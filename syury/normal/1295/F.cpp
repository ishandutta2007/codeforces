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
const int B = 206;
const ll mod = 998244353;

ll dp[N][B];
pii block[B];
ll precalced[N][B];
int sz = 0, n;
int L[N], R[N];

ll inv(ll x){
    ll p = mod - 2;
    ll res = 1;
    while(p){
        if(p&1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

ll eql(int len, int C){
    ll P = 1;
    ll cu = (len + C - 1)%mod;
    ll fac = 1;
    for(int i = 1; i <= len; i++){
        fac = fac * i % mod;
        P = P * cu % mod;
        --cu;
    }
    P = P * inv(fac) % mod;
    return (P + mod)%mod;
}

void solve(){
    cin >> n;
    vector<int> pts;
    for(int i = 0; i < n; i++){
        cin >> L[i] >> R[i];
        pts.push_back(L[i]);
        pts.push_back(R[i]);
    }
    sort(all(pts));
    int old = -1488;
    for(auto x: pts){
        if(old != x){
            if(old != -1488 && old + 1 < x){
                block[sz++] = {old + 1, x - 1};
            }
            block[sz++] = {x, x};
            old = x;
        }
    }
    for(int b = 0; b < sz; b++){
        for(int cnt = 1; cnt <= n; cnt++){
            precalced[cnt][b] = eql(cnt, block[b].Y - block[b].X + 1);
        }
    }
    for(int i = 0; i < n; i++){
        for(int b = 0; b < sz; b++){
            if(block[b].X > R[i] || block[b].Y < L[i])
                continue;
            bool fug = 0;
            for(int old = i - 1; old >= 0; old--){
                for(int pb = b + 1; pb < sz; pb++){
                    dp[i][b] += precalced[i - old][b] * dp[old][pb] % mod;
                }
                if(block[b].X > R[old] || block[b].Y < L[old]){
                    fug = 1;
                    break;
                }
            }
            if(!fug)
                dp[i][b] += precalced[i + 1][b];
            dp[i][b] %= mod;
        }
    }
    ll ans = 0;
    for(int b = 0; b < sz; b++)
        ans += dp[n - 1][b];
    ans %= mod;
    ll Q = 1;
    for(int i = 0; i < n; i++)
        Q = Q * (R[i] - L[i] + 1) % mod;
    ans = ans * inv(Q) % mod;
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    T = 1;
    while(T--)
        solve();
    //cerr << fixed << clock()/(double)CLOCKS_PER_SEC << endl;
    return 0;
}