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

vi cnt;
vi val;
vvi adj;

vi sz;
vi mark;
vi mark_up;

vi traversal;
vi lo, hi;

void dfs1(int u, int last){
    int s = 1;
    for(int &v : adj[u]){
        if(v == last) continue;
        dfs1(v, u);
        s += sz[v];
        if(sz[v] > sz[adj[u][0]]){
            swap(v, adj[u][0]);
        }
    }
    sz[u] = s;
}

vector<set<int>> sing;
vector<set<int>> doub;

bool ok = true;

void dfs2(int u, int last){
    debug(u);
    lo[u] = traversal.size();
    traversal.push_back(u);
    vi branches;
    for(int v : adj[u]){
        if(v == last) continue;
        dfs2(v, u);
        if(v == adj[u][0]){
            swap(sing[u], sing[v]);
            swap(doub[u], doub[v]);
            if(sing[u].find(val[u]) != sing[u].end()){
                branches.push_back(v);
            }
        }else{
            for(int i : doub[v]){
                if(cnt[i] == 1) continue;
                if(doub[u].find(i) == doub[u].end() && sing[u].find(i) == sing[u].end()){
                    doub[u].insert(i);
                }
                else ok = false;
            }
            for(int i : sing[v]){
                if(cnt[i] == 1) continue;
                if(i == val[u]){
                    branches.push_back(v);
                }
                if(doub[u].find(i) == doub[u].end()){
                    if(sing[u].find(i) == sing[u].end()){
                        // mark[u] = 1;
                        sing[u].insert(i);
                    }
                }
                else ok = false;
            }
        }
    }
    hi[u] = traversal.size();
    if(cnt[val[u]] == 1) return;
    debug(u, val[u]);
    if(doub[u].find(val[u]) != doub[u].end()){
        ok = false;
    }else if(sing[u].find(val[u]) != sing[u].end()){
        if(branches.size() > 1){
            ok = false;
        }else{
            sing[u].erase(val[u]);
            doub[u].insert(val[u]);
            mark_up[branches[0]] = 1;
        }
    }else{
        sing[u].insert(val[u]);
        mark[u] = 1;
    }
}

void solve(){
    int n;
    cin >> n;
    // compress
    map<int, int> mapping;
    set<int> taken;
    int cur = 0;
    val.resize(n);
    cnt.resize(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(taken.find(x) == taken.end()){
            taken.insert(x);
            mapping[x] = cur++;
        }
        val[i] = mapping[x];
        cnt[val[i]]++;
    }
    debug(val);

    adj.resize(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sz.resize(n);
    dfs1(0, -1);
    debug(sz);

    mark.resize(n);
    mark_up.resize(n);
    sing.resize(n);
    doub.resize(n);
    lo.resize(n);
    hi.resize(n);
    dfs2(0, -1);

    debug(ok, mark, mark_up);
    debug(sing);
    debug(doub);

    if(!ok){
        cout << 0 << endl;
        return;
    }
    debug(traversal, lo, hi);

    vi diff(n+1);
    for(int i = 0; i < n; i++){
        if(mark[i] == 1){
            diff[lo[i]]++;
            diff[hi[i]]--;
        }
        if(mark_up[i] == 1){
            diff[0]++;
            diff[n]--;
            diff[lo[i]]--;
            diff[hi[i]]++;
        }
    }
    debug(diff);

    vi bad(n);
    bad[0] = diff[0];
    int ans = 0;
    for(int i = 1; i < n; i++){
        bad[i] = diff[i] + bad[i-1];
    }
    debug(bad);
    for(int i = 0; i < n; i++){
        if(bad[i] == 0){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}