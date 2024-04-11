#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    auto solve = [&](vector<int> a) -> ll {
        sort(a.begin(), a.end());
        ll ans = 1;
        for(int i = 1; i <= n; ++i) {
            if(a[i - 1] <= i) return 0;
            ans = ans * (a[i - 1] - i) % mod;
        }
        return ans;
    };
    ll fac = 1;
    for(int i = 2; i <= n; ++i) fac = fac * i % mod;
    ll ans = 0;
    for(int i = 0; i < m; ++i) {
        vector<int> b;
        for(int j = 0; j < n; ++j) {
            b.push_back(a[j][i]);
        }
        ans += (fac - solve(b)) % mod;
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    ans = ans * fpow(fac, mod - 2) % mod;
    cout << ans << '\n';
}