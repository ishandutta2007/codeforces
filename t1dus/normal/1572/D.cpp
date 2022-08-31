// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/ 
// -------------------</optimizations>--------------------
 
// ---------------<Headers and namespaces>----------------
#include <bits/stdc++.h>
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
 
// ---------------</Headers and namespaces>---------------
 
// -----------------<Defines and typedefs>----------------
// typedef tree<int,null_type,less<int>,rb_tree_tag, 
// tree_order_statistics_node_update> indexed_set; // use less_equal for multiset
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
typedef long double LD;
typedef long long ll;
// #define int ll
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
 
/*
// -----<SCANF>-----
#define sfi(x) scanf("%d",&x);
#define sfi2(x,y) scanf("%d%d",&x,&y);
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z);
 
#define sfl(x) scanf("%lld",&x);
#define sfl2(x,y) scanf("%lld%lld",&x,&y);
#define sfl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
#define sfl4(x,y,z,x1) scanf("%lld%lld%lld%lld",&x,&y,&z,&x1);
#define sfl5(x,y,z,x1,y1) scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1);
#define sfl6(x,y,z,x1,y1,z1) scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1,&z1);
 
#define sfs(x) scanf("%s",x);
#define sfs2(x,y) scanf("%s%s",x,y);
#define sfs3(x,y,z) scanf("%s%s%s",x,y,z);
// ----</SCANF>-----
 
// ----<PRINTF>-----
#define pfi(x) printf("%d\n",x);
#define pfi2(x,y) printf("%d %d\n",x,y);
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z);
 
#define pfl(x) printf("%lld\n",x);
#define pfl2(x,y) printf("%lld %lld\n",x,y);
#define pfl3(x,y,z) printf("%lld %lld %lld\n",x,y,z);
 
#define pfs(x) printf("%s\n",x);
#define pfs2(x,y) printf("%s %s\n",x,y);
#define pfs3(x,y,z) printf("%s %s %s\n",x,y,z);
 
#define pwe(x) printf("%lld ",x); // print without end
// ----</PRINTF>----
*/
#define FLSH fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x) cout << fixed << setprecision(x); 
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
// ----------------</Defines and typedefs>----------------
 
// -------------------<Debugging stuff>-------------------
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
// ------------------</Debugging stuff>-------------------
 
// ------------------------<Consts>-----------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
 
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
#endif
 
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------------</Consts>-----------------------

// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.
 
// ------------------------</RNG>-------------------------
 
