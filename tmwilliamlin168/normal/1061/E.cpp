#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<double> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

int co, q[2];
int n,r[2],a[501], comp[2][501], demand[2][501];
vi adj[2][501];

#define ar array
const int mxN=1002;

struct MinCostFlow {
	struct edge {
		int v, flow, C, rev, cost;
	};
	ar<int, 2> pre[mxN];
	int cost[mxN], num[mxN], flo, ans, ccost;
	int n=1002;
	vector<edge> adj[mxN];
	void addEdge(int u, int v, int C, int cost) {
		edge a{v, 0, C, adj[v].size(), cost}, b{u, 0, 0, adj[u].size(), -cost};
		adj[u].push_back(a);
		adj[v].push_back(b);
	}
	bool spfa() {
		for(int i=0; i<n; ++i) {
			cost[i]=1e9;
			num[i]=0;
		}
		cost[0]=0;
		num[0]=1e9;
		priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> todo;
		todo.push({0, 0});
		while(todo.size()) {
			ar<int, 2> x=todo.top();
			todo.pop();
			if(x[0]>cost[x[1]])
				continue;
			for(edge a : adj[x[1]]) {
				if(x[0]+a.cost>=cost[a.v]||a.flow>=a.C)
					continue;
				pre[a.v]={x[1], a.rev};
				cost[a.v]=x[0]+a.cost;
				num[a.v]=min(a.C-a.flow, num[x[1]]);
				todo.push({cost[a.v], a.v});
			}
		}
		ccost+=cost[n-1];
		return num[n-1];
	}
	ar<int, 2> flow() {
		flo=ans=ccost=0;
		spfa();
		while(1) {
			for(int i=0; i<n; ++i)
				for(edge &p : adj[i])
					p.cost+=cost[i]-cost[p.v];
			if(!spfa())
				return {flo, ans};
			flo+=num[n-1];
			ans+=num[n-1]*ccost;
			for(int x=n-1; x; x=pre[x][0]) {
				adj[x][pre[x][1]].flow-=num[n-1];
				adj[pre[x][0]][adj[x][pre[x][1]].rev].flow+=num[n-1];
			}
		}
	}
};

MinCostFlow m;

pair<int,vi> getChild(int z, int x, int p) {
    int sum = 0;
    vi v = {x};
    for (int i: adj[z][x]) if (i != p) {
        auto a = getChild(z,i,x);
        sum += a.f;
        v.insert(v.end(),all(a.s));
    }
    if (demand[z][x]) {
        if (demand[z][x] < sum) {
            cout << -1;
            exit(0);
        }
        co ++;
        if (z == 0) {
            m.addEdge(0,co,demand[z][x]-sum,0);
        } else {
            m.addEdge(co,1001,demand[z][x]-sum,0);
        }
        for (int i: v) comp[z][i] = co;
        return {demand[z][x],{}};
    } else {
        return {sum,v};
    }
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,r[0],r[1]); 
    FOR(i,1,n+1) re(a[i]);
    F0R(z,2) F0R(i,n-1) {
        int u,v; re(u,v);
        adj[z][u].pb(v), adj[z][v].pb(u);
    }    
    vi des;
    F0R(z,2) {
        re(q[z]);
        F0R(i,q[z]) {
            int k,x; re(k,x);
            demand[z][k] = x;
        }
        des.pb(getChild(z,r[z],0).f);
    }
    
    FOR(i,1,n+1) m.addEdge(comp[0][i],comp[1][i],1,-a[i]);
    // exit(0);
    // you should actually read the stuff at the bottom
    auto a = m.flow();
    // cout << a.f << " " << a.s << " " << des;
    for (int i: des) if (a[0] != i) {
        cout << -1;
        exit(0);
    }
    cout << -a[1];
    exit(0);
}