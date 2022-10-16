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

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll sub(ll a, ll b){
    return (a - b + MOD) % MOD;
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

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vvll wp(n, vll(n, 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            wp[i][j] = mul(v[i], inv(add(v[i], v[j])));
        }
    }

    vvll beats(n, vll(1<<n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1<<n); j++){
            if((j >> i) & 1) continue;
            beats[i][j] = 1;
            for(int b = 0; b < n; b++){
                if((j >> b) & 1){
                    beats[i][j] = mul(beats[i][j], wp[i][b]);
                }
            }
        }
    }
    debug(beats);

    auto beats_all = [&](int s, int t) -> ll{
        ll ans = 1;
        for(int b = 0; b < n; b++){
            if((s >> b) & 1){
                ans = mul(ans, beats[b][t]);
            }
        }
        return ans;
    };
    debug(beats_all(1, 2));

    ll ans = 0;
    vll dp(1<<n);
    for(int mask = 1; mask < (1<<n); mask++){
        dp[mask] = beats_all(mask, ((1<<n)-1)^mask);
        ll x = 0;
        for(int s = mask; s; s = (s-1)&mask){
            if(s == mask) continue;
            x = add(x, mul(dp[s], inv(beats_all(s, ((1<<n)-1)^mask))));
        }
        dp[mask] = mul(dp[mask], sub(1, x));
        ans = add(ans, mul(__builtin_popcount(mask), dp[mask]));
    }
    debug(dp);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}