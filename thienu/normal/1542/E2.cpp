// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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
    return x + (x < 0) * MOD;
}

template <typename T>
T sum_pref(T *pref, int sz, int l, int r){
    if(l >= sz) return 0;
    if(r < 0) return 0;
    if(r < l) return 0;
    l = min(sz-1, max(0, l));
    r = min(sz-1, max(0, r));
    return normalize(pref[r+1] - pref[l]);
}

const int T = 124750;
ll diffs[2*T+1];
ll diffs_pref[2*T+2];

void solve(){
    int n;
    cin >> n >> MOD;
    // int T = n * (n-1) / 2;
    vvll P(M, vll(M));
    for(int i = 0; i < M; i++){
        P[i][0] = 1;
        for(int j = 1; j <= i; j++){
            P[i][j] = mul(P[i][j-1], i-j+1);
        }
    }

    ll ans = 0;

    // vll diffs(2*T+1);
    diffs[T] = 1;
    // vll diffs_pref(2*T+2);
    for(int j = 1; j <= 2*T+1; j++){
        diffs_pref[j] = add(diffs_pref[j-1], diffs[j-1]);
    }
    for(int i = 1; i <= n; i++){

        int f = n-i;
        // first f are the same
        ll permutations = P[n][f];
        for(int d = 1; d <= n-f-1; d++){
            ll ways = n-f-abs(d);
            ll suffixes = sum_pref(diffs_pref, 2*T+1, T+d+1, 2*T);
            ans = add(ans, mul(permutations, mul(ways, suffixes)));
        }

        // vll new_diffs(2*T+1);
        // vll new_diffs_pref(2*T+2);
        ll nd0 = 0;
        for(int j = 0; j < i; j++){
            nd0 = add(nd0, mul(i-j, diffs[j]));
        }
        diffs[0] = nd0;
        for(int j = 1; j <= 2*T; j++){
            diffs[j] = normalize((diffs[j-1] + sum_pref(diffs_pref, 2*T+1, j, j+i-1) -sum_pref(diffs_pref, 2*T+1, j-i, j-1)) % MOD);
        }
        for(int j = 1; j <= 2*T+1; j++){
            diffs_pref[j] = add(diffs_pref[j-1], diffs[j-1]);
        }
        // diffs = new_diffs;
        // diffs_pref = new_diffs_pref;
    }
    // for(int i = 0; i < n; i++){
    // }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}