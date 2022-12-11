#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 5e5 + 7;
vector <int> g[N];
int c[N];
int color[N];
int comp[N];
int pa[N];
bool is_good_comp[N];
int color2[N];
vector <int> gg[N];
vector <int> this_color[N];
vector <pair <int, int>> new_edges[N];

vector <int> lft, rght;

bool is_bip(int v, int cc) {
    color[v] = cc;
    if (cc == 0)
        lft.push_back(v);
    else
        rght.push_back(v);
    for (int u : g[v]) {
        if (c[u] != c[v])
            continue;
        if (color[u] != -1 && color[u] == color[v])
            return 0;
        if (color[u] == -1)
            if (!is_bip(u, 1 - cc))
                return 0;
    }
    return 1;
}

bool is_bip2(int v, int cc) {
    //cout << v << ' ' << cc << endl;
    color2[v] = cc;
    //cout << v <<  ' ' << cc << endl;
    for (int u : gg[v]) {
        if (color2[u] != -1 && color2[v] == color2[u])
            return 0;
        if (color2[u] == -1) {
            if (!is_bip2(u, 1 - cc))
                return 0;
        }
    }
    return 1;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; 
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        this_color[c[i]].push_back(i);
        color[i] = color2[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int lst = 1;
    int cnt_bad = 0;
    long long ans = (1ll * k) * (k - 1) / 2;
    for (int colr = 1; colr <= k; colr++) {
        is_good_comp[colr] = 1;
        for (int elem : this_color[colr]) {
            if (color[elem] == -1) {
                lft.clear();
                rght.clear();
                if (!is_bip(elem, 0))
                    is_good_comp[colr] = 0;
                for (int elem2 : lft) {
                    comp[elem2] = lst;
                }
                pa[lst] = -1;
                lst++;
                if (!rght.empty()) {
                    for (int elem2 : rght) {
                        comp[elem2] = lst;
                    }
                    pa[lst] = lst - 1;
                    pa[lst - 1] = lst;
                    lst++;
                }
            }
        }
        if (!is_good_comp[colr])
            cnt_bad++;
    }
    //cout << lst << endl;
    for (int colr = 1; colr <= k; colr++) {
        if (!is_good_comp[colr]) {
            ans -= (k - colr);
            cnt_bad--;
            continue;
        }
        ans -= cnt_bad;
        //cout << colr << endl;
        vector <int> interest;
        for (int v : this_color[colr]) {
            for (int u : g[v]) {
                if (c[u] > c[v]) {
                    if (new_edges[c[u]].empty())
                        interest.push_back(c[u]);
                    new_edges[c[u]].push_back({comp[v], comp[u]});
                }
            }
        }
        for (int colr2 : interest) {
            if (!is_good_comp[colr2])
                continue;
            vector <int> nodes;
            for (auto e : new_edges[colr2]) {
                nodes.push_back(e.first);    
                nodes.push_back(e.second);
                if (pa[e.first] != -1) nodes.push_back(pa[e.first]);
                if (pa[e.second] != -1) nodes.push_back(pa[e.second]);
                gg[e.first].push_back(e.second);
                gg[e.second].push_back(e.first);
                if (pa[e.first] != -1) {
                    gg[pa[e.first]].push_back(e.first);
                    gg[e.first].push_back(pa[e.first]);
                }
                if (pa[e.second] != -1) {
                    gg[pa[e.second]].push_back(e.second);
                    gg[e.second].push_back(pa[e.second]);
                }
            }
            bool ok = 1;
            for (int elem : nodes) {
                //cout << colr << ' ' << colr2 << ' ' << elem  << color2[elem] << endl;
                if (color2[elem] == -1 && !is_bip2(elem, 0)) {
                    ok = 0;
                    break;
                }
            }
            //cout << colr << ' ' << colr2 << ' ' << ok << endl;
            if (!ok)
                ans--;
            for (int elem : nodes) {
                color2[elem] = -1;
                gg[elem].clear();
            }
        }
        for (int v : this_color[colr]) {
            for (int u : g[v]) {
                if (c[u] > c[v]) {
                    new_edges[c[u]].clear();
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}