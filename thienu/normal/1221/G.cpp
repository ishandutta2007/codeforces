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

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi vis(n);
    vll ans(8, 1);
    vi color(n);
    vi idx(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        vi cc;
        queue<int> q;
        vis[i] = 1;
        cc.push_back(i);
        q.push(i);
        color[i] = 0;
        bool bipartite = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(vis[v]){
                    if(color[v] == color[u]) bipartite = false;
                    continue;
                }
                color[v] = color[u] ^ 1;
                vis[v] = 1;
                q.push(v);
                cc.push_back(v);
            }
        }
        for(int j = 0; j < cc.size(); j++){
            idx[cc[j]] = j;
        }
        if(cc.size() == 1){
            for(int i = 0; i < 8; i++){
                ans[i] *= 2;
            }
            continue;
        }
        debug(cc, bipartite);
        int B = (int)cc.size()/2;
        debug(B);
        vll aa_adj(B);
        vll ab_adj(B);
        vll bb_adj(cc.size()-B);
        for(int j = 0; j < B; j++){
            for(int u : adj[cc[j]]){
                if(idx[u] < B) aa_adj[j] |= (1LL<<idx[u]);
                else ab_adj[j] |= (1LL<<(idx[u]-B));
            }
        }
        for(int j = B; j < cc.size(); j++){
            for(int u : adj[cc[j]]){
                if(idx[u] >= B) bb_adj[j-B] |= (1LL<<(idx[u]-B));
            }
        }
        debug(ab_adj, aa_adj, bb_adj);
        vll a((1<<B));
        vll b((1<<((int)cc.size()-B)));
        for(int j = 0; j < (1<<B); j++){
            ll cur = 0;
            bool ok = true;
            for(int k = 0; k < B; k++){
                if((j>>k) & 1){
                    if((cur >> k) & 1){
                        ok = false;
                        break;
                    }
                    cur |= aa_adj[k];
                }
            }
            if(ok){
                a[j] = 1;
            }
        }
        for(int j = 0; j < (1<<(cc.size()-B)); j++){
            ll cur = 0;
            bool ok = true;
            for(int k = 0; k < (cc.size()-B); k++){
                if((j>>k) & 1){
                    if((cur >> k) & 1){
                        ok = false;
                        break;
                    }
                    cur |= bb_adj[k];
                }
            }
            if(ok){
                b[j] = 1;
            }
        }
        debug(a, b);
        // sos on b
        for(int k = 0; k < (cc.size()-B); k++){
            for(int j = 0; j < (1<<(cc.size()-B)); j++){
                if((j>>k) & 1){
                    b[j] += b[j^(1<<k)];
                }
            }
        }
        debug(b);

        ll independent_cnt = 0;
        for(int j = 0; j < (1<<B); j++){
            if(!a[j]) continue;
            ll allowed = (1<<(cc.size()-B))-1;
            for(int k = 0; k < B; k++){
                if((j>>k) & 1){
                    allowed &= ~ab_adj[k];
                }
            }
            independent_cnt += b[allowed];
        }
        debug(independent_cnt);

        ans[0] *= (1LL << cc.size()); // any
        ans[1] *= independent_cnt; // no 0
        ans[4] *= independent_cnt; // no 2
        ans[2] *= 2; // no 1
        ans[3] *= 1; // no 0/1
        ans[6] *= 1; // no 1/2
        ans[5] *= (bipartite ? 2 : 0); // no 0/2
        ans[7] *= 0; // no 0/1/2
    }
    debug(ans);
    cout << ans[0]-ans[1]-ans[2]-ans[4]+ans[3]+ans[5]+ans[6]-ans[7] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}