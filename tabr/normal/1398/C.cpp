#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = s[i] - '0';
            a[i + 1]--;
            a[i + 1] += a[i];
        }
        map<ll, ll> mp;
        for (int i = 0; i <= n; i++){
            mp[a[i]]++;
        }
        ll ans = 0;
        for(auto e:mp){
            ans += e.second * (e.second - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}