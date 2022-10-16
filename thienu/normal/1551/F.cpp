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

const int N = 205;
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

void solve(){
    int k, n;
    cin >> n >> k;
    vvi adj(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(k == 2){
        cout << n * (n-1) / 2 << endl;
        return;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        vi dist(n, -1);
        vi sector(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(dist[v] != -1) continue;
                if(u == i){
                    sector[v] = v;
                }else{
                    sector[v] = sector[u];
                }
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        debug(dist, sector);
        map<int, map<int, int>> cnt;
        for(int j = 0; j < n; j++) cnt[dist[j]][sector[j]]++;
        for(pair<int, map<int, int>> p : cnt){
            vi s;
            debug(p.first, p.second);
            for(pii pp : p.second){
                s.push_back(pp.second);
            }
            debug(i, p.first, s);
            int m = s.size();
            vvll dp(m+1, vll(k+1));
            dp[0][0] = 1;
            for(int j = 1; j <= m; j++){
                dp[j][0] = dp[j-1][0];
                for(int x = 1; x <= k; x++){
                    dp[j][x] = add(dp[j-1][x], mul(dp[j-1][x-1], s[j-1]));
                }
            }
            ans = add(ans, dp[m][k]);
        }
    }
    cout << ans << endl;
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