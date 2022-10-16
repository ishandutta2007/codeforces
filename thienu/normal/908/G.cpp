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

void inc(ll &x, ll a){
    x = add(x, a);
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for(int d = 1; d <= 9; d++){
        vector<vvll> dp(n+1, vvll(n+1, vll(2)));
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                // dp[i][j][0]
                if(s[i]-'0' >= d){
                    inc(dp[i+1][j+1][0], dp[i][j][0]);
                    inc(dp[i+1][j+1][1], mul(dp[i][j][0], (s[i]-'0')-d));
                    inc(dp[i+1][j][1], mul(dp[i][j][0], d));
                }else{
                    inc(dp[i+1][j][0], dp[i][j][0]);
                    inc(dp[i+1][j][1], mul(dp[i][j][0], (s[i]-'0')));
                }
                // dp[i][j][1]
                inc(dp[i+1][j+1][1], mul(dp[i][j][1], 10-d));
                inc(dp[i+1][j][1], mul(dp[i][j][1], d));
            }
        }
        debug(d, dp);
        ll running = 0;
        for(int pos = 0; pos < n; pos++){
            inc(running, add(dp[n][n-pos][0], dp[n][n-pos][1]));
            inc(ans, mul(binexp(10, n-pos-1), running));
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}