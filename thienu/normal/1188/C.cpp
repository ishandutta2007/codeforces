#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll MOD = 998244353;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

const int A = 1e5 + 5;
// const int A = 10;
const int N = 1005;

ll dp[N][N];
ll pref[N][N];

void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    // debug(v);
    ll ans = 0;
    vi lookup(A);
    int x = 0;
    for(int i = 0; i < A; i++){
        while(x < n && v[x] <= i) x++;
        lookup[i] = x;
    }
    // debug(lookup);
    for(int b = 1; b <= A / (k-1); b++){
        if(b % 1000 == 0){
            debug(b);
        }
        for(int i = 0; i <= n; i++){
            // memset(dp[i], 0, sizeof(ll) * (k+1));
            for(int j = 0; j <= k; j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i <= n+1; i++){
            // memset(pref[i], 0, sizeof(ll) * (k+1));
            for(int j = 0; j <= k; j++){
                pref[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            // debug(i);
            dp[i][1] = 1;
            // auto it = upper_bound(v.begin(), v.end(), v[i-1]-b);
            int midx = 0;
            if(v[i-1]-b >= 0) midx = lookup[v[i-1]-b];
            // debug(i, midx);
            for(int j = 2; j <= k; j++){
                dp[i][j] = pref[midx+1][j-1];
            }
            for(int j = 1; j <= k; j++){
                pref[i+1][j] = add(pref[i][j], dp[i][j]);
            }
        }
        for(int i = 1; i <= n; i++){
            ans += dp[i][k];
        }
        ans %= MOD;
        // debug(dp);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}