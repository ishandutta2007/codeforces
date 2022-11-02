#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)4e3 + 3;
const ll mod = (ll)1e9 + 7;

ll cnt[4];
ll dp[N][N];

void solve(){
    int h, w;
    cin >> h >> w;
    ++h; ++w;
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int c1 = 0; c1 < 4; c1++){
                for(int c2 = 0; c2 < 4; c2++){
                    int x1 = c1>>1, x2 = c2>>1;
                    int y1 = c1&1, y2 = c2&1;
                    int l = (x1&y2)^(i&1&y2)^(j&1&x1);
                    int r = (x2&y1)^(i&1&y1)^(j&1&x2);
                    int ok = (l&1) == (r&1);
                    ans += ok * cnt[c1] * cnt[c2];
                    ans -= ok * int(c1 == c2) * cnt[c1];
                }
            }
            ans %= mod;
            cnt[((i%2)<<1)|(j%2)]++;
        }
    }
    for(int i = 0; i <= h; i++){
        ll val = i * (i - 1) * 1ll * (i - 2)/6;
        dp[i][1] = val;
    }
    for(int i = 0; i <= w; i++){
        ll val = i * (i - 1) * 1ll * (i - 2)/6;
        dp[1][i] = val;
    }
    for(int i = 2; i <= h; i++){
        for(int j = 2; j <= w; j++){
            dp[i][j] = 2*(__gcd(i - 1, j - 1) - 1) + 2*dp[i - 1][j] + 2*dp[i][j - 1] - 4*dp[i - 1][j - 1] - dp[i - 2][j] - dp[i][j - 2] + 2*dp[i - 2][j - 1] + 2*dp[i - 1][j - 2] - dp[i - 2][j - 2];
            dp[i][j] %= mod;
            if(dp[i][j] < 0)dp[i][j] += mod;
        }
    }
    ans *= 3;
    ans -= dp[h][w] * 6;
    ans = (ans%mod + mod)%mod;
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}