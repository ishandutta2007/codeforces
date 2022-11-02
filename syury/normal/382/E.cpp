//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 51;
const int mod = (int)1e9 + 7;

ll dp0[N][N];
ll dp1[N][N];
ll C[N][N];

inline ll modpow(ll x, ll p){
    ll res = 1;
    while(p){
        if(p&1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

void solve(){
    ll i2 = modpow(2, mod - 2);
    C[0][0] = 1;
    for(int i = 1; i < N; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%mod;
        }
    }
    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));
    int n, K;
    cin >> n >> K;
    dp1[0][0] = 1;
    dp0[1][0] = 1;
    for(int sz = 2; sz <= n; sz++){
        for(int k = 0; k <= sz/2; k++){
            for(int szl = 0; szl < sz; szl++){
                int szr = sz - 1 - szl;
                if(szl > szr)
                    break;
                ll enumerate = sz == n ? 1 : sz;
                enumerate = enumerate * C[sz - 1][szl] % mod;
                for(int kl = 0; kl <= k; kl++){
                    if(szl == szr && kl > k - kl)
                        break;
                    if(szl == szr && kl == k - kl)enumerate = enumerate * i2 % mod;
                    //cerr << szl << ' ' << szr << ' ' << kl << ' ' << k - kl << endl;
                    dp0[sz][k] += dp1[szl][kl] * dp1[szr][k - kl] % mod * enumerate;
                    dp0[sz][k] %= mod;
                    dp1[sz][k + 1] += (dp1[szl][kl] * dp0[szr][k - kl] + dp0[szl][kl] * dp1[szr][k - kl] + dp0[szl][kl] * dp0[szr][k - kl]) % mod * enumerate;
                    dp1[sz][k + 1] %= mod;
                    if(szl == szr && kl == k - kl)enumerate = enumerate * 2 % mod;
                }
            }
        }
    }
    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i/2; j++)
            cerr << "(" << dp0[i][j] << ", " << dp1[i][j] << "), ";
        cerr << endl;
    }*/
    cout << (dp0[n][K] + dp1[n][K])%mod << endl;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}