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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

int find_parent(vi &par, int x){
    if(par[x] == x) return x;
    return par[x] = find_parent(par, par[x]);
}

void merge(vi &par, int x, int y){
    x = find_parent(par, x);
    y = find_parent(par, y);
    par[x] = y;
}

void solve(){
    int n;
    cin >> n;
    vvvb same(n, vvb(n, vb(n, false)));
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            string s;
            cin >> s;
            for(int k = 0; k < n; k++){
                same[i][i+j+1][k] = (s[k] == '1');
                same[i+j+1][i][k] = (s[k] == '1');
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            same[i][i][k] = 1;
        }
    }

    debug(same);

    vvi equiv;

    // check equivalence classes
    for(int k = 0; k < n; k++){
        // debug(k);
        vi par(n);
        iota(par.begin(), par.end(), 0);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(same[i][j][k]){
                    merge(par, i, j);
                }
            }
        }

        // debug(par);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // debug(i, j, par);
                if(find_parent(par, i) == find_parent(par, j) && !same[i][j][k]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }

        for(int i = 0; i < n; i++){
            find_parent(par, i);
        }

        equiv.push_back(par);
    }
    // cout << "MAYBE" << endl;
    debug(equiv);
    
    for(int g = 1; g < n; g++){
        // guess that equiv[0][g] represents distance 1
        vvi adj(n);
        vi dist1(n, -1);
        dist1[0] = equiv[0][g];
        queue<int> q;
        q.push(0);
        int edges = 0;
        int vertices = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vertices++;
            for(int v = 0; v < n; v++){
                if(equiv[u][v] == dist1[u]){
                    if(dist1[v] == -1){
                        dist1[v] = equiv[v][u];
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                        edges++;
                        q.push(v);
                    }
                }
            }
        }
        debug(g, adj, edges, vertices);

        if(edges != n-1 || vertices != n){
            continue;
        }

        // guaranteed tree
        // check equivalences again
        vvi dist(n, vi(n, -1));
        for(int r = 0; r < n; r++){
            queue<int> qu;
            qu.push(r);
            dist[r][r] = 0;
            while(!qu.empty()){
                int u = qu.front();
                qu.pop();
                for(int v : adj[u]){
                    if(dist[r][v] == -1){
                        dist[r][v] = dist[r][u] + 1;
                        qu.push(v);
                    }
                }
            }
        }
        debug(g, dist);

        bool ok = true;
        for(int i = 0; i < n; i++){
            vi rep(n, -1);
            for(int j = 0; j < n; j++){
                if(rep[equiv[i][j]] != -1 && rep[equiv[i][j]] != dist[i][j]){
                    ok = false;
                }
                rep[equiv[i][j]] = dist[i][j];
            }
        }

        if(ok){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                for(int j : adj[i]){
                    if(j > i){
                        cout << i+1 << ' ' << j+1 << endl;
                    }
                }
            }
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}