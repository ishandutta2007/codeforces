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
const int T = 1e4 + 5;
// const int T = 20;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll neg(ll x){
    return (MOD - x) % MOD;
}

void solve(){
    int n;
    cin >> n;
    vi c(n), b(n-1), p(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n-1; i++) cin >> b[i];
    int q, x;
    cin >> q >> x;
    debug(q, x);
    for(int i = 1; i < n; i++){
        p[i] = p[i-1] + b[i-1];
    }
    vi p_pref(n+1);
    for(int i = 1; i < n+1; i++){
        p_pref[i] = p[i-1] + p_pref[i-1];
    }
    
    vi threshold(n);
    for(int i = 0; i < n; i++){
        threshold[i] = (i+1) * x + p_pref[i+1];
    }
    debug(threshold);

    vvll dp(n+1, vll(T));
    vvll dpp(n+1, vll(T+1));
    dp[0][0] = 1;
    for(int i = 1; i <= T; i++){
        dpp[0][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = max(0, threshold[i-1]); j < T; j++){
            int fi = max(0, j-c[i-1]);
            // for(int k = 0; k <= min(j, c[i-1]); k++){
            //     dp[i][j] = add(dp[i][j], dp[i-1][j-k]);
            // }
            dp[i][j] = add(dpp[i-1][j+1], neg(dpp[i-1][fi]));
        }
        for(int j = 1; j <= T; j++){
            dpp[i][j] = add(dpp[i][j-1], dp[i][j-1]);
        }
    }
    ll ans = 0;
    for(int j = 0; j < T; j++){
        ans = add(ans, dp[n][j]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}