// ----------------------<MATH>---------------------------
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int add(int a, int b, int c = MOD){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c = MOD){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;return(res>=c?res%c:res);}
int muln(int a, int b, int c = MOD){ll res=(ll)a*b;return ((res%c)+c)%c;}
ll mulmod(ll a,ll b, ll m = MOD){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
 
const int FACSZ = 1; // Make sure to change this
 
int fact[FACSZ],ifact[FACSZ];
 
void precom(int c = MOD){
    fact[0] = 1;
    FOR(i,1,FACSZ) fact[i] = mul(fact[i-1],i,c);
    ifact[FACSZ-1] = mod_inverse(fact[FACSZ-1],c);
    REPD(i,FACSZ-1){
        ifact[i] = mul(i+1,ifact[i+1],c);
    }
}
 
int ncr(int n,int r,int c = MOD){
    if(r > n) return 0;
    return mul(mul(ifact[r],ifact[n-r],c),fact[n],c);
} 

// ----------------------</MATH>--------------------------
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
 
void solvethetestcase();
 
signed main(){
    // comment when using scanf,printf
    FAST_IO
    int t = 1;
    // (UNCOMMENT FOR MULTIPLE TEST CASES)
    // cin >> t;
    FOR(testcase,1,t+1){
        // (UNCOMMENT FOR CODEJAM)
        // printf("Case #%lld: ",testcase); 
        solvethetestcase();
    }
}

struct edge
{
    int to, flow, cap, cost, rev;
};

struct MinCostMaxFlow
{
    int nodes;
    vector<int> prio, curflow, prevedge, prevnode, q, pot;
    vector<bool> inqueue;
    vector<vector<edge> > graph;
    MinCostMaxFlow() {}

    MinCostMaxFlow(int n): nodes(n), prio(n, 0), curflow(n, 0),
    prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

    void add_edge(int source, int to, int capacity, int cost)
    {
        edge a = {to, 0, capacity, cost, (int)graph[to].size()};
        edge b = {source, 0, 0, -cost, (int)graph[source].size()};
        graph[source].push_back(a);
        graph[to].push_back(b);
    }

    void bellman_ford(int source, vector<int> &dist)
    {
        fill(dist.begin(), dist.end(), INT_MAX);
        dist[source] = 0;
        int qt=0;
        q[qt++] = source;
        for(int qh=0;(qh-qt)%nodes!=0;qh++)
        {
            int u = q[qh%nodes];
            inqueue[u] = false;
            for(auto &e : graph[u])
            {
                if(e.flow >= e.cap)
                    continue;
                int v = e.to;
                int newDist = dist[u] + e.cost;
                if(dist[v] > newDist)
                {
                    dist[v] = newDist;
                    if(!inqueue[v])
                    {
                        inqueue[v] = true;
                        q[qt++ % nodes] = v;
                    }
                }
            }
        }
    }

    pair<int, int> minCostFlow(int source, int dest, int maxflow)
    {
        bellman_ford(source, pot);
        int flow = 0;
        int flow_cost = 0;
        while(flow < maxflow)
        {
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
            q.push({0, source});
            fill(prio.begin(), prio.end(), INT_MAX);
            prio[source] = 0;
            curflow[source] = INT_MAX;
            while(!q.empty())
            {
                int d = q.top().first;
                int u = q.top().second;
                q.pop();
                if(d != prio[u])
                    continue;
                for(int i=0;i<graph[u].size();i++)
                {
                    edge &e=graph[u][i];
                    int v = e.to;
                    if(e.flow >= e.cap)
                        continue;
                    int newPrio = prio[u] + e.cost + pot[u] - pot[v];
                    if(prio[v] > newPrio)
                    {
                        prio[v] = newPrio;
                        q.push({newPrio, v});
                        prevnode[v] = u;
                        prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.flow);
                    }
                }
            }
            if(prio[dest] == INT_MAX)
                break;
            for(int i=0;i<nodes;i++)
                pot[i]+=prio[i];
            int df = min(curflow[dest], maxflow - flow);
            flow += df;
            for(int v=dest;v!=source;v=prevnode[v])
            {
                edge &e = graph[prevnode[v]][prevedge[v]];
                e.flow += df;
                graph[v][e.rev].flow -= df;
                flow_cost += df * e.cost;
            }
        }
        return {flow, flow_cost};
    }
};
int n,k;
int a[(1<<20)+5];
 
void solvethetestcase(){
    cin >> n >> k;
    REP(i,(1<<n)) cin >> a[i];
    vector<pair<int,pii> > edges;
    int source0 = 0;
    int source1 = 1;
    int sink = 2;
    REP(i,(1<<n)){
        if(__builtin_popcount(i)%2 == 0){
            REP(j,n){
                int u = i;
                int v = (i^(1<<j));
                int w = a[u]+a[v];
                edges.pb({-w,{u,v}});
            }
        }
    }
    int tot = min(SZ(edges),(2*n-1)*(k-1)+1);
    nth_element(edges.begin(),edges.begin()+tot-1,edges.end());
    mii gg;
    int cur = 3;
    for(auto x:edges){
        if(x <= edges[tot-1]){
            if(!gg.count(x.S.F)) gg[x.S.F] = cur++;
            if(!gg.count(x.S.S)) gg[x.S.S] = cur++;
        }
    }
    assert(cur <= 2*n*k*2+5);
    MinCostMaxFlow network(cur);
    network.add_edge(source0,source1,k,0);
    REP(i,(1<<n)){
        if(__builtin_popcount(i)%2 == 0){
            if(gg.count(i)) network.add_edge(source1,gg[i],1,0);
        }
        else{
            if(gg.count(i)) network.add_edge(gg[i],sink,1,0);
        }
    }
    for(auto x:edges){
        if(x <= edges[tot-1]){
            network.add_edge(gg[x.S.F],gg[x.S.S],1,x.F);
        }
    }
    int ans = network.minCostFlow(source0,sink,k).S;
    cout << -ans << "\n";
}