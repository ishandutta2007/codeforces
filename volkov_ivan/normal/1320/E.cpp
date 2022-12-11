#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


const int N = 2e5 + 7, K = 20;
vector <int> g[N];
vector <pair <int, int>> g2[N];
pair <int, int> vir[N], dist[N];
int tin[N], tout[N], depth[N], color[N];
int go[K][N];
int T = 0;

void dfs(int v, int p = -1, int d = 0) {
    tin[v] = T++;
    go[0][v] = p;
    depth[v] = d;
    for (int i = 1; i < K; i++) {
        if (go[i - 1][v] == -1) go[i][v] = -1;
        else go[i][v] = go[i - 1][go[i - 1][v]];
    }
    for (int u : g[v]) {
        if (u != p) dfs(u, v, d + 1); 
    }
    tout[v] = T - 1;
}

bool is_ancestor(int v, int u) {
    if (v == -1) return 1;
    return (tin[v] <= tin[u] && tout[u] <= tout[v]);
}

int get_lca(int v, int u) {
    if (is_ancestor(v, u)) return v;
    for (int i = K - 1; i >= 0; i--) {
        if (!is_ancestor(go[i][v], u)) v = go[i][v];
    }
    return go[0][v];
}

bool cmp(int a, int b) {
    return (tin[a] < tin[b]);
}

void solve() {
    int k, m;
    cin >> k >> m;
    vector <int> start(k), interest(m), all;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        start[i] = a;
        all.push_back(a);
        vir[i] = {b, i};
    }
    for (int i = 0; i < m; i++) {
        cin >> interest[i];
        all.push_back(interest[i]);
    }
    set <int> nw;
    sort(all.begin(), all.end(), cmp);
    for (int i = 1; i < k + m; i++) nw.insert(get_lca(all[i - 1], all[i]));
    for (int elem : all) nw.insert(elem);
    all.clear();
    for (int elem : nw) all.push_back(elem);
    for (int elem : all) g2[elem].clear();
    sort(all.begin(), all.end(), cmp);
    vector <int> st;
    //cout << all.size() << endl;
    for (int v : all) {
        while (!st.empty() && !is_ancestor(st.back(), v)) st.pop_back();
        if (!st.empty()) {
            int d = depth[v] - depth[st.back()];
            g2[st.back()].push_back({v, d});
            g2[v].push_back({st.back(), d});
            //cout << "!! " << v << ' ' << st.back() << endl;
        }
        st.push_back(v);
    }
    set <pair <pair <int, int>, pair <int, int>>> q;
    for (int elem : all) {
        dist[elem] = {N, N};
        color[elem] = N;
    }
    for (int i = 0; i < k; i++) {
        dist[start[i]] = {0, 0};
        color[start[i]] = i;
        q.insert({{0, i}, {0, start[i]}});
    }
    while (!q.empty()) {
        auto [aa, bb] = *q.begin();
        q.erase(q.begin());
        auto [len, cl] = aa;
        auto [rest, v] = bb;
        //cout << v << endl;
        for (pair <int, int> e : g2[v]) {
            auto [u, w] = e;
            //cout << v << ' ' << u << ' ' << w << endl;
            pair <pair <int, int>, pair <int, int>> lst = {{dist[u].first, color[u]}, {dist[u].second, u}};
            pair <pair <int, int>, pair <int, int>> nw = {{(rest + w + vir[cl].first - 1) / vir[cl].first, cl}, {rest + w, u}};
            if (nw < lst) {
                //cout << 104 << endl;
                if (q.find(lst) != q.end()) q.erase(q.find(lst));
                //cout << 106 << endl;
                q.insert(nw);
                dist[u].first = (rest + w + vir[cl].first - 1) / vir[cl].first;
                dist[u].second = rest + w;
                color[u] = cl;
            }
        }
    }
    for (int elem : interest) {
        cout << color[elem] + 1 << ' ';
    }
    cout << "\n";
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) solve();
    return 0;
}