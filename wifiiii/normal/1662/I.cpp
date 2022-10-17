#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(m);
    for(int i = 0; i < m; ++i) cin >> b[i];
    sort(b.begin(), b.end());
    vector<array<int, 3>> c;
    for(int i = 0, j = 0; i < n; ++i) {
        while(j + 1 < m && b[j + 1] <= i * 100) ++j;
        int d = abs(i * 100 - b[j]);
        if(j + 1 < m) d = min(d, abs(i * 100 - b[j + 1]));
        int l = i * 100 - d, r = i * 100 + (d - 1);
        if(l <= r) {
            c.push_back({l, 1, a[i]});
            c.push_back({r + 1, -1, a[i]});
        }
    }
    sort(c.begin(), c.end());
    ll ans = 0, cur = 0;
    for(auto [p, t, w] : c) {
        cur += t * w;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}