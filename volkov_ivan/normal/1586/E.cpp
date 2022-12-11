#include <bits/stdc++.h>
//#define int long long

using namespace std;
const int N = 3e5 + 7;

set <int> g[N];
vector <int> euler;
vector <int> res;
bool vis[N];
pair <int, int> dom[N];
vector <pair <int, int>> edges;
vector <int> edge_nums;
vector <int> ans[N];
vector <int> gg[N];
 
void dfs(int v, int depth = 0, int prv = 0) {
    while (!g[v].empty()) {
        int pos = (*g[v].begin());
        g[v].erase(g[v].begin());
        pair <int, int> edge = edges[pos];
        g[edge.first].erase(pos ^ 1);
        dfs(edge.first, depth + 1, edge.second);
    }
    euler.push_back(prv);
}

void dfs0(int v) {
    if (vis[v])
        return;
    vis[v] = 1;
    for (int u : g[v]) {
        dfs0(edges[u].first);
    }
}

vector <int> my_path;
vector <bool> viss;

bool dfs2(int v, int need) {
    if (viss[v])
        return 0;
    viss[v] = 1;
    my_path.push_back(v);
    if (v == need)
        return 1;
    for (int u : gg[v]) {
        if (dfs2(u, need))
            return 1;
    }
    my_path.pop_back();
    return 0;
}

vector <int> find_path(int n, int v, int u) {
    viss.assign(n + 1, 0);
    my_path.clear();
    dfs2(v, u);
    return my_path;
}

void normalize(int n, vector <int> &p1, vector <int> &p2) {
    if (p1.empty()) {
        p1 = p2;
        return;
    }
    vector <int> pos(n + 1, -1);
    for (int i = 0; i < (int) p1.size(); i++)
        pos[p1[i]] = i;
    int lst = -1;
    for (int i = 0; i < (int) p2.size(); i++) {
        if (pos[p2[i]] != -1)
            lst = i;
    }
    vector <int> np2;
    for (int i = (int) p1.size() - 1; i >= 0; i--) {
        np2.push_back(p1[i]);
        if (p1[i] == p2[lst])
            break;
        p1.pop_back();
    }
    for (int i = lst + 1; i < (int) p2.size(); i++) {
        np2.push_back(p2[i]);
        p1.push_back(p2[i]);
    }
    p2 = np2;
}

void find_euler() {
    int n, m;
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        gg[a].push_back(b);
        gg[b].push_back(a);
    }
    int q;
    cin >> q;
    vector <pair <int, int>> ee(q + 1);
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(edges.size());
        edges.push_back({b, i});
        g[b].insert(edges.size());
        edges.push_back({a, -i});
        ee[i] = {a, b};
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2 == 1)
            cnt++;
    }
    if (cnt != 0) {
        cout << "NO" << endl;
        cout << cnt / 2 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!g[i].empty() && !vis[i]) {
            dfs0(i);
            euler.clear();
            dfs(i);
            reverse(euler.begin(), euler.end());
            vector <int> cur_path;
            int sz = euler.size();
            for (int i = 1; i < sz - 1; i++) {
                int v = ee[abs(euler[i])].first;
                int u = ee[abs(euler[i])].second;
                if (euler[i] < 0)
                    swap(v, u);
                auto path = find_path(n, v, u);
                //cout << euler[i] << ' ' << v << ' ' << u << ' ' << path.size() << endl;
                normalize(n, cur_path, path);
                ans[abs(euler[i])] = path;
            }
            //cout << cur_path.size() << endl;
            ans[abs(euler[sz - 1])] = cur_path;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= q; i++) {
        if (ans[i][0] != ee[i].first) {
            reverse(ans[i].begin(), ans[i].end());
        }
        cout << ans[i].size() << "\n";
        for (int elem : ans[i]) {
            cout << elem << ' ';
        }
        cout << "\n";
    }
}


signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    find_euler();
}