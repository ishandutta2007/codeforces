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

struct TwoSat {
    vvi adj;
    vvi radj;

    void add_edge(int x, int y){
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    TwoSat(int n) {
        adj.resize(2*n);
        radj.resize(2*n);
    }

    void resize(int n){
        adj.resize(2*n);
        radj.resize(2*n);
    }

    using Var = int;

    Var var(int x, bool is_negated){
        return (x << 1) | is_negated;
    }

    Var neg(Var x){
        return x ^ 1;
    }

    // x || y
    void c_or(Var x, Var y){
        add_edge(neg(x), y);
        add_edge(neg(y), x);
    }

    // x => y
    void c_implies(Var x, Var y){
        c_or(neg(x), y);
    }

    // x xor y
    void c_xor(Var x, Var y){
        debug(x, y);
        c_implies(x, neg(y));
        c_implies(neg(x), y);
        // c_or(x, y);
        // c_or(neg(x), neg(y));
    }

    // x
    void c_true(Var x){
        c_or(x, x);
    }

    // returns true if it is satisfiable. If satisfiable, also returns a satisfying arrangement.
    bool solve(vector<bool> &result){
        int n = adj.size();
        vi vis(n);
        vi order;
        vi fin(n);
        int time = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            dfs1(i, vis, order, fin, time);
        }
        debug(order);
        reverse(order.begin(), order.end());
        debug(order);
        fill(vis.begin(), vis.end(), 0);
        vi cc(n);
        int comp = 0;
        for(int i : order){
            if(vis[i]) continue;
            dfs2(i, comp, vis, cc);
            comp++;
        }
        debug(cc, fin, order);
        for(int i = 0; i < n; i+=2){
            if(cc[i] == cc[i^1]){
                debug(i>>1);
                return false;
            }
        }
        for(int i = 0; i < n; i+=2){
            result[i>>1] = cc[i] > cc[i^1];
        }
        return true;
    }

    void dfs1(int u, vi &vis, vi &order, vi &fin, int &time){
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs1(v, vis, order, fin, time);
            }
        }
        order.push_back(u);
        fin[u] = time++;
    }

    void dfs2(int u, int id, vi &vis, vi &cc){
        vis[u] = 1;
        cc[u] = id;
        for(int v : radj[u]){
            if(!vis[v]){
                dfs2(v, id, vis, cc);
            }
        }
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    TwoSat ts(n * (k+1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            ts.c_implies(ts.var(i*(k+1)+j, false), ts.var(i*(k+1)+j+1, false)); // a_i <= j => a_i <= j+1
        }
        ts.c_true(ts.var(i*(k+1)+k, false)); // a_i <= k
        ts.c_true(ts.var(i*(k+1), true)); // a_i > 0
    }

    // non-decreasing array
    for(int i = 0; i+1 < n; i++){
        for(int j = 0; j <= k; j++){
            ts.c_implies(ts.var(i*(k+1)+j, true), ts.var((i+1)*(k+1)+j, true)); // a_i > j => a_{i+1} > j 
        }
    }

    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int i, x;
            cin >> i >> x;
            i--;
            ts.c_implies(ts.var(i*(k+1)+x, false), ts.var(i*(k+1)+x-1, false)); // a_i <= x => a_i <= x-1
        }else if(t == 2){
            int i, j, x;
            cin >> i >> j >> x;
            i--;
            j--;
            for(int p = 0; p <= x; p++){
                int q = x - p - 1;
                if(p < 0 || p > k || q < 0 || q > k) continue;
                ts.c_implies(ts.var(i*(k+1)+p, true), ts.var(j*(k+1)+q, false)); // a_i > p => a_j <= q
            }
        }else{
            int i, j, x;
            cin >> i >> j >> x;
            i--;
            j--;
            for(int p = 0; p <= x; p++){
                int q = x - p - 1;
                if(p < 0 || p > k || q < 0 || q > k) continue;
                ts.c_implies(ts.var(i*(k+1)+p, false), ts.var(j*(k+1)+q, true)); // a_i <= p => a_j > q
            }
        }
    }

    // for(int i = 0; i < ts.adj.size(); i++){
    //     for(int j : ts.adj[i]){
    //         cout << i << ' ' << j << endl;
    //     }
    // }

    vector<bool> result(n * (k+1));
    bool sat = ts.solve(result);
    debug(sat, result);

    if(!sat){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= k; j++){
                if(result[i*(k+1)+j] && !result[i*(k+1)+j-1]){
                    cout << j << ' ';
                    break;
                }
            }
        }
        cout << endl;
    }
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