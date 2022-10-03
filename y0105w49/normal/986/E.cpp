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
const int e7=e6*10;


int powq(int x,int e) {
	if(!e) return 1;
	if(e&1) return int(1LL*x*powq(x,e-1)%P);
	x=powq(x,e>>1);
	return int(1LL*x*x%P);
}

const int S=10<<20;
const int L=17;
const int N=1<<L;
int n,pp[L][N],*p=pp[0],d[N],a[N],op[N],cl[N],tt=3;
vector<int> adj[N];


void dfs(int u,int _p=-1,int _d=0) {
	p[u]=_p;
	for(int l=1;l<L;l++) pp[l][u]=(~pp[l-1][u] ? pp[l-1][pp[l-1][u]] : -1);
	d[u]=_d;
	op[u]=++tt;
	for(int v:adj[u]) if(v!=_p) dfs(v,u,_d+1);
	cl[u]=++tt;
}
int lca(int u,int v) {
	if(d[u]>d[v]) swap(u,v);
	for(int l=L;--l>=0;) if(d[v]-(1<<l) >= d[u]) v=pp[l][v];
	if(u==v) return u;
	for(int l=L;--l>=0;) if(pp[l][u]!=pp[l][v]) u=pp[l][u],v=pp[l][v];
	assert(u!=v && p[u]==p[v]);
	return p[u];
}


vector<int> ps;
vector<pair<int,int>> pps;
const int spps=700<<10;

vector<pair<int,int>> psums[spps];

void ins(int u,int p,int e) {
	auto it=lower_bound(all_(pps),pair<int,int>(p,0));
	for(int f=1;it!=pps.end() && it->fi==p;++it,++f) {
		int i=int(it-pps.begin());
		psums[i].pb({op[u],min(e,f)});
		psums[i].pb({cl[u],-min(e,f)});
	}
}
void genem() {
	for(int i=0;i<spps;i++) {
		sort(psums[i].begin(),psums[i].end());
		for(int j=1;j<sz(psums[i]);j++) {
			psums[i][j].se+=psums[i][j-1].se;
		}
	}
}


int W(int l,int r,const vector<pair<int,int>> &v) {
	auto itl=lower_bound(v.begin(),v.end(),pair<int,int>(l,-inf));
	auto itr=lower_bound(v.begin(),v.end(),pair<int,int>(r,inf));
	int Z=0;
	if(itr!=v.begin()) Z+=(--itr)->se;
	if(itl!=v.begin()) Z-=(--itl)->se;
	return Z;
}
int Q(int u,int v,int p,int e) {
	auto it=lower_bound(all_(pps),pair<int,int>(p,e));
	int i=int(it-pps.begin());
	e=W(op[u],op[v],psums[i]);
	assert(e>=0);
	return powq(p,e);
}
int Q(int u,int v,int x) {
	int Z=1;
	for(int p:ps) {
		if(p*p>x) break;
		if(x%p) continue;
		int e=0;
		for(;!(x%p);) ++e,x/=p;
		Z=int(1LL*Z*Q(u,v,p,e)%P);
	}
	if(x>1) Z=int(1LL*Z*Q(u,v,x,1)%P);
	return Z;
}


#undef QQ
int32_t main() { // CURSOR START
	for(int p=2;p<S;p++) {
		static bool nisp[S];
		if(nisp[p]) continue;
		int me=0;
		for(int x=p;x<S;x+=p) {
			int y=x,e=0;
			for(;!(y%p);) ++e,y/=p;
			nisp[x]=1;
			me=max(me,e);
		}
		assert(me>0);
		ps.pb(p);
		for(int e=1;e<=me;e++) pps.pb({p,e});
		// dbg(p,me);
	}
	dbg(sz(ps),sz(pps));
	assert(sz(pps)<spps);

	#ifdef QQ
	n=100000;
	#else
	scanf("%d",&n);
	#endif
	for(int i=1;i<=n-1;i++) {
		#ifdef QQ
		int u=i,v=i+1;
		#else
		int u,v; scanf("%d%d",&u,&v);
		#endif
		adj[u].pb(v);
		adj[v].pb(u);
	}
	#ifdef QQ
	for(int i=1;i<=n;i++) a[i]=rand()%e7+1;
	#else
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	#endif
	dfs(1);

	for(int i=1;i<=n;i++) {
		int x=a[i];
		for(int p:ps) {
			if(p*p>x) break;
			if(x%p) continue;
			int e=0;
			for(;!(x%p);) ++e,x/=p;
			ins(i,p,e);
		}
		if(x>1) ins(i,x,1);
	}

	genem();

	#ifdef QQ
	int q=100000;
	#else
	int q; scanf("%d",&q);
	#endif
	for(;q--;) {
		#ifdef QQ
		int u=rand()%n+1,v=rand()%n+1,x=rand()%e7+1;
		#else
		int u,v,x; scanf("%d%d%d",&u,&v,&x);
		#endif
		if(u==v) {
			printf("%d\n",__gcd(a[u],x));
			continue;
		}
		int w=lca(u,v);
		if(w==u || w==v) printf("%d\n",Q(w,u^v^w,x));
		else printf("%d\n",int(1LL*Q(w,u,x)*Q(w,v,x)%P*powq(__gcd(a[w],x),P-2)%P));
	}
}