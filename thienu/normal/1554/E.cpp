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

const int N = 1e5 + 5;
vi lp(N), pr;
void precomp(){
    for(int i = 2; i < N; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++){
            lp[i * pr[j]] = pr[j];
        }
    }
}

void dfs(int u, int last, vvi &adj, vi &a, vi &dp, int mult){
    for(int v : adj[u]){
        if(v == last) continue;
        dfs(v, u, adj, a, dp, mult);
        if(dp[v] == 0){
            dp[u] = 0;
            return;
        }
    }
    if(last == -1){
        if(a[u] % mult == 0){
            dp[u] = 1;
        }
        return;
    }
    if(a[u] % mult == 0){
        dp[u] = 1;
        a[last]++;
    }else if(a[u] % mult == mult - 1){
        dp[u] = 1;
    }
}

int get_ans(int n, vvi &adj, int mult){
    vi dp(n);
    vi a(n);
    dfs(0, -1, adj, a, dp, mult);
    return dp[0];
}

void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vll mult_arr(n+1);
    set<int> factors = {1};
    int m = n-1;
    while(m > 1){
        debug(m);
        int f = lp[m];
        set<int> nf = factors;
        for(int i : factors){
            nf.insert(i * f);
        }
        m /= lp[m];
        factors = nf;
    }
    debug(factors);
    factors.erase(1);

    mult_arr[1] = binexp(2, n-1);
    for(int i : factors){
        mult_arr[i] = get_ans(n, adj, i);
    }

    vll ans(n+1);
    for(int i = n; i >= 1; i--){
        ans[i] = mult_arr[i];
        for(int j = i+i; j <= n; j+=i){
            ans[i] = add(ans[i], normalize(-ans[j]));
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}