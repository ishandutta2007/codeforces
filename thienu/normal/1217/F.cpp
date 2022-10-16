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

const int B = 350;

struct Query{
    int t, x, y, e0, e1;
    Query(int _t, int _x, int _y) : t(_t), x(_x), y(_y) {}
};

const int BUF = 1e7;

int par[BUF];
int sz[BUF];
int* where[BUF];
int val[BUF];
int cnt = 0;

int find_par(int u){
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

void merge(int a, int b){
    a = find_par(a), b = find_par(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int find_par_reversible(int u){
    if(par[u] == u) return u;
    return find_par_reversible(par[u]);
}

void merge_reversible(int a, int b){
    a = find_par_reversible(a), b = find_par_reversible(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    where[cnt] = &sz[a];
    val[cnt++] = sz[a];
    where[cnt] = &par[b];
    val[cnt++] = par[b];
    sz[a] += sz[b];
    par[b] = a;
}

vpii edges;
map<pii, int> lookup;

int get_edge(pii e){
    if(lookup.count(e) == 0){
        int k = edges.size();
        edges.push_back(e);
        lookup[e] = k;
    }
    return lookup[e];
}

void solve(){
    int n, q;
    cin >> n >> q;
    
    vector<Query> queries;
    for(int i = 0; i < q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        queries.push_back(Query(t, x, y));
        if(t == 1){
            pii e0 = (x < y ? make_pair(x, y) : make_pair(y, x));
            queries[i].e0 = get_edge(e0);
            x = (x+1)%n;
            y = (y+1)%n;
            pii e1 = (x < y ? make_pair(x, y) : make_pair(y, x));
            queries[i].e1 = get_edge(e1);
        }
    }
    vi ans;

    int m = edges.size();

    int last = 0;
    vi history(q);
    for(int i = 0; i < q; i+=B){
        debug("recalc");
        int start = i, end = min(q, i+B);
        // recalc dsu
        cnt = 0;
        for(int j = 0; j < n; j++){
            par[j] = j;
            sz[j] = 1;
        }
        vi state(m), dyn(m);
        for(int j = 0; j < i; j++){
            if(queries[j].t == 1){
                int e = history[j] ? queries[j].e1 : queries[j].e0;
                debug("toggle", e);
                state[e] ^= 1;
            }
        }
        for(int j = start; j < end; j++){
            if(queries[j].t == 1){
                dyn[queries[j].e0] = dyn[queries[j].e1] = true;
            }
        }
        vi cur;
        for(int j = 0; j < i; j++){
            if(queries[j].t == 1){
                int e = (history[j] ? queries[j].e1 : queries[j].e0);
                if(!dyn[e] && state[e]){
                    merge(edges[e].first, edges[e].second);
                    state[e] = false;
                }
                else if(dyn[e] && state[e]){
                    cur.push_back(e);
                    state[e] = false;
                }
            }
        }
        debug(cur);
        debug("process");


        // process queries
        for(int j = start; j < end; j++){
            debug(i, cur);
            history[j] = last;

            int x = (queries[j].x + last) % n;
            int y = (queries[j].y + last) % n;
            if(x > y) swap(x, y);

            if(queries[j].t == 1){
                // rollback
                while(cnt > 0){
                    *where[cnt-1] = val[cnt-1];
                    cnt--;
                }
                debug(par[0], par[1], sz[0], sz[1]);
                int e = get_edge({x, y});
                auto it = find(cur.begin(), cur.end(), e);
                if(it == cur.end()){
                    debug("add", e);
                    cur.push_back(e);
                }else{
                    debug("remove", e);
                    cur.erase(it);
                }
            }else{
                debug(cur);
                for(int e : cur){
                    merge_reversible(edges[e].first, edges[e].second);
                }
                debug(x, y, find_par_reversible(x), find_par_reversible(y));
                int connected = (find_par_reversible(x) == find_par_reversible(y));
                last = connected;
                ans.push_back(last);
            }
        }
    }
    for(int i : ans){
        cout << i;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}