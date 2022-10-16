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

ll normalize(ll x){
    return (x % MOD + MOD) % MOD;
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

ll arrange(int y, int a){
    if(a > y) return 0LL;
    return mul(y-a, inv(y));
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    // {b, a}
    vector<pair<pii, int>> queries;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back({{b, a}, i});
    }
    sort(d.begin(), d.end());
    sort(queries.begin(), queries.end());
    // everything strictly left of d_ptr is < b
    auto d_ptr = d.begin();
    int cur_b = 0;
    ll less_sum = 0; // < b
    ll more_sum = accumulate(d.begin(), d.end(), 0LL, add); // >= b
    ll r = n;

    debug(less_sum, more_sum);

    vll ans(q);
    for(int i = 0; i < q; i++){
        int b, a;
        tie(b, a) = queries[i].first;
        while(d_ptr != d.end() && *d_ptr < b){
            less_sum = add(less_sum, *d_ptr);
            more_sum = add(more_sum, normalize(-*d_ptr));
            d_ptr++;
            r--;
        }
        debug(less_sum, more_sum, r);
        ll ca = add(mul(arrange(r, a), more_sum), mul(arrange(r+1, a), less_sum));
        ans[queries[i].second] = ca;
    }

    for(ll i : ans){
        cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}