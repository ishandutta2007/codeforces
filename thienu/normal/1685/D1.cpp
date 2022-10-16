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

int find_par(vi &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find_par(parent, parent[x]);
}

void merge(vi &parent, int x, int y){
    x = find_par(parent, x);
    y = find_par(parent, y);
    if(x == y) return;
    parent[x] = y;
}

void solve(){
    int n;
    cin >> n;
    vi p(n);
    vi invp(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        invp[p[i]] = i;
    }
    debug(p, invp);
    vvi cycles;
    vvi sorted_cycles;
    vi cvis(n);
    for(int i = 0; i < n; i++){
        if(cvis[i]) continue;
        int cur = i;
        vi cycle;
        while(!cvis[cur]){
            cvis[cur] = 1;
            cycle.push_back(cur);
            cur = invp[cur];
        }
        cycles.push_back(cycle);
        vi scycle = cycle;
        sort(scycle.begin(), scycle.end());
        sorted_cycles.push_back(scycle);
    }
    debug(cycles);

    int m = cycles.size();

    debug(sorted_cycles);

    vector<vector<int>> min_dist(m, vi(m));
    vector<vector<pii>> pairs(m, vpii(m));
    debug(min_dist, pairs);
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            int md = 1e9;
            pii p;
            int a = 0;
            int b = 0;
            while(a < cycles[i].size() && b < cycles[j].size()){
                int dd = sorted_cycles[i][a] - sorted_cycles[j][b];
                int d = abs(dd);
                if(d < md){
                    md = d;
                    p = {sorted_cycles[i][a], sorted_cycles[j][b]};
                }
                if(dd < 0){
                    a++;
                }else{
                    b++;
                }
            }
            min_dist[i][j] = min_dist[j][i] = md;
            pairs[i][j] = pairs[j][i] = p;
        }
    }

    debug(min_dist);
    
    vpii mst_edges;
    vector<pair<int, pii>> edge_pairs;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            edge_pairs.push_back({min_dist[i][j], {i, j}});
        }
    }
    vi parent(n);
    iota(parent.begin(), parent.end(), 0);
    sort(edge_pairs.begin(), edge_pairs.end());
    // debug
    ll total_weight = 0;
    for(auto pair : edge_pairs){
        int weight;
        pii edge;
        tie(weight, edge) = pair;
        if(find_par(parent, edge.first) != find_par(parent, edge.second)){
            merge(parent, edge.first, edge.second);
            total_weight += weight;
            mst_edges.push_back(edge);
        }
    }
    total_weight *= 2;
    debug(total_weight, mst_edges);
    
    // build cycle
    vi nxt = invp;
    for(pii e : mst_edges){
        pii pair = pairs[e.first][e.second];
        debug(pair);
        // nxt[pair.first] = invp[pair.second];
        // nxt[pair.second] = invp[pair.first];
        swap(nxt[pair.first], nxt[pair.second]);
    }
    debug(nxt);
    
    int cur = 0;
    for(int i = 0; i < n; i++){
        cout << cur+1 << ' ';
        cur = nxt[cur];
    }
    cout << endl;
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