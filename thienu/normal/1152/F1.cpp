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

const int N = 1e5 + 10;
const int K = 13;
const int M = 4;
ll dp[N][K][1<<M];

ll MOD = 1e9 + 7;

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int k = 0; k < (1<<M); k++){
                dp[i][j][k] = 0;
            }
        }
    }
    int n, k, m;
    cin >> n >> k >> m;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0][0] = 1;
        for(int j = 1; j <= k; j++){
            for(int mask = 0; mask < (1<<m); mask++){
                ll val = 0;
                if(mask & 1){
                    for(int b = 0; b < 2; b++){
                        debug(i, j, mask, (__builtin_popcount((b<<(m-1))|(mask>>1))+1) * dp[i-1][j-1][(b<<(m-1))|(mask>>1)]);
                        val += (__builtin_popcount((b<<(m-1))|(mask>>1))+1) * dp[i-1][j-1][(b<<(m-1))|(mask>>1)];
                    }
                }else{
                    for(int b = 0; b < 2; b++){
                        val += dp[i-1][j][(b<<(m-1))|(mask>>1)];
                    }
                }
                dp[i][j][mask] = val % MOD;
            }
        }
    }
    ll ans = 0;
    for(int mask = 0; mask < (1<<m); mask++){
        debug(mask, dp[n][k][mask]);
        ans += dp[n][k][mask];
    }
    cout << ans%MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}