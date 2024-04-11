#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/11/07, 00:11:57
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

vector<int> edge[100001];
int cnt[100001];
int par[100001];
int sz[100001];
int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> cp;
    for (int i = 1; i <= n; ++i) {
        cp.push_back(i);
        sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : cp) cnt[j] = 0;
        for (int j : edge[i]) ++cnt[find(j)];
        vector<int> nxt;
        for (int j : cp) {
            if (cnt[j] == sz[j]) {
                nxt.push_back(j);
            }
            else if (find(i) != find(j)) {
                sz[find(i)] += sz[find(j)];
                par[find(j)] = find(i);
            }
        }
        nxt.push_back(find(i));
        swap(cp, nxt);
    }
    printf("%d\n", (int)cp.size() - 1);
    return 0;
}