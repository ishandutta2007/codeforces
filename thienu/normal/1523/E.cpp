#include <bits/stdc++.h>

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

ll MOD = 1e9 + 7;

int MAXN = 1e5 + 5;
vll factorial(MAXN);
vll factorial_inv(MAXN);

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inverse(ll x){
    return binexp(x, MOD - 2);
}

void precompute(){
    factorial[0] = 1;
    for(int i = 1; i < MAXN; i++){
        factorial[i] = mul(factorial[i-1], i);
    }
    for(int i = 0; i < MAXN; i++){
        factorial_inv[i] = inverse(factorial[i]);
    }
}

ll ncr(ll n, ll r){
    if(r < 0 || r > n) return 0;
    return mul(mul(factorial_inv[r], factorial_inv[n-r]), factorial[n]);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll total = ncr(n, i);
        ll valid = ncr(n - (i-1) * (k-1), i);
        debug(i, valid, total);
        ans = add(ans, mul(valid, inverse(total)));
    }
    ans = add(ans, 1);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    precompute();
    while(tc--){
        solve();
    }
    return 0;
}