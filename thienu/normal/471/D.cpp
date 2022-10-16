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


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// generates from [left, right)
ll randint(ll left, ll right){
    return rng() % (right - left) + left;
}

ll MOD = 1e9 + 7;


ll binpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}


ll inverse(ll a){
    return binpow(a, MOD - 2);
}


void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];
    if(k == 1){
        cout << n << endl;
        return;
    }
    if(n < k){
        cout << 0 << endl;
        return;
    }
    vi string(n-1);
    vi pattern(k-1);
    for(int i = 0; i < n-1; i++){
        string[i] = a[i+1]-a[i];
    }
    for(int i = 0; i < k-1; i++){
        pattern[i] = b[i+1]-b[i];
    }
    debug(string, pattern);
    // debug(randint(0, MOD));

    ll base = randint(0, MOD);
    debug(base);

    // hash pattern
    ll pattern_hash = 0;
    ll base_pow = 1;
    for(int i = 0; i < k-1; i++){
        pattern_hash = (pattern_hash + (((ll) pattern[i] % MOD + MOD) % MOD) * base_pow) % MOD;
        base_pow = (base_pow * base) % MOD;
    }
    debug(pattern_hash);

    // rolling hash string
    vll prefix_hashes(n);
    base_pow = 1;
    ll string_hash = 0;
    for(int i = 0; i < n-1; i++){
        string_hash = (string_hash + (((ll) string[i] % MOD + MOD) % MOD) * base_pow) % MOD;
        prefix_hashes[i+1] = string_hash;
        base_pow = (base_pow * base) % MOD;
    }

    debug(prefix_hashes);

    int ans = 0;
    for(int i = 0; i + k - 1 < n; i++){
        ll substring_hash = (inverse(binpow(base, i)) * ((prefix_hashes[i+k-1] - prefix_hashes[i]) % MOD + MOD) % MOD) % MOD;
        debug(i, substring_hash);
        if(substring_hash == pattern_hash) ans++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}