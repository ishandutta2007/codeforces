#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
vector<pair<int, int>> G[maxn];
int p[maxn], pe[maxn], cy[maxn], st, ed, n, m, fe;

bool dfs1(int now, int fa, int eid) {
    p[now] = fa; pe[now] = eid;
    cy[now] = 1;
    bool ret = false;
    for (auto u : G[now]) {
        int to = u.first, e = u.second;
        if (cy[to] == -1) ret |= dfs1(to, now, e);
        else if (cy[to] == 1) ret = true, st = now, ed = to, fe = e;
    }
    cy[now] = 0;
    return ret;
}

bool dfs2(int now, int forb) {
    cy[now] = 1;
    bool ret = true;
    for (auto u : G[now]) if (u.second != forb) {
        if (cy[u.first] == -1) ret &= dfs2(u.first, forb);
        else if (cy[u.first] == 1) ret = false;
    }
    cy[now] = 0;
    return ret;
}

bool solve(int forb) {
    fill_n(cy, n, -1);
    bool ret = true;
    for (int i = 0; i < n; ++i) if (cy[i] == -1) ret &= dfs2(i, forb);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        G[a].emplace_back(b, i);
    } 
    fill_n(cy, n, -1);
    for (int i = 0; i < n; ++i) if (cy[i] == -1) {
        if (dfs1(i, -1, -1)) {
            // cout << "i = " << i << endl;
            // cout << "st = " << st << " ed = " << ed << endl;
            vector<int> cand;
            while (st != ed) {
                cand.push_back(pe[st]);
                // cout << "edge = " << pe[st] << endl;
                st = p[st];
            }
            cand.push_back(fe);
            for (int j : cand) if (solve(j)) return cout << "YES" << endl, 0;
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}