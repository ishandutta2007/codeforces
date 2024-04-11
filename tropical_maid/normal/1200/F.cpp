#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/11, 22:26:58
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int L = 8 * 9 * 5 * 7;
int n;
vector<int> edge[1001];
int k[1001];
int nxt[1001 * L];
bool vis[1001 * L];
bool fin[1001 * L];
vector<int> cnt[1001 * L];
int cyc[1001 * L];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        k[i] %= L;
        k[i] += L;
        k[i] %= L;
    }
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            edge[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < L; ++j) {
            int v = edge[i][j % edge[i].size()];
            nxt[i * L + j] = v * L + (j + k[v]) % L;
        }
    }
    for (int i = L; i < (n + 1) * L; ++i) {
        int x = i;
        while (!vis[x]) {
            vis[x] = 1;
            x = nxt[x];
        }
        int c = cyc[x];
        if (!fin[x]) {
            c = x;
            int v = x;
            while (!fin[v]) {
                cnt[c].push_back(v / L);
                cyc[v] = c;
                fin[v] = 1;
                v = nxt[v];
            }
        }
        x = i;
        while (!fin[x]) {
            cyc[x] = c;
            fin[x] = 1;
            x = nxt[x];
        }
    }
    for (int i = L; i < (n + 1) * L; ++i) {
        if (cyc[i] != i) continue;
        sort(cnt[i].begin(), cnt[i].end());
        cnt[i].erase(unique(cnt[i].begin(), cnt[i].end()), cnt[i].end());
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        y %= L;
        y += L + k[x];
        y %= L;
        x = x * L + y;
        x = cyc[x];
        printf("%d\n", (int)cnt[x].size());
    }
    return 0;
}