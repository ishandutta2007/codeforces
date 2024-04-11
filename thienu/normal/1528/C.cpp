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

struct Tree{
    vvi child;
    vi parent;
    int n;

    Tree(int n){
        child.resize(n);
        parent.resize(n, -1);
    }

    void add_edge(int from, int to){
        child[from].push_back(to);
        parent[to] = from;
    }
};

void traverse(Tree &t, vi &traversal, int u){
    traversal.push_back(u);
    for(int v : t.child[u]){
        traverse(t, traversal, v);
        traversal.push_back(u);
    }
}

// void st_init(vi &st, int tl, int tr, int pos, vi &v){
//     if(tl == tr){
//         st[pos] = v[tl];
//         return;
//     }
//     st_init(st, tl, tl + (tr - tl) / 2, pos * 2, v);
//     st_init(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, v);
// }

void st_set(vi &st, int tl, int tr, int pos, int left, int right, int val){
    // debug("set", tl, tr, pos, left, right);
    if(left <= tl && tr <= right){
        debug("set to val");
        st[pos] = val;
        return;
    }
    if(tr < left || right < tl){
        return;
    }
    // propogate, -2 is do not propogate
    if(st[pos] != -2){
        st[2 * pos] = st[pos];
        st[2 * pos + 1] = st[pos];
        st[pos] = -2;
    }
    st_set(st, tl, tl + (tr - tl) / 2, pos * 2, left, right, val);
    st_set(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right, val);
}

int st_get(vi &st, int tl, int tr, int pos, int idx){
    // debug(tl, tr, pos, st[pos]);
    if(tl == tr){
        return st[pos] == -2 ? -1 : st[pos];
    }
    if(st[pos] != -2){
        return st[pos];
    }
    if(tl + (tr - tl) / 2 >= idx){
        return st_get(st, tl, tl + (tr - tl) / 2, pos * 2, idx);
    }
    else{
        return st_get(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, idx);
    }
}

// dfs on s
void dfs(Tree &s, Tree &t, int u, int sz, vi &st, int tt_size, vi &t_traversal, vi &tt_first, vi &tt_last, vi &ans){
    // get answer
    int ancestor = st_get(st, 0, tt_size - 1, 1, tt_first[u]);
    debug(u, ancestor);
    if(ancestor == -1){
        // can add
        ans[u] = sz + 1;
    }
    else{
        ans[u] = sz;
    }
    // update ancestry for children
    if(ancestor != -1){
        st_set(st, 0, tt_size - 1, 1, tt_first[ancestor], tt_last[ancestor], -1);
    }
    st_set(st, 0, tt_size - 1, 1, tt_first[u], tt_last[u], u);

    // start dfs
    for(int v : s.child[u]){
        dfs(s, t, v, ans[u], st, tt_size, t_traversal, tt_first, tt_last, ans);
    }

    // undo update ancestry
    st_set(st, 0, tt_size - 1, 1, tt_first[u], tt_last[u], -1);
    if(ancestor != -1){
        st_set(st, 0, tt_size - 1, 1, tt_first[ancestor], tt_last[ancestor], ancestor);
    }
}

void solve(){
    int n;
    cin >> n;
    Tree s(n);
    Tree t(n);
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        s.add_edge(x, i);
    }
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        t.add_edge(x, i);
    }
    
    vi t_traversal;
    traverse(t, t_traversal, 0);
    debug(t_traversal);

    int tt_size = t_traversal.size();

    vi tt_first(n), tt_last(n);
    for(int i = tt_size - 1; i >= 0; i--){
        tt_first[t_traversal[i]] = i;
    }
    for(int i = 0; i < tt_size; i++){
        tt_last[t_traversal[i]] = i;
    }
    debug(tt_first, tt_last);
    
    vi st(4 * tt_size, -2);
    vi ans(n);
    dfs(s, t, 0, 0, st, tt_size, t_traversal, tt_first, tt_last, ans);

    debug(ans);
    int out = 0;
    for(int i = 0; i < n; i++){
        out = max(out, ans[i]);
    }
    cout << out << endl;
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