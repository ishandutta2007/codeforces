#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int v[maxn], l[maxn], r[maxn];
bool rt[maxn];
set<int> ans;

void dfs(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin>> n;
    memset(rt, true, sizeof(rt));
    for (int i = 1; i <= n; ++i) {
        cin >>  v[i] >> l[i] >> r[i];
        if (l[i] != -1) rt[l[i]] = false;
        if (r[i] != -1) rt[r[i]] = false;
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) if (rt[i]) root = i;
    dfs(root, inf, -1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (ans.find(v[i]) == ans.end()) ++cnt;
    cout << cnt << endl;
    return 0;
}

void dfs(int x, int mx, int mn) {
    if (v[x] <= mx && v[x] >= mn) ans.insert(v[x]);
    if (l[x] != -1) dfs(l[x], min(mx, v[x]), mn);
    if (r[x] != -1) dfs(r[x], mx, max(mn, v[x]));
}