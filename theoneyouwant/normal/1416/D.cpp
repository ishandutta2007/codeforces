//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
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
const int LIM=5e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Segtree{

    vp32 t;

    Segtree(int n) {
        t.assign(4*n, mp(0,0));
    }

    void build(int a[], int v, int tl, int tr){
        if(tl == tr){
            t[v] = mp(a[tl], tl);
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int addend){
        if(l > r){
            return;
        }
        if(l <= tl && tr <= r){
            t[v].fi = addend;
        } else {
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    p32 query(int v, int tl, int tr, int l, int r) {
        if(l>r) return mp(0,0);
        if(l <= tl && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};

int in[LIM], out[LIM];
v32 adj[LIM];
bool visited[LIM];
int t = 0;

void dfs(int node){
    in[node] = t++;
    visited[node] = 1;
    forstl(r,adj[node]){
        if(visited[r]) continue;
        dfs(r);
    }
    out[node] = t;
}

struct DSU{
    int link[LIM], sz[LIM];
    int lmin[LIM], rmax[LIM];

    DSU(int n){
        forn(i,n){
            link[i] = i;
            sz[i] = 1;
            lmin[i] = in[i];
            rmax[i] = out[i];
        }
    }

    int find(int x){
        if(x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        sz[a] += sz[b];
        link[b] = a;
        lmin[a] = min(lmin[a], lmin[b]);
        rmax[a] = max(rmax[a], rmax[b]);
    }
};




int main(){
	fastio;

	int n, m, q;
    cin>>n>>m>>q;

    int p[n];
    forn(i,n) cin>>p[i];
    vp32 edges;

    forn(i,m){
        int a, b;
        cin>>a>>b;
        a--; b--;
        edges.pb(mp(a,b));
    }

    vp32 queries;
    vp32 edgeord;

    bool marked[m] = {0};

    forn(i,q){
        int type, v;
        cin>>type>>v;
        v--;
        if(type == 2){
            marked[v] = 1;
            edgeord.pb(edges[v]);
        }
        queries.pb(mp(type, v));
    }

    forn(i,m){
        if(marked[i] == 0) {
            edgeord.pb(edges[i]);
            queries.pb(mp(2, i));
        }
    }

    reverse(edgeord.begin(), edgeord.end());
    reverse(queries.begin(), queries.end());
    
    DSU getTree(2*n);
    int cnt = n;

    forstl(r,edgeord){
        int a = getTree.find(r.fi), b = getTree.find(r.se);
        if(a == b) continue;
        int c = cnt;
        cnt++;
        adj[a].pb(c);
        adj[c].pb(a);
        getTree.unite(c, a);
        adj[b].pb(c);
        adj[c].pb(b);
        getTree.unite(c, b);
    }

    forn(i,n){
        if(!visited[i]){
            int par = getTree.find(i);
            dfs(par);
        }
    }

    DSU maintainFin(2*n);
    Segtree s(cnt);
    cnt = n;
    int giveVal[2*n] = {0};
    forn(i,n){
        giveVal[in[i]] = p[i];
    }
    s.build(giveVal,1,0,2*n-1);
    vp32 would_see;

    stack<int> ans;

    forstl(r,queries){
        // cout<<r<<ln;
        if(r.fi == 1){
            int ver = r.se;
            ver = maintainFin.find(ver);
            // cout<<r.se<<" my parent is "<<ver<<ln;
            would_see.pb(mp(maintainFin.lmin[ver], maintainFin.rmax[ver]));
            // p32 val = s.query(1, 0, 2*n-1, maintainFin.lmin[ver], maintainFin.rmax[ver]-1);
            // ans.push(val.fi);
            // s.update(1, 0, 2*n-1, val.se, val.se, 0);
        }
        else{
            int a = maintainFin.find(edges[r.se].fi), b = maintainFin.find(edges[r.se].se);
            if(a == b) continue;
            int c = cnt;
            cnt++;
            maintainFin.unite(c, a);
            maintainFin.unite(c, b);
        }
    }

    reverse(all(would_see));

    forstl(r,would_see){
        // cout<<r<<ln;
        p32 val = s.query(1, 0, 2*n-1, r.fi, r.se-1);
        cout<<val.fi<<ln;
        s.update(1, 0, 2*n-1, val.se, val.se, 0);
    }

    // while(!ans.empty()){
    //     cout<<ans.top()<<ln;
    //     ans.pop();
    // }


	return 0;
}