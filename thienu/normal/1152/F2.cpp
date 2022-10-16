#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
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

ll MOD = 1e9 + 7;

vvll multiply(vvll a, vvll b){
    int x = a.size();
    int y = b.size();
    int z = b[0].size();
    assert(y == a[0].size());
    vvll ans(x, vll(z));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            for(int k = 0; k < y; k++){
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

vvll binexp(vvll m, ll b){
    int n = m.size();
    vvll ans(n, vll(n));
    for(int i = 0; i < n; i++){
        ans[i][i] = 1;
    }
    while(b){
        if(b & 1){
            ans = multiply(ans, m);
        }
        m = multiply(m, m);
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n, k, m;
    cin >> n >> k >> m;

    int d = (k+1) * (1<<m);
    vvll mat(d+1, vll(d+1));
    mat[d][d] = 1;

    // dp[i][0][0] = 1;
    mat[0][d] = 1;
    for(int j = 1; j <= k; j++){
        for(int mask = 0; mask < (1<<m); mask++){
            int row = j*(1<<m)+mask;
            if(mask & 1){
                for(int b = 0; b < 2; b++){
                    // debug(i, j, mask, (__builtin_popcount((b<<(m-1))|(mask>>1))+1) * dp[i-1][j-1][(b<<(m-1))|(mask>>1)]);
                    // val += (__builtin_popcount((b<<(m-1))|(mask>>1))+1) * dp[i-1][j-1][(b<<(m-1))|(mask>>1)];
                    mat[row][(j-1)*(1<<m)+((b<<(m-1))|(mask>>1))] = (__builtin_popcount((b<<(m-1))|(mask>>1))+1);
                }
            }else{
                for(int b = 0; b < 2; b++){
                    // val += dp[i-1][j][(b<<(m-1))|(mask>>1)];
                    mat[row][j*(1<<m)+((b<<(m-1))|(mask>>1))] = 1;
                }
            }
            // dp[i][j][mask] = val % MOD;
        }
    }
    debug(mat);
    vvll v(d+1, vll(1));
    v[0][0] = 1;
    v[d][0] = 1;
    debug(v);

    vvll e = binexp(mat, n);
    debug(e);
    vvll res = multiply(e, v);
    debug(res);
    ll ans = 0;
    for(int mask = 0; mask < (1<<m); mask++){
        ans += res[k*(1<<m) + mask][0];
    }
    cout << ans%MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}