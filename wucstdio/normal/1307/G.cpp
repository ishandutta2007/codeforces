#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;


template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<class T> T poll(pqg<T>& x) {
    T y = x.top(); x.pop();
    return y;
}

template<int SZ> struct mcf
{
    struct Edge { int v, rev; ll flow, cap, cost; };

    vector<Edge> adj[SZ];

    void addEdge(int u, int v, ll cap, ll cost)
	{
        Edge a{v, sz(adj[v]), 0, cap, cost}, b{u, sz(adj[u]), 0, 0, -cost};
        adj[u].pb(a), adj[v].pb(b);
    }

    int ST, EN;
    pi pre[SZ];
    pl cost[SZ];
    ll totFlow, totCost, curCost;

    void reweight()
	{
    	F0R(i,SZ) trav(p,adj[i]) p.cost += cost[i].f-cost[p.v].f;
    }

    bool spfa()
	{
        F0R(i,SZ) cost[i] = {INF,0};
        cost[ST] = {0,INF};
        pqg<pair<ll,int>> todo; todo.push({0,ST});
        while (sz(todo))
		{
            auto x = poll(todo); if (x.f > cost[x.s].f) continue;
            trav(a,adj[x.s]) if (x.f+a.cost < cost[a.v].f && a.flow < a.cap)
			{
                pre[a.v] = {x.s,a.rev};
                cost[a.v] = {x.f+a.cost, min(a.cap-a.flow,cost[x.s].s)};
                todo.push({cost[a.v].f,a.v});
            }
        }

        curCost += cost[EN].f; return cost[EN].s;
    }

    void backtrack()
	{
        auto f=1;
		totFlow+=f;
		totCost+=curCost*f;
        for (int x = EN; x != ST; x = pre[x].f)
		{
            adj[x][pre[x].s].flow -= f;
            adj[pre[x].f][adj[x][pre[x].s].rev].flow += f;
        }
    }
};
mcf<201> m;
int N,M,q,s,t;
double ans[200005],x[200005];
int main()
{
	scanf("%d%d",&N,&M);
    s=1,t=N;
    for(int i=1;i<=M;i++)
	{
    	int u,v,d;
    	scanf("%d%d%d",&u,&v,&d);
    	m.addEdge(u,v,1,d);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)ans[i]=INF;
    for(int i=1;i<=q;i++)scanf("%lf",&x[i]);
    m.ST=s,m.EN=t;
    m.totFlow=m.totCost=m.curCost=0;
    m.spfa();
    while(1)
	{
        m.reweight();
        if(!m.spfa())break;
        m.backtrack();
        for(int i=1;i<=q;i++)
          ckmin(ans[i],(double)(m.totCost+x[i])/m.totFlow);
    }
    for(int i=1;i<=q;i++)printf("%.12lf\n",ans[i]);
    return 0;
}