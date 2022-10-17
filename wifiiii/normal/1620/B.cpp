#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> a(4);
        for(int i = 0; i < 4; ++i) {
            int k;
            cin >> k;
            vector<int> b(k);
            for(auto &j : b) cin >> j;
            a[i] = {b[0], b.back()};
        }
        ll ans = 0;
        ans = max(ans, 1ll * (a[0].second - a[0].first) * m);
        ans = max(ans, 1ll * (a[1].second - a[1].first) * m);
        ans = max(ans, 1ll * (a[2].second - a[2].first) * n);
        ans = max(ans, 1ll * (a[3].second - a[3].first) * n);
        cout << ans << '\n';
    }
}