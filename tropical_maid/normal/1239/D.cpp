#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/10/20, 19:20:42
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m;
vector<int> edge[1000001];
vector<int> redge[1000001];
bool vis[1000001];

void add_edge(int x, int y) {
    edge[x].push_back(y);
    redge[y].push_back(x);
}

int L;
void dfs1(int x) {
    vis[x] = 1;
    for (int i : edge[x]) {
        if (vis[i]) continue;
        dfs1(i);
    }
    L = x;
}

void dfs2(int x) {
    vis[x] = 0;
    for (int i : redge[x]) {
        if (vis[i]) dfs2(i);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        redge[i].clear();
        vis[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
    }
    L = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        dfs1(i);
    }
    dfs2(L);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            printf("Yes\n");
            for (int j = 1; j <= n; ++j) vis[i] = 0;
            dfs1(i);
            vector<int> J, P;
            for (int j = 1; j <= n; ++j) {
                if (vis[j]) J.push_back(j);
                else P.push_back(j);
            }
            printf("%u %u\n", J.size(), P.size());
            for (int j : J) printf("%d ", j);
            printf("\n");
            for (int j : P) printf("%d ", j);
            printf("\n");
            return;
        }
    }
    printf("No\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}