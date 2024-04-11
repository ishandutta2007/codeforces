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

const int M = 505;
ll MOD;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
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

ll normalize(ll x){
    return (x % MOD + MOD) % MOD;
}

template <typename T>
T sum_pref(vector<T> &pref, int sz, int l, int r){
    if(l >= sz) return 0;
    if(r < 0) return 0;
    if(r < l) return 0;
    l = min(sz-1, max(0, l));
    r = min(sz-1, max(0, r));
    return add(pref[r+1], normalize(-pref[l]));
}

void solve(){
    int n;
    cin >> n >> MOD;
    int maxs = n * (n-1) / 2;
    // vvll sums(n+1, vll(maxs+1));
    // sums[0][0] = 1;
    // vvll sums_pref(n+1, vll(maxs+2));
    // for(int j = 1; j <= maxs+1; j++){
    //     sums_pref[0][j] = add(sums_pref[0][j-1], sums[0][j-1]);
    // }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= maxs; j++){
    //         sums[i][j] = j-i+1 >= 0 ? add(sums_pref[i-1][j+1], normalize(-sums_pref[i-1][j-i+1])) : sums_pref[i-1][j+1];
    //     }
    //     for(int j = 1; j <= maxs+1; j++){
    //         sums_pref[i][j] = add(sums_pref[i][j-1], sums[i][j-1]);
    //     }
    // }
    // debug(sums_pref);
    // debug(sums);
    vvll diffs(n+1, vll(2*maxs+1));
    diffs[0][maxs] = 1;
    vvll diffs_pref(n+1, vll(2*maxs+2));
    for(int j = 1; j <= 2*maxs+1; j++){
        diffs_pref[0][j] = add(diffs_pref[0][j-1], diffs[0][j-1]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            diffs[i][0] = add(diffs[i][0], mul(i-j, diffs[i-1][j]));
        }
        for(int j = 1; j <= 2 * maxs; j++){
            diffs[i][j] = add(diffs[i][j-1], add(sum_pref(diffs_pref[i-1], 2*maxs+1, j, j+i-1), normalize(-sum_pref(diffs_pref[i-1], 2*maxs+1, j-i, j-1))));
        }
        for(int j = 1; j <= 2*maxs+1; j++){
            diffs_pref[i][j] = add(diffs_pref[i][j-1], diffs[i][j-1]);
        }
    }
    debug(diffs_pref);
    debug(diffs);
    
    vvll P(M, vll(M));
    for(int i = 0; i < M; i++){
        P[i][0] = 1;
        for(int j = 1; j <= i; j++){
            P[i][j] = mul(P[i][j-1], i-j+1);
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        // first i are the same
        ll permutations = P[n][i];
        for(int d = 1; d <= n-i-1; d++){
            ll ways = n-i-abs(d);
            ll suffixes = sum_pref(diffs_pref[n-i-1], 2*maxs+1, maxs+d+1, 2*maxs);
            ans = add(ans, mul(permutations, mul(ways, suffixes)));
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