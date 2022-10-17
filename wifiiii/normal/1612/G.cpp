#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int M = 2e6 + 5;
const int mod = 1e9 + 7;
ll C(ll l, ll r) {
    r %= mod, l %= mod;
    return (r + l) * (r - l + 1) / 2 % mod;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), cnt(N * 4);
    vector<ll> f(n + 1);
    f[0] = 1; for(int i = 1; i <= n; ++i) f[i] = f[i-1] * i % mod;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[1 - a[i] + M] += 1;
        cnt[a[i] + 1 + M] -= 1;
    }
    ll ans1 = 0, ans2 = 1, cur = 1;
    for(int i = 2; i < 4 * N; ++i) {
        cnt[i] += cnt[i - 2];
        if(cnt[i]) {
            ans2 = ans2 * f[cnt[i]] % mod;
            ans1 += C(cur, cur + cnt[i] - 1) * (i - M) % mod;
            cur += cnt[i];
        }
    }
    ans1 %= mod;
    if(ans1 < 0) ans1 += mod;
    cout << ans1 << " " << ans2 << '\n';
}