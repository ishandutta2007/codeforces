#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
int prime[maxn], np[maxn], mp[maxn], tot = 0;
void init(int n) {
    np[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(!np[i]) prime[++tot] = i, mp[i] = i;
        for(int j = 1; j <= tot; ++j) {
            if(i * prime[j] > n) break;
            np[i * prime[j]] = 1;
            mp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}
bool vis[maxn * 23];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    init(n);
    vector<int> dp(n + 1, -1);
    for(int i = 1; i <= n; ++i) {
        int x = i, g = 0;
        vector<pair<int,int>> f;
        while(x > 1) {
            int p = mp[x], cc = 0;
            while(x % p == 0) {
                x /= p;
                ++cc;
            }
            f.push_back({p, cc});
            g = gcd(g, cc);
        }
        for(auto [p, cc] : f) {
            cc /= g;
            while(cc--) x *= p;
        }
        dp[x] = max(dp[x], g);
    }
    ll ans = 1;
    vector<int> sz(22);
    for(int i = 1; i <= 21; ++i) {
        int cnt = 0;
        for(int j = 1; j <= m; ++j) {
            cnt += !vis[i * j];
            vis[i * j] = 1;
        }
        sz[i] = sz[i - 1] + cnt;
    }
    for(int i = 1; i <= n; ++i) {
        if(dp[i] == -1) continue;
        ans += sz[dp[i]];
    }
    cout << ans << '\n';
}