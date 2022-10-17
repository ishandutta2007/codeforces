#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;
int main() {
    ll x = 2050;
    while(1) {
        a.push_back(x);
        x = x * 10;
        if(x >= 1e18) break;
    }
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int ans = 0;
        for(int i = a.size() - 1; i >= 0; --i) {
            ans += n / a[i];
            n %= a[i];
        }
        if(n == 0) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}