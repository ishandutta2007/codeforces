// ayy
// ' lamo
// SUBLIME HAX
	#include <bits/stdc++.h>
	using namespace std;
	template<class T,class U>
	ostream &operator<<(ostream &os,const pair<T,U> &x) {
		return os<<"("<<x.first<<","<<x.second<<")";
	}
	namespace dbg_ns {
		template<typename C>
		struct is_iterable {
			template<class T> static long check(...);
			template<class T> static char check(int,
				typename T::const_iterator = C().end());
			enum {
				value = sizeof(check<C>(0)) == sizeof(char),
				neg_value = sizeof(check<C>(0)) != sizeof(char)
			};
		};
		template<class T> ostream &_out_str(ostream &os,const T &x) {
			return os<<'"'<<x<<'"';
		}
		template<class T> ostream &_dbg2_5(ostream &,const T &);
		template<bool B,typename T=void> using eit=typename enable_if<B,T>::type;
		template<class T>
		inline ostream &_dbg3(ostream &os,eit<is_iterable<T>::neg_value,const T> &x) {
			return os<<x;
		}
		template<class T>
		inline ostream &_dbg3(ostream &os,eit<is_iterable<T>::value,const T> &V) {
			os<<"{";
			bool ff=0;
			for(const auto &E:V) _dbg2_5(ff?os<<",":os,E), ff=1;
			return os<<"}";
		}
		template<>
		inline ostream &_dbg3<string>(ostream &os,const string &x) {
			return _out_str(os,x);
		}
		template<>
		inline ostream &_dbg3<const char *>(ostream &os,const char *const &x) {
			return _out_str(os,x);
		}
		template<class T> inline ostream &_dbg2_5(ostream &os,const T &x) {
			return _dbg3<T>(os,x);
		}
		template<class T,typename... Args> ostream &_dbg2(ostream &os,vector<string>::iterator nm,const T &x,Args&&... args);
		inline ostream &_dbg2(ostream &os,vector<string>::iterator) { return os; }
		template<typename... Args>
		inline ostream &_dbg2(ostream &os,vector<string>::iterator nm,const char *x,Args&&... args) {
			return _dbg2(_dbg3<const char *>(os<<"  ",x),nm+1,args...);
		}
		template<class T,typename... Args>
		inline ostream &_dbg2(ostream &os,vector<string>::iterator nm,const T &x,Args&&... args) {
			return _dbg2(_dbg3<T>(os<<"  "<<*nm<<"=",x),nm+1,args...);
		}
		vector<string> split(string s) {
			vector<string> Z;
			string z="";
			s+=',';
			int dep=0;
			for(char c:s) {
				if(c==',' && !dep) Z.push_back(z),z="";
				else z+=c;
				if(c=='(') ++dep;
				if(c==')') --dep;
			}
			return Z;
		}
		template<typename... Args> inline ostream &_dbg1(int ln,const string &nm,Args&&... args) {
			auto nms=split(nm);
			return _dbg2(cerr<<"L"<<ln<<":",nms.begin(),args...)<<endl;
		}
	}
	#define dbg(...) dbg_ns::_dbg1(__LINE__,#__VA_ARGS__,__VA_ARGS__)
	#define sz(x) (int(x.size()))
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
	#define fi first
	#define se second
	#define pb push_back
// END SUBLIME HAX
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
const ld eps=(ld)1e-8;
const ld tau=2*(ld)acosl(-1);
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;


void die() {
	printf("-1\n");
	exit(0);
}


vector<int> mxl_cqs;

struct small_graph { // assume: |V| <= 64
  typedef int state;
  int n;
  int N[1<<23]; // neighbor of i
  small_graph(int n=-1) : n(n) { }
  void add_edge(int src, int dst) {
    // n = max(n, max(src, dst)+1);
    N[1<<src] |= (1<<dst);
    N[1<<dst] |= (1<<src);
  }
  int maximal_cliques() {
    // enumerate cliques that include R, exclude X, arbitrary P.
    function<int (state,state,state)> rec = [&](state R, state P, state X) {
      if (!(P | X)) { // R is a bitset of maximal clique
        // for (int i = 0; i < n; ++i, R >>= 1)
        //   if (R & 1) cout << i << " ";
        // cout << endl;
      	mxl_cqs.pb(R);
        return 1;
      }
      int count = 0;
      state u = (P | X); u = u & ~(u-1);
      while (P & (N[u]|u)) {
        state v = P & ~(P-1);
        count += rec(R | v, P & ~(N[v]|v), X & ~(N[v]|v));
        P ^= v; X |= v;
      }
      return count;
    };
    return rec(0, (1<<n)-1, 0);
  }
} SG;


int _solve(int mk) {
	static int dp[1<<23];
	static bool seen[1<<23];
	int &ans=dp[mk];
	bool &sn=seen[mk];
	if(sn) return ans;
	sn=1;
	if(!mk) return ans=0;
	ans=inf;
	for(int c:mxl_cqs) if(c&mk)
		ans=min(ans,1+_solve(mk&~c));
	return ans;
}

vector<int> adj[23];
int solve(int n) {
	assert(n<=23);
	SG.n=n;
	for(int u=0;u<n;u++) for(int v:adj[u]) {
		assert(u!=v);
		if(u<v) SG.add_edge(u,v);
	}
	dbg(SG.maximal_cliques());

	return _solve((1<<n)-1);
}


char g[52][52];
vector<int> ss_dfs;
void dfs1(int u,const set<int> &S) {
	static bool seen[52];
	if(seen[u]) return;
	seen[u]=1;
	ss_dfs.pb(u);
	for(int v:S) if(v!=u && g[u][v]=='A')
		dfs1(v,S);
}


int32_t main() {
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",g[i]+1);
	set<int> nodes; for(int i=1;i<=n;i++) nodes.insert(i);
	for(;;) {
		for(int x:nodes) {
			for(int y:nodes) if(y!=x && g[x][y]=='A') goto nah;
			nodes.erase(x);
			goto cont;
			nah:;
		}
		break;
		cont:;
	}
	dbg(nodes);

	vector<vector<int> > sup_nodes;
	for(;sz(nodes);) {
		dfs1(*nodes.begin(),nodes);
		for(int x:ss_dfs) for(int y:ss_dfs)
			if(y!=x && g[x][y]=='X') die();
		for(int x:ss_dfs) nodes.erase(x);
		sup_nodes.pb(ss_dfs);
		ss_dfs.clear();
	}

	dbg(sup_nodes);

	int nn=sz(sup_nodes);
	assert(nn<=23);
	for(int i=0;i<nn;i++) for(int j=0;j<nn;j++) if(i!=j) {
		for(int x:sup_nodes[i]) for(int y:sup_nodes[j]) {
			assert(x!=y);
			if(g[x][y]=='X') {
				adj[i].pb(j);
				goto qq;
			}
		}
		qq:;
	}

	for(int i=0;i<nn;i++) dbg(i,adj[i]);

	printf("%d\n",n-1+solve(nn));
}