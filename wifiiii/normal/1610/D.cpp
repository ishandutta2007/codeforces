#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
ll solve(vector<int> a) {
    if(a.empty()) return 0;
    int n = a.size();
    ll ans = 0, tot = fpow(2, n) - 1;
    vector<int> b;
    int cnt = 0;
    for(int i : a) {
        if(i % 4 == 2) cnt += 1;
        if(i % 4 == 0) b.push_back(i / 2);
    }
    if(cnt) ans += fpow(2, b.size() + cnt - 1);
    ans = (ans + solve(b)) % mod;
    return ans;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    ll ans = fpow(2, n) - solve(a) - 1;
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << '\n';
}