//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb emplace_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int K = 32;

ll dp[K][K];
ll numwith[K];

ll solve(int d, int m){
    memset(dp, 0, sizeof(dp));
    ll total = 0;
    F(i, 0, K){
        ll L = 1ll<<i;
        ll R = (1ll<<(i + 1))-1;
        R = min(R, d*1ll);
        numwith[i] = max(0ll, R - L + 1);
    }
    F(hi, 0, K)
        dp[1][hi] = numwith[hi];
    F(len, 2, K){
        F(hi, 0, K){
            ll coeff = numwith[hi];
            F(prv, 0, hi){
                dp[len][hi] += dp[len - 1][prv];
            }
            dp[len][hi] %= m;
            dp[len][hi] = dp[len][hi] * coeff % m;
        }
    }
    F(len, 1, K)F(hi, 0, K)total += dp[len][hi];
    ret total%m;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int d, m;
        cin >> d >> m;
        cout << solve(d, m) << '\n';
    }
    return 0;
}