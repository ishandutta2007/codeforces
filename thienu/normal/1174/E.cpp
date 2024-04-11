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

const int N = 1e6 + 5;
int fact[N];
int inv_fact[N];
void precomp(){ // don't forget to call precomp()!
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = mul(fact[i-1], i);
    }
    for(int i = 0; i < N; i++){
        inv_fact[i] = inv(fact[i]);
    }
}

ll ncr(ll n, ll r){
    assert(n >= 0);
    if(r < 0 || r > n) return 0;
    return mul(fact[n], mul(inv_fact[r], inv_fact[n-r]));
}

int log2(int x){
    return 8 * sizeof(int) - __builtin_clz(x) - 1;
}

// positive integers <= n which are divisible by a, but not by b (a|b)
int divisible(int a, int b, int n){
    assert(b % a == 0);
    b /= a;
    n /= a;
    return n-(n/b);
}

ll calc(vi &factor, int n){
    debug(factor);
    int m = factor.size();
    vi suf(m+1);
    suf[m] = 1;
    for(int i = m-1; i >= 0; i--){
        suf[i] = suf[i+1] * factor[i];
    }
    vi choices = {1};
    for(int i = 1; i <= m; i++){
        choices.push_back(divisible(suf[i], suf[i-1], n));
    }
    debug(choices);
    ll ans = 1;
    int places = 0;
    for(int i = m; i >= 0; i--){
        ans = mul(ans, choices[i]);
        ans = mul(ans, mul(ncr(places + choices[i] - 1, choices[i] - 1), fact[choices[i] - 1]));
        places += choices[i];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    debug(log2(n));
    ll ans = 0;
    int m = log2(n);
    int p2 = (1<<log2(n));
    vi v(log2(n), 2);
    ans = add(ans, calc(v, n));
    if(p2 * 3 / 2 <= n){
        for(int i = 0; i < m; i++){
            v[i] = 3;
            ans = add(ans, calc(v, n));
            v[i] = 2;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}