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
const ll HALF = 499122177;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll neg(ll x){
    return -x + MOD * (x != 0);
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

const int F = 2e5 + 12;
vll factorial(F);
vll inv_factorial(F);

ll ncr(ll n, ll r){
    return mul(factorial[n], mul(inv_factorial[r], inv_factorial[n-r]));
}

void precalc(){
    factorial[0] = 1;
    for(int i = 1; i < F; i++){
        factorial[i] = mul(factorial[i-1], i);
    }
    for(int i = 0; i < F; i++){
        inv_factorial[i] = inv(factorial[i]);
    }
}

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    vll v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vll shift(n);
    for(int i = 0; i < n; i++){
        shift[i] = v[(i-1+n)%n];
    }
    int diff = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != shift[i]){
            diff++;
        }
    }
    if(diff == 0){
        cout << 0 << endl;
        return;
    }
    ll zero = 0;
    for(int i = 0; diff-2*i >= 0; i++){
        zero = add(zero, mul(binexp(k-2, diff-2*i), mul(ncr(diff, 2*i), ncr(2*i, i))));
    }
    zero = mul(zero, binexp(k, n-diff));
    ll all = binexp(k, n);
    cout << mul(HALF, add(all, neg(zero)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    solve();
    return 0;
}