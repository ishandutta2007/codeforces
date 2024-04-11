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

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}


const int INF = 1e9 + 7;

vpii neigh = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool oob(int i, int j, int n, int m){
    return !(0 <= i && i < n && 0 <= j && j < m);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    vi height_map(m, INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            grid[i][j] = c == '#';
            if(grid[i][j]) height_map[j] = min(height_map[j], i);
        }
    }
    // ignore for f1
    vi req(m);
    for(int i = 0; i < m; i++){
        cin >> req[i];
    }

    vvi next_highest(n, vi(m));
    for(int j = 0; j < m; j++){
        int x = -1;
        for(int i = 0; i < n; i++){
            next_highest[i][j] = x;
            if(grid[i][j]) x = i;
        }
    }
    debug(next_highest);

    vvi comp(n, vi(m, -1));
    int num_comp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(comp[i][j] != -1 || grid[i][j] == 0){
                continue;
            }
            queue<pii> q;
            comp[i][j] = num_comp;
            q.push({i, j});
            while(!q.empty()){
                pii p = q.front();
                q.pop();
                for(pii d : neigh){
                    int x = p.first + d.first, y = p.second + d.second;
                    if(!oob(x, y, n, m) && grid[x][y] && comp[x][y] == -1){
                        comp[x][y] = num_comp;
                        q.push({x, y});
                    }
                }
            }
            num_comp++;
        }
    }
    debug(comp);

    vector<set<int>> adj(num_comp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!grid[i][j]) continue;
            for(int jj = max(0, j-1); jj <= min(m-1, j+1); jj++){
                int x = next_highest[i][jj];
                if(x == -1) continue;
                int c = comp[x][jj];
                if(c != comp[i][j]) adj[c].insert(comp[i][j]);
            }
        }
    }
    debug(adj);

    vvi rev_adj(num_comp);
    for(int i = 0; i < num_comp; i++){
        for(int j : adj[i]){
            rev_adj[j].push_back(i);
        }
    }
    debug(rev_adj);

    int ans = 0;
    scc(adj, [&] (vi &v){
        debug(v);
        set<int> s;
        for(int i : v){
            s.insert(i);
        }
        int in = 0;
        for(int i : v){
            for(int j : rev_adj[i]){
                if(s.find(j) == s.end()){
                    in++;
                }
            }
        }
        if(in == 0){
            ans++;
        }
    });
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}