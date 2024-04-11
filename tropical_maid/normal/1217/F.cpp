#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/06, 00:30:55
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int B = 1000;
int n, m;
int T[200001];
int X[200001];
int Y[200001];
vector<pii> es;

int par[200001];
int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    par[y] = x;
    return 1;
}

int last;
vector<int> edge[200001];
bool vis[200001];

void dfs(int x, bool ch) {
    vis[x] = ch;
    for (int i : edge[x]) {
        if (vis[i] == ch) continue;
        dfs(i, ch);
    }
}

void solve(int st, int ed) {
    for (int i = 1; i <= n; ++i) {
        par[i] = 0;
    }
    vector<pii> ch;
    for (int i = st; i <= ed; ++i) {
        if (T[i] == 1) {
            int x = X[i], y = Y[i];
            if (x > y) swap(x, y);
            ch.emplace_back(x, y);
            x = x % n + 1;
            y = y % n + 1;
            if (x > y) swap(x, y);
            ch.emplace_back(x, y);
        }
    }
    sort(ch.begin(), ch.end());
    vector<int> in(ch.size());
    for (pii i : es) {
        auto it = lower_bound(ch.begin(), ch.end(), i);
        if (it != ch.end() && *it == i) continue;
        merge(i.fs, i.se);
    }
    vector<int> er;
    for (pii i : es) {
        if (i.fs > i.se) swap(i.fs, i.se);
        auto it = lower_bound(ch.begin(), ch.end(), i);
        if (it == ch.end() || *it != i) continue;
        in[it - ch.begin()] = 1;
        int x = find(i.fs);
        int y = find(i.se);
        edge[x].push_back(y);
        edge[y].push_back(x);
        er.push_back(x);
        er.push_back(y);
    }
    for (int i = st; i <= ed; ++i) {
        if (T[i] == 1) {
            int x = X[i], y = Y[i];
            if (last) {
                x = x % n + 1;
                y = y % n + 1;
            }
            if (x > y) swap(x, y);
            int j = lower_bound(ch.begin(), ch.end(), pii(x, y)) - ch.begin();
            x = find(x);
            y = find(y);
            if (in[j]) {
                edge[x].erase(find(edge[x].begin(), edge[x].end(), y));
                edge[y].erase(find(edge[y].begin(), edge[y].end(), x));
            }
            else {
                edge[x].push_back(y);
                edge[y].push_back(x);
                er.push_back(x);
                er.push_back(y);
            }
            in[j] ^= 1;
        }
        else {
            int x = X[i], y = Y[i];
            if (last) {
                x = x % n + 1;
                y = y % n + 1;
            }
            x = find(x);
            y = find(y);
            dfs(x, 1);
            last = vis[y];
            dfs(x, 0);
            printf("%d", last);
        }
    }
    for (int i : er) edge[i].clear();
    vector<pii> nxt;
    for (pii i : es) {
        if (i.fs > i.se) swap(i.fs, i.se);
        auto it = lower_bound(ch.begin(), ch.end(), i);
        if (it != ch.end() && *it == i) {
            if (in[it - ch.begin()] == 0) continue;
            in[it - ch.begin()] = 0;
        }
        nxt.push_back(i);
    }
    for (int i = 0; i < ch.size(); ++i) {
        if (in[i]) nxt.push_back(ch[i]);
    }
    swap(es, nxt);
    sort(es.begin(), es.end());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> T[i] >> X[i] >> Y[i];
    }
    for (int it = 0; it < B; ++it) {
        int st = it * B + 1;
        int ed = min((it + 1) * B, m);
        if (st > ed) break;
        solve(st, ed);
    }
    return 0;
}