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

const int N = 2e5 + 20;
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

pii bounds(int l, int r, int mult){
    return {(l-1)/mult+1, (r-1)/mult+1};
}

void solve(){
    int n, m;
    cin >> n >> m;
    vpii v(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y+1};
    }
    vll ans(m+1);
    for(int p = m; p >= 1; p--){
        for(int j = p+p; j <= m; j+=p){
            ans[p] = sub(ans[p], ans[j]);
        }
        int bound = m/p;
        vi cap;
        int sum = 0;
        bool ok = true;
        for(int i = 0; i < n; i++){
            int l, r;
            tie(l, r) = bounds(v[i].first, v[i].second, p);
            // debug(l, r);
            cap.push_back(r-l-1);
            sum += l;
            if(r == l){
                ok = false;
                break;
            }
        }
        bound -= sum;
        if(!ok || bound < 0) continue;
        debug(p, bound, cap);
        vvll dp(n+1, vll(bound+1));
        vvll pref(n+1, vll(bound+2));
        dp[0][0] = 1;
        for(int j = 0; j <= bound; j++){
            pref[0][j+1] = add(pref[0][j], dp[0][j]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= bound; j++){
                dp[i][j] = sub(pref[i-1][j+1], pref[i-1][max(0, j-cap[i-1])]);
            }
            for(int j = 0; j <= bound; j++){
                pref[i][j+1] = add(pref[i][j], dp[i][j]);
            }
        }
        // debug(dp, pref);
        ll x = 0;
        for(int j = 0; j <= bound; j++){
            x = add(x, dp[n][j]);
        }
        debug(x);
        ans[p] = add(ans[p], x);
    }
    debug(ans);
    cout << ans[1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}