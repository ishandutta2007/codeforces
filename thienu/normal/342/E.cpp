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

// https://codeforces.com/contest/342/problem/E
// batch sqrt-decomp

vvi adj;
int INF = 1e9 + 7;
int BATCH_SIZE = 300;
// int BATCH_SIZE = 1;

void traverse(int u, int last, int cur_depth, vi &traversal, vi &depth, vi &traversal_idx, vi &distance_from_root){
    traversal_idx[u] = traversal.size();
    traversal.push_back(u);
    depth.push_back(cur_depth);
    distance_from_root[u] = cur_depth;
    for(int v : adj[u]){
        if(v == last) continue;
        traverse(v, u, cur_depth + 1, traversal, depth, traversal_idx, distance_from_root);
        traversal.push_back(u);
        depth.push_back(cur_depth);
    }
}

void st_build(vi &st, vi &min_idx_st, vi &v, int tl, int tr, int pos){
    if(tl == tr){
        st[pos] = v[tl];
        min_idx_st[pos] = tl;
        return;
    }
    st_build(st, min_idx_st, v, tl, tl + (tr - tl) / 2, pos * 2);
    st_build(st, min_idx_st, v, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1);
    st[pos] = min(st[2 * pos], st[2 * pos + 1]);
    if(st[2 * pos] <= st[2 * pos + 1]){
        min_idx_st[pos] = min_idx_st[2 * pos];
    }
    else{
        min_idx_st[pos] = min_idx_st[2 * pos + 1];
    }
}

// returns pair {min, idx}
pii st_min(vi &st, vi &min_idx_st, int tl, int tr, int pos, int left, int right){
    if(left <= tl && tr <= right){
        return {st[pos], min_idx_st[pos]};
    }
    if(tr < left || right < tl){
        return {INF, -1};
    }
    int x, y, ix, iy;
    tie(x, ix) = st_min(st, min_idx_st, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    tie(y, iy) = st_min(st, min_idx_st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    if(x < y){
        debug(tl, tr, ix, left, right);
        return {x, ix};
    }
    else{
        debug(tl, tr, iy, left, right);
        return {y, iy};
    }
}

int lca(vi &st, vi &min_idx_st, vi &traversal, vi &traversal_idx, int u, int v){
    int x, ix;
    int a = traversal_idx[u];
    int b = traversal_idx[v];
    tie(x, ix) = st_min(st, min_idx_st, 0, traversal.size() - 1, 1, min(a, b), max(a, b));
    // debug(ix, traversal_idx[u], traversal_idx[v]);
    debug(x, ix);
    return traversal[ix];
}

int dist(int u, int v, vi &st, vi &min_idx_st, vi &traversal, vi &traversal_idx, vi &distance_from_root){
    int x = lca(st, min_idx_st, traversal, traversal_idx, u, v);
    debug(u, v, x);
    return distance_from_root[u] + distance_from_root[v] - 2 * distance_from_root[x];
}

void solve(){
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // precompute lengths
    // lca
    vi traversal, depth, distance_from_root(n);
    vi traversal_idx(n, -1);
    traverse(0, -1, 0, traversal, depth, traversal_idx, distance_from_root);
    debug(traversal, depth, traversal_idx, distance_from_root);

    vi st(8 * n);
    vi min_idx_st(8 * n);
    st_build(st, min_idx_st, depth, 0, traversal.size() - 1, 1);

    // debug(lca(st, traversal, traversal_idx, 2, 4));
    // debug(dist(2, 4, st, traversal, traversal_idx, distance_from_root));
    // debug(dist(0, 1, st, traversal, traversal_idx, distance_from_root));
    // debug(lca(st, traversal, traversal_idx, 0, 1));

    int batch_num = 0;
    vi distances(n, INF);
    vi points;
    vi all_points;
    all_points.push_back(0);
    points.push_back(0);
    for(int j = 0; j < m; j++){
        debug(j);
        // cout << 'a';
        // batch
        if(batch_num == BATCH_SIZE){
            // bfs
            fill(distances.begin(), distances.end(), INF);
            queue<int> q;
            vi vis(n);
            for(int i : all_points){
                distances[i] = 0;
                q.push(i);
                vis[i] = 1;
            }
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : adj[u]){
                    if(!vis[v]){
                        vis[v] = 1;
                        distances[v] = distances[u] + 1;
                        q.push(v);
                    }
                }
            }

            // clear vars for next batch
            points.clear();
            batch_num = 0;
        }
        // process query
        int x, y;
        cin >> x >> y;
        y--;
        if(x == 1){
            points.push_back(y);
            all_points.push_back(y);
        }
        else{
            int ans = distances[y];
            for(int p : points){
                ans = min(ans, dist(p, y, st, min_idx_st, traversal, traversal_idx, distance_from_root));
            }
            cout << ans << endl;
        }

        // cout << 'b';

        batch_num++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}