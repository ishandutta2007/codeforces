#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    vector<ll> s(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        s[i]++;
        if(i) s[i-1]--;
    }
    int cur = 0;
    ll ans = a.back() + 1;
    for(int i = n - 1; i >= 0; --i) {
        (cur += s[i]) %= mod;
        ll tmp = (cur + c[i] - 1) % mod;
        int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        // [pos, i - 1] += tmp
        if(pos <= i-1) {
            (s[i-1] += tmp) %= mod;
            if(pos) (s[pos-1] -= tmp) %= mod;
        }
        ans += (a[i] - b[i]) * tmp % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}