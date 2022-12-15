//By TheOneYouWant

#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
    c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;

const int LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;
// int t,n,m,k,x,y,w;

const int MAXN = 100050;
const int LOGN = 17;
int par[LOGN][MAXN];   // par[i][v]: (2^i)th ancestor of v            
int level[MAXN], sub[MAXN];        // sub[v]: size of subtree whose root is v
int ctPar[MAXN];                // ctPar[v]: parent of v in centroid tree
set<int> adj[MAXN];
int n;
int ans[MAXN];        
// ans[v]: shortest distance between v and red nodes in subtree corresponding to centroid v

// calculate level by dfs
void dfsLevel(int node, int pnode) {
    for(auto cnode : adj[node]) {
        if(cnode != pnode) {
            par[0][cnode] = node;
            level[cnode] = level[node] + 1;
            dfsLevel(cnode, node);
        }
    }
}

void preprocess() {
    level[0] = 0;
    par[0][0] = 0;
    dfsLevel(0, -1);

    for(int i = 1; i < LOGN; i++) {
        for(int node = 0; node < n; node++) {
            par[i][node] = par[i-1][par[i-1][node]];
        }
    }
}

int lca(int u, int v) {
    if(level[u] > level[v]) swap(u, v);
    int d = level[v] - level[u];

    // make u, v same level
    for(int i = 0; i < LOGN; i++) {
        if(d & (1 << i)) {
            v = par[i][v];
        }
    }

    if(u == v) return u;

    // find LCA
    for(int i = LOGN - 1; i >= 0; i--) {
        if(par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}


/* Centroid decomposition */
// Calculate size of subtrees by dfs
void dfsSubtree(int node, int pnode) {
    sub[node] = 1;
    for(auto cnode : adj[node]) {
        if(cnode != pnode) {
            dfsSubtree(cnode, node);
            sub[node] += sub[cnode];
        }
    }
}

// find Centroid
int dfsCentroid(int node, int pnode, int size) {
    for(auto cnode : adj[node]) {
        if(cnode != pnode && sub[cnode] > size / 2)
            return dfsCentroid(cnode, node, size);
    }
    return node;
}

// Centroid decomposition
void decompose(int node, int pCtr, int depth) {
    dfsSubtree(node, -1);
    int ctr = dfsCentroid(node, node, sub[node]);
    if(pCtr == -1)
        pCtr = ctr;    // root of centroid tree
    ctPar[ctr] = pCtr;
    ans[ctr] = depth;
    for(auto cnode : adj[ctr]) {
        adj[cnode].erase(ctr);
        decompose(cnode, ctr, depth+1);
    }
    adj[ctr].clear();
}


signed main(){
    fastio;

    cin>>n;

    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    preprocess();
    decompose(0,-1,0);
    forn(i,n){
        cout<<(char)('A'+ans[i])<<" ";
    }
    cout<<ln;

    return 0;
}