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

const int N = 3e6 + 20;
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



vll divide(vll a, vll b, int sz){
    int m = m = b.size();
    a.resize(sz+m);
    int n = a.size();
    debug(n, m);
    vll ans;
    ll ib = inv(b[0]);
    for(int i = 0; i <= sz; i++){
        debug(i);
        // divide
        ll x = mul(ib, a[i]);
        ans.push_back(x);
        for(int j = 0; j < m; j++){
            a[i+j] = add(a[i+j], normalize(-mul(x, b[j])));
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vll a = {3, 3, 1};
    vll b(3*n+3);
    for(int i = 0; i < 3*n+3; i++){
        b[i] = ncr(3*n+3, i+1);
    }
    debug(a, b);
    vll gf = divide(b, a, 3*n);
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << gf[x] << '\n';
    }
    // debug(divide({1,2,1}, {2,1}, 4));
}

// don't forget to submit after contest!

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}