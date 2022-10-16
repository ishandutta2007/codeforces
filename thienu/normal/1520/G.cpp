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

ll INF = 1e18;

const vpii directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool oob(int x, int y, int n, int m){
    return x < 0 || y < 0 || x >= n || y >= m;
}

void populate(vvi &dist, vvi &board, pii start, int n, int m){
    vvi vis(n, vi(m));
    queue<pair<int, pii>> q;
    q.push({0, start});
    vis[start.first][start.second] = 1;
    while(!q.empty()){
        int d;
        pii pos;
        tie(d, pos) = q.front();
        q.pop();
        dist[pos.first][pos.second] = d;
        for(pii direction : directions){
            pii nxt = {pos.first + direction.first, pos.second + direction.second};
            if(!oob(nxt.first, nxt.second, n, m) && board[nxt.first][nxt.second] != -1 && !vis[nxt.first][nxt.second]){
                q.push({d + 1, nxt});
                vis[nxt.first][nxt.second] = 1;
            }
        }
    }
}

void solve(){
    int n, m, w;
    cin >> n >> m >> w;
    vvi board(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    vvi start_dist(n, vi(m, -1));
    populate(start_dist, board, {0, 0}, n, m);
    vvi end_dist(n, vi(m, -1));
    populate(end_dist, board, {n-1, m-1}, n, m);
    debug(start_dist, end_dist);
    ll ans = INF;
    // no portal
    if(start_dist[n-1][m-1] != -1){
        ans = (ll) start_dist[n-1][m-1] * w;
    }
    // portals
    ll start_portal = INF;
    ll end_portal = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] > 0){
                if(start_dist[i][j] != -1){
                    start_portal = min(start_portal, (ll) w * start_dist[i][j] + board[i][j]);
                }
                if(end_dist[i][j] != -1){
                    end_portal = min(end_portal, (ll) w * end_dist[i][j] + board[i][j]);
                }
            }
        }
    }
    if(start_portal < INF && end_portal < INF) ans = min(ans, start_portal + end_portal);

    if(ans >= INF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}