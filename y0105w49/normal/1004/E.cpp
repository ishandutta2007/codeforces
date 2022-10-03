// BEGIN AUTOFOLD
	/*NOSUCHFILE
	cat
	// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars
	// ayy lamo
	*/
	#include <bits/stdc++.h>
	using namespace std;
	namespace gbd_ns {
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
		template<bool B,typename T=void> using eit=typename enable_if<B,T>::type;
		template<class T> struct _gbd3C;
		template<class T> ostream &_gbd3(ostream &os,const T &x) {
			return _gbd3C<T>::call(os,x);
		}
		template<class T> struct _gbd3C {
			template<class U=T>
			static ostream &call(ostream &os,eit<is_iterable<U>::value,const T> &V) {
				os<<"{";
				bool ff=0;
				for(const auto &E:V) _gbd3<decltype(E)>(ff?os<<",":os,E), ff=1;
				return os<<"}";
			}
			template<class U=T>
			static ostream &call(ostream &os,eit<is_iterable<U>::neg_value,const T> &x) {
				return os<<x;
			}
		};
		template<> struct _gbd3C<string> {
			static ostream &call(ostream &os,const string &s) {
				return os<<'"'<<s<<'"';
			}
		};
		template<> struct _gbd3C<char *> {
			static ostream &call(ostream &os,char *const &s) {
				return os<<'"'<<s<<'"';
			}
		};
		template<class S,class T> struct _gbd3C<pair<S,T> > {
			static ostream &call(ostream &os,const pair<S,T> &p) {
				_gbd3(os<<'(',p.first);
				_gbd3(os<<',',p.second);
				return os<<')';
			}
		};
		template<class T,typename... Args> ostream &_gbd2(ostream &os,vector<string>::iterator nm,const T &x,Args&&... args);
		ostream &_gbd2(ostream &os,vector<string>::iterator) { return os; }
		template<typename... Args>
		ostream &_gbd2(ostream &os,vector<string>::iterator nm,const char *x,Args&&... args) {
			return _gbd2(os<<"  "<<x,nm+1,args...);
		}
		template<class T,typename... Args>
		ostream &_gbd2(ostream &os,vector<string>::iterator nm,const T &x,Args&&... args) {
			return _gbd2(_gbd3<T>(os<<"  "<<*nm<<"=",x),nm+1,args...);
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
		template<typename... Args> ostream &_gbd1(int ln,const string &nm,Args&&... args) {
			auto nms=split(nm);
			_gbd2(cerr<<"L"<<ln<<":",nms.begin(),args...);
			return cerr<<endl;
		}
	}
	#define _gbd(...) gbd_ns::_gbd1(__LINE__,#__VA_ARGS__,__VA_ARGS__)
	#ifdef ARST
	#define QQ
	#else
	#define OJ
	#endif
	inline void nop() {}
	#define sz(x) (int((x).size()))
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
	#define fi first
	#define se second
	#define pb push_back
	#define OMAP(S,T) tree<S,T,less<S>,rb_tree_tag,tree_order_statistics_node_update>
	#define OSET(S) OMAP(S,null_type)
	#define all_(v) begin(v),end(v)
	const int e3=1000;
	const int e6=e3*e3;
	const int e9=e6*e3;
	const long double tau=2*acosl(-1);
// END AUTOFOLD
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
#define dbg _gbd
// #define dbg(...) cerr
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
const ld eps=(ld)1e-8;
const int inf=e9+99;
const ll linf=1LL*e9*e9+99;
const int P=e9+7;




const int N=100<<10;
int n,k;
vector<pair<int,int>> adj[N],fas[N];
int p[N],D[N],DD[N];

int dd(int u,int v) {
	if(fas[u][0].se!=v) return fas[u][0].fi;
	if(sz(fas[u])>=2) return fas[u][1].fi;
	return 0;
}

int dfs1(int u,int _p=-1) {
	p[u]=_p;
	for(const auto &P:adj[u]) if(P.fi!=_p) {
		int r=dfs1(P.fi,u)+P.se;
		D[u]=max(D[u],r);
		fas[u].pb({r,P.fi});
	}
	return D[u];
}
void dfs2(int u,int _p=-1,int _d=0) {
	// dbg(u,_p,_d);
	if(~_p) fas[u].pb({_d,_p});
	sort(fas[u].rbegin(),fas[u].rend());

	for(const auto &P:adj[u]) if(P.fi!=_p) {
		dfs2(P.fi,u,dd(u,P.fi)+P.se);
	}
}

set<int> ff[N];
void adv(vector<int> &z,int &n,int &c,int &r) {
	assert(~n);
	z.pb(n);
	ff[n].insert(c);
	ff[c].insert(n);
	int pr=c;
	c=n;
	r=0;
	n=-1;
	for(const auto &P:adj[c]) {
		if(P.fi==pr) continue;
		int v=P.fi;
		int co=dd(v,c)+P.se;
		if(co>r) n=v, r=co;
	}
}

int32_t main() { // CURSOR START
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++) {
		int u,v,d; scanf("%d%d%d",&u,&v,&d);
		adj[u].pb({v,d});
		adj[v].pb({u,d});
	}
	if(n==1) return printf("0\n"),0;

	dfs1(1);
	dfs2(1);

	int dz=-1;
	for(int u=1;u<=n;u++) {
		DD[u]=fas[u][0].fi;
		if(!~dz || DD[u]<DD[dz]) dz=u;
	}

	vector<int> zz;
	zz.pb(dz);
	int c1=dz,c2=dz;
	int n1=-1,n2=-1;
	int r1=0,r2=0;
	for(const auto &P:adj[dz]) {
		int v=P.fi;
		int co=dd(v,dz)+P.se;
		if(co>r1) n1=v, r1=co;
	}
	for(const auto &P:adj[dz]) {
		if(P.fi==n1) continue;
		int v=P.fi;
		int co=dd(v,dz)+P.se;
		if(co>r2) n2=v, r2=co;
	}
	// dbg(dz,n1,n2,r1,r2);

	for(;sz(zz)<k;) {
		if(max(r1,r2)==0) break;
		if(r1>r2) adv(zz,n1,c1,r1);
		else adv(zz,n2,c2,r2);
	}

	int Z=0;
	for(int u:zz) for(const auto &P:adj[u]) if(!ff[u].count(P.fi)) {
		Z=max(Z,dd(P.fi,u)+P.se);
	}

	// dbg(zz);
	printf("%d\n",Z);
}