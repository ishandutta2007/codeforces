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
const int N = 2e6 + 69;
ll factorial[N];
ll inv_factorial[N];

ll mul(ll x, ll y){
    return x * y % MOD;
}

ll add(ll x, ll y){
    ll ans = (x + y) % MOD;
    return ans + (ans < 0) * MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

void precompute(){
    factorial[0] = 1;
    for(int i = 1; i < N; i++){
        factorial[i] = mul(factorial[i-1], i);
    }
    for(int i = 0; i < N; i++){
        inv_factorial[i] = inv(factorial[i]);
    }
}

ll ncr(ll n, ll r){
    assert(n >= 0);
    if(r < 0 || r > n) return 0;
    return mul(factorial[n], mul(inv_factorial[r], inv_factorial[n-r]));
}

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int m = 0; n-2*m >= 0; m++){
        ans = add(ans, mul(ncr(2*m, n-2*m), factorial[2*m]));
    }
    for(int m = 1; n-2*m-1 >= 0; m++){
        ans = add(ans, mul(ncr(2*m-1, n-2*m-1), factorial[2*m]));
    }
    cout << mul(ans, 2) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    solve();
    return 0;
}