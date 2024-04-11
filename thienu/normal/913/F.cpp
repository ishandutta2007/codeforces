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

const ll MOD = 998244353;

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

const ll HALF = 499122177;

ll nc2(ll n){
    return mul(n, mul(n-1, HALF));
}

void solve(){
    int n, _a, _b;
    cin >> n >> _a >> _b;
    int p = mul(_a, inv(_b));
    vvll win_p(n+1, vll(n+1));
    win_p[0][0] = 1;
    for(int i = 1; i <= n; i++){
        win_p[i][0] = 1;
        for(int j = 1; j <= i; j++){
            win_p[i][j] = add(mul(win_p[i-1][j], binexp(p, j)), mul(win_p[i-1][j-1], binexp(sub(1, p), i-j)));
        }
    }
    debug(win_p);
    vll ctour(n+1);
    ctour[1] = 1;
    for(int i = 2; i <= n; i++){
        ctour[i] = 1;
        for(int j = 1; j < i; j++){
            ctour[i] = sub(ctour[i], mul(ctour[j], win_p[i][j]));
        }
    }
    debug(ctour);

    vll ans(n+1);
    ans[1] = 0;
    for(int i = 2; i <= n; i++){
        ll x = 0;
        for(int j = 1; j < i; j++){
            x = add(x, mul(mul(ctour[j], win_p[i][j]), add(add(mul(j, (i-j)), nc2(j)), add(ans[j], ans[i-j]))));
        }
        x = add(x, mul(nc2(i), ctour[i]));
        ans[i] = mul(x, inv(sub(1, ctour[i])));
    }
    debug(ans);
    cout << ans[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}