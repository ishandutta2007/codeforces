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

ll MOD = 998244353;

ll MAXN = 400000;

vll factorial(MAXN);

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

ll inverse(ll n){
    return binexp(n, MOD - 2);
}

ll ncr(int n, int r){
    if(r > n) return 0;
    if(n < 0) return 0;
    if(r < 0) return 0;
    debug(n, r);
    return (factorial[n] * inverse(factorial[n-r]) % MOD) * inverse(factorial[r]) % MOD;
}

void solve(){
    int n;
    cin >> n;
    vi v(2 * n);

    for(int i = 0; i < 2 * n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = ((ans - v[i]) % MOD + MOD) % MOD;
    for(int i = n; i < 2 * n; i++) ans = (ans + v[i]) % MOD;
    ans %= MOD;
    ans = ans * ncr(2 * n, n) % MOD;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial[0] = 1;
    // factorial[1] = 1;
    for(int i = 1; i < MAXN; i++){
        factorial[i] = factorial[i-1] * i % MOD;
    }

    debug(factorial[5]);
    debug(ncr(10, 5));

    solve();
    return 0;
}