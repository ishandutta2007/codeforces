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

const int MAXF = 505;
// const int MAXF = 10;
vll factorial(MAXF);
vll factorial_inv(MAXF);

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    ll ans = (a + b) % MOD;
    return ans + (ans < 0) * MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = mul(a, ans);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inverse(ll a){
    return binexp(a, MOD - 2);
}

ll ncr(ll n, ll r){
    return mul(factorial[n], mul(factorial_inv[r], factorial_inv[n-r]));
}

void precalc(){
    factorial[0] = 1;
    for(int i = 1; i < MAXF; i++){
        factorial[i] = mul(factorial[i-1], i);
    }
    for(int i = 0; i < MAXF; i++){
        factorial_inv[i] = inverse(factorial[i]);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    
    // big_ncr[i] = C(n, i)
    vll big_ncr(MAXF);
    for(int i = 0; i < MAXF; i++){
        ll a = 1;
        for(int j = n-i+1; j <= n; j++){
            a = mul(a, j);
        }
        for(int j = 1; j <= i; j++){
            a = mul(a, inverse(j));
        }
        big_ncr[i] = a;
    }
    // debug(big_ncr);
    
    // editorial: swaps[i][j] is # perms length i, min swaps j
    vvll swaps(MAXF, vll(MAXF));
    for(int i = 0; i < MAXF; i++){
        swaps[i][0] = 1;
        for(int j = 1; j < i; j++){
            swaps[i][j] = add(swaps[i-1][j], mul((i-1), swaps[i-1][j-1]));
        }
    }
    // debug(swaps);

    // editorial: dp[i][j] is # derangements length i, min swaps j
    vvll dp(MAXF, vll(MAXF));
    dp[0][0] = 1;
    for(int i = 0; i < MAXF; i++){
        for(int j = 0; j < i; j++){
            // inclusion/exclusion, f = # fixed points
            for(int f = 0; f <= i; f++){
                dp[i][j] = add(dp[i][j], mul(((f & 1) ? -1 : 1), mul(ncr(i, f), swaps[i-f][j])));
            }
        }
    }

    // debug(dp);

    vll ans(k+1);
    for(int i = 1; i <= k; i++){
        // j is # moved points
        for(int j = 0; j <= min(n, 2 * i); j++){
            // m is min # swaps
            for(int m = i; m >= 0; m -= 2){
                ans[i] = add(ans[i], mul(big_ncr[j], dp[j][m]));
            }
        }
    }
    for(int i = 1; i <= k; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    precalc();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}