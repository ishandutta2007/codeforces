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

vi traversal;
vvi adj;
vi first_index;
vi last_index;
vi color;
int cnt = 0;
vll st;
vll lazy;

void traverse(int v, int last, int c){
    debug(v, c);
    color[v] = c;
    traversal.push_back(v);
    first_index[v] = cnt;
    last_index[v] = cnt;
    cnt++;
    for(int u : adj[v]){
        if(u == last) continue;
        traverse(u, v, -c);
        traversal.push_back(v);
        last_index[v] = cnt;
        cnt++;
    }
}

void st_build(int tl, int tr, int pos, vll &v){
    if(tl == tr){
        // debug(tl, pos, color[tl]);
        st[pos] = v[traversal[tl]] * color[traversal[tl]];
        return;
    }
    st_build(tl, tl + (tr - tl) / 2, pos * 2, v);
    st_build(tl + (tr - tl) / 2 + 1, tr, 2 * pos + 1, v);
    st[pos] = st[2 * pos] + st[2 * pos + 1];
}

void st_add(int tl, int tr, int pos, int left, int right, int add_amt){
    if(tr < left || right < tl) return;
    if(left <= tl && tr <= right){
        lazy[pos] += add_amt;
        return;
    }
    st_add(tl, tl + (tr - tl) / 2, pos * 2, left, right, add_amt);
    st_add(tl + (tr - tl) / 2 + 1, tr, 2 * pos + 1, left, right, add_amt);
}

ll st_get(int tl, int tr, int pos, int p){
    debug(tl, tr, pos, p);
    if(p < tl || tr < p) return -1;
    if(tl == tr){
        debug(pos);
        st[pos] += lazy[pos];
        lazy[pos] = 0;
        return st[pos];
    }
    // push lazy
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;
    if(p <= tl + (tr - tl) / 2){
        return st_get(tl, tl + (tr - tl) / 2, 2 * pos, p);
    }
    else{
        return st_get(tl + (tr - tl) / 2 + 1, tr, 2 * pos + 1, p);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    adj.resize(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    first_index.resize(n);
    last_index.resize(n);
    color.resize(n);
    traverse(0, -1, 1);
    debug(traversal, first_index, last_index, color);
    int traversal_size = traversal.size();
    st.resize(4 * traversal_size);
    lazy.resize(4 * traversal_size);
    st_build(0, traversal_size-1, 1, v);
    debug(st);

    while(m--){
        int x;
        cin >> x;
        if(x == 1){
            int u, val;
            cin >> u >> val;
            u--;
            int node_color = color[u];
            st_add(0, traversal_size-1, 1, first_index[u], last_index[u], node_color * val);
        }
        else{
            int u;
            cin >> u;
            u--;
            int node_color = color[u];
            debug(first_index[u], st, lazy);
            cout << st_get(0, traversal_size-1, 1, first_index[u]) * node_color << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}