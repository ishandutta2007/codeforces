#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

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

const int MOD = 31607;

int mul(int a, int b){
    return a * b % MOD;
}

int add(int a, int b){
    return (a + b) % MOD;
}

int binexp(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int inv(int x){
    return binexp(x, MOD - 2);
}

short row_divs[4][1<<21][21];
int inverse[MOD];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < MOD; i++){
        inverse[i] = inv(i);
    }


    debug(inv(4));
    debug(inv(8));
    debug(inv(1000));
    debug(mul(7, inv(32)));
    debug(mul(267, inv(512)));
    debug(inv(1'000'000'000%MOD));
    debug(mul(1953125%MOD, inv(1'000'000'000%MOD)));
    debug(inv(512));

    debug(mul(1, inv(10)));
    debug(mul(2, inv(10)));
    debug(mul(3, inv(10)));
    debug(mul(6, inv(1000)));
    
    vvi prob(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            prob[i][j] = mul(x, 3973); // mul by 10000^-1
        }
    }

    vi col_sums(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            col_sums[j] = mul(col_sums[j], prob[i][j]);
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < (1<<n); j++){
            for(int k = 0; k < n; k++){
                row_divs[i][j][k] = 1;
            }
        }
    }
    vvi diag_sums(4, vi(n, 1));
    for(int diag = 0; diag < 4; diag++){
        vvi forbidden(n, vi(n));
        if(diag & 0b01){
            for(int i = 0; i < n; i++){
                forbidden[i][i] = 1;
            }
        }
        if(diag & 0b10){
            for(int i = 0; i < n; i++){
                forbidden[i][n-i-1] = 1;
            }
        }
        debug(diag, forbidden);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(forbidden[i][j]){
                    diag_sums[diag][j] = mul(diag_sums[diag][j], prob[i][j]);
                }
            }
        }

        for(int b = 0; b < n; b++){
            for(int i = 0; i < n; i++){
                if(forbidden[b][i]) continue;
                row_divs[diag][1<<b][i] = mul(row_divs[diag][1<<b][i], prob[b][i]);
            }
        }
        for(int mask = 1; mask < (1<<n); mask++){
            int p = 1<<(31-__builtin_clz(mask));
            // debug(mask, p);
            if((mask ^ p) == 0){
                continue;
            }
            for(int i = 0; i < n; i++){
                row_divs[diag][mask][i] = mul(row_divs[diag][p][i], row_divs[diag][mask ^ p][i]);
            }
        }
    }

    // debug(row_divs, diag_sums);

    int ans = 0;
    for(int row_mask = 0; row_mask < (1<<n); row_mask++){
        for(int diag = 0; diag < 4; diag++){
            vi col_probs(n, 1);
            int pr = 1;
            for(int i = 0; i < n; i++){
                col_probs[i] = mul(col_probs[i], row_divs[diag][row_mask][i]);
                col_probs[i] = mul(col_probs[i], diag_sums[diag][i]);
                pr = mul(pr, col_probs[i]);
            }
            // debug(col_probs);
            debug(diag, row_mask, col_probs);
            for(int col = 0; col < 2; col++){
                if((row_mask | diag | col) == 0) continue;
                int sgn = (__builtin_popcount(row_mask ^ diag ^ col) & 1) ? 1 : MOD-1;
                if(col == 0){
                    ans = add(ans, mul(sgn, pr));
                    debug(pr);
                }else{
                    vi complete_probs(n);
                    for(int i = 0; i < n; i++){
                        complete_probs[i] = mul(col_sums[i], inverse[col_probs[i]]);
                    }
                    debug(complete_probs);
                    int col_complete = 1;
                    for(int i = 0; i < n; i++){
                        col_complete = mul(col_complete, add(MOD+1, -complete_probs[i]));
                    }
                    col_complete = add(MOD+1, -col_complete);
                    ans = add(ans, mul(sgn, mul(pr, col_complete)));
                    debug(mul(pr, col_complete));
                }
            }
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