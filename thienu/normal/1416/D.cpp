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

vi par, sz, rightmost, leftmost, group;

int find_par(int u){
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

// merge u (left) and v (right)
bool merge(int u, int v, int grp){
    debug(par, sz, rightmost, leftmost, group);
    u = find_par(u);
    v = find_par(v);
    if(u == v) return false;
    int rg = rightmost[v];
    int lf = leftmost[u];
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    rightmost[u] = rg;
    leftmost[u] = lf;
    group[u] = grp;
    return true;
}

struct Node{
    Node *l = 0, *r = 0;
    int idx;
    Node(int idx) : idx(idx) {}
};

struct SegTree{
    int n;
    vi v;
    vi midx;
    SegTree(int n) : n(n) {
        v.resize(2*n);
        midx.resize(2*n);
        for(int i = 0; i < n; i++){
            midx[i+n] = i;
        }
    }

    void set(int idx, int val){
        idx += n;
        v[idx] = val;
        for(; idx > 1; idx >>= 1){
            if(v[idx] > v[idx^1]){
                v[idx>>1] = v[idx];
                midx[idx>>1] = midx[idx];
            }else{
                v[idx>>1] = v[idx^1];
                midx[idx>>1] = midx[idx^1];
            }
        }
    }

    void umax(int &maxi, int &idx, int pos, int val){
        if(maxi < val){
            maxi = val;
            idx = pos;
        }
    }

    // {max, idx}
    pair<int, int> query(int l, int r){
        debug(midx, v);
        debug(l, r);
        int maxi = 0;
        int idx = l;
        for(l += n, r += n; l < r; l>>=1, r>>=1){
            if(l & 1){
                umax(maxi, idx, midx[l], v[l]);
                l++;
            }
            if(r & 1){
                r--;
                umax(maxi, idx, midx[r], v[r]);
            }
        }
        return {maxi, idx};
    }
};

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vi value(n);
    for(int i = 0; i < n; i++) cin >> value[i];
    vector<pii> edges;
    vi deleted(m);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        edges.push_back({x, y});
    }
    debug(edges);

    vi modify;
    vector<vpii> queries(m+1);
    int del = 0, cnt = 0;
    for(int i = 0; i < q; i++){
        int t, x;
        cin >> t >> x;
        x--;
        if(t == 1){
            queries[del].push_back({x, cnt++});
        }else{
            modify.push_back(x);
            deleted[x] = 1;
            del++;
        }
    }

    for(int i = 0; i < m; i++){
        if(!deleted[i]){
            modify.push_back(i);
        }
    }
    debug(queries, modify);
    
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    sz.resize(n);
    rightmost.resize(n);
    iota(rightmost.begin(), rightmost.end(), 0);
    leftmost.resize(n);
    iota(leftmost.begin(), leftmost.end(), 0);
    group.resize(n);
    iota(group.begin(), group.end(), 0);
    vector<Node*> nodes;
    for(int i = 0; i < n; i++){
        nodes.push_back(new Node(i));
    }

    debug(nodes.size());
    
    vi qleft(cnt), qright(cnt);

    for(pii p : queries[m]){
        qleft[p.second] = qright[p.second] = p.first;
    }

    debug(qleft, qright);

    int grp = n;
    for(int i = m-1; i >= 0; i--){
        int x, y;
        tie(x, y) = edges[modify[i]];
        debug(x, y);
        int lf = group[find_par(x)], rt = group[find_par(y)];
        bool res = merge(x, y, grp);
        debug(res);
        if(res){
            Node* nd = new Node(grp);
            nd->l = nodes[lf];
            nd->r = nodes[rt];
            grp++;
            nodes.push_back(nd);
        }

        for(pii p : queries[i]){
            int x = find_par(p.first);
            qleft[p.second] = leftmost[x];
            qright[p.second] = rightmost[x];
        }
    }
    debug(qleft, qright);

    vi order;
    stack<Node*> sta;
    vi vis(nodes.size());
    for(int i = nodes.size()-1; i >= 0; i--){
        if(vis[i]) continue;
        sta.push(nodes[i]);
        while(!sta.empty()){
            Node* u = sta.top();
            sta.pop();
            vis[u->idx] = 1;
            if(u->idx < n){
                order.push_back(u->idx);
            }else{
                sta.push(u->r);
                sta.push(u->l);
            }
        }
        debug(i, vis);
    }
    debug(order);

    vi lookup(n);
    for(int i = 0; i < n; i++){
        lookup[order[i]] = i;
    }

    SegTree st(n);
    for(int i = 0; i < n; i++){
        st.set(i, value[order[i]]);
    }
    for(int i = 0; i < cnt; i++){
        int maxi, idx;
        tie(maxi, idx) = st.query(lookup[qleft[i]], lookup[qright[i]]+1);
        debug(idx);
        st.set(idx, 0);
        cout << maxi << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    solve();
    return 0;
}