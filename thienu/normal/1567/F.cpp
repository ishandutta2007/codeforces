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

vpii dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<vpii>> adj(n, vector<vpii>(m));
    vvi f(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.') continue;
            vpii free;
            for(pii off : dir){
                pii np = {off.first+i, off.second+j};
                if(grid[np.first][np.second] == '.'){
                    free.push_back(np);
                }
            }
            if((int)free.size() & 1){
                cout << "NO" << endl;
                return;
            }
            if(free.size() == 2){
                adj[free[0].first][free[0].second].push_back(free[1]);
                adj[free[1].first][free[1].second].push_back(free[0]);
            }else if(free.size() == 4){
                adj[i-1][j].push_back({i, j-1});
                adj[i][j-1].push_back({i-1, j});
                adj[i+1][j].push_back({i, j+1});
                adj[i][j+1].push_back({i+1, j});
            }
            f[i][j] = free.size();
        }
    }
    debug(adj);

    vvi ans(n, vi(m, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'X'){
                ans[i][j] = 5 * f[i][j] / 2;
                continue;
            }
            if(ans[i][j] != -1) continue;
            queue<pii> q;
            q.push({i, j});
            ans[i][j] = 1;
            while(!q.empty()){
                pii p = q.front();
                q.pop();
                for(pii x : adj[p.first][p.second]){
                    if(ans[x.first][x.second] != -1) continue;
                    ans[x.first][x.second] = 5 - ans[p.first][p.second];
                    q.push(x);
                }
            }
        }
    }
    debug(ans);
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}