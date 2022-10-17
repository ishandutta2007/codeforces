#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll c3(ll x) {
    return x * (x - 1) * (x - 2) / 6;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<int> cx(n), cy(n);
        set<pair<int,int>> s;
        for(int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            --a[i], --b[i];
            cx[a[i]]++;
            cy[b[i]]++;
        }
        ll ans = c3(n);
        for(int i = 0; i < n; ++i) {
            ans -= 1ll * (cx[a[i]] - 1) * (cy[b[i]] - 1);
        }
        cout << ans << '\n';
    }
}