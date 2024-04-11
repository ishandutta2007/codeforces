#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 10;
int d[maxn], n, m;
vector<int> nd[maxn];
vector<int> sum[maxn];

void dfs(int now) {
    if (now * 2 <= n) dfs(now * 2);
    if (now * 2 + 1 <= n) dfs(now * 2 + 1);
    nd[now].push_back(0);
    size_t lptr = 0, rptr = 0;
    int l = now * 2, r = now * 2 + 1;
    while (lptr < nd[l].size() && rptr < nd[r].size()) {
        if (nd[l][lptr] + d[l] < nd[r][rptr] + d[r]) nd[now].push_back(nd[l][lptr++] + d[l]);
        else nd[now].push_back(nd[r][rptr++] + d[r]);
    }
    while (lptr < nd[l].size()) nd[now].push_back(nd[l][lptr++] + d[l]);
    while (rptr < nd[r].size()) nd[now].push_back(nd[r][rptr++] + d[r]);
    sum[now].resize(nd[now].size());
    sum[now][0] = nd[now][0];
    for (size_t i = 1; i < nd[now].size(); ++i) sum[now][i] = sum[now][i - 1] + nd[now][i];
}

long long query(int a, int h) {
    if (a > n || a <= 0 || h < 0) return 0;
    int i = upper_bound(nd[a].begin(), nd[a].end(), h) - nd[a].begin() - 1;
    int c = i + 1; 
    long long s = (i >= 0 ? sum[a][i] : 0);
    return h * c - s;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) cin >> d[i];
    dfs(1);
    while (m--) {
        int a, h; cin >> a >> h;
        long long ans = query(a, h);
        int w = 0;
        while (a > 1) {
            w += d[a];
            if (w > h) break;
            ans += h - w + query(a ^ 1, h - w - d[a ^ 1]);
            a >>= 1;
        }
        cout << ans << endl;
    }
    return 0;
}