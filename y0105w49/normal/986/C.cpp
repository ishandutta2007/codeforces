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



const int L=22;
const int N=1<<L;
int n,m,a[N+1];
int da[N],rk[N];
bool ex[N];
int dp[N];
int CC;
int rt(int u) { return da[u]==u ? u : da[u]=rt(da[u]); }
void un(int u,int v) {
	u=rt(u),v=rt(v);
	if(u==v) return;
	--CC;
	if(rk[u]>rk[v]) swap(u,v);
	if(rk[u]==rk[v]) ++rk[v];
	da[u]=v;
}

void dfs(int msk,int u) {
	if(dp[msk]==-1) return;
	if(dp[msk]>=0) { un(u,dp[msk]); return; }
	dp[msk]=u;
	if(ex[msk]) un(u,msk);
	for(int l=0;l<L;l++) if(msk & (1<<l))
		dfs(msk & ~(1<<l),u);
}

#undef QQ
int32_t main() { // CURSOR START
	#ifdef QQ
	n=22;
	m=1<<n;
	for(int i=0;i<m;i++) a[i]=i;
	#else
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d",a+i);
	#endif

	for(int i=0;i<N;i++) da[i]=i;
	for(int i=0;i<m;i++) ex[a[i]]=1;
	for(int i=0;i<N;i++) dp[i]=-1;
	for(int i=0;i<N;i++) {
		if(ex[i]) dp[i]=-2;
		if(dp[i]==-1) continue;
		for(int l=0;l<L;l++) {
			dp[i | (1<<l)]=-2;
		}
	}

	CC=m;
	for(int i=0;i<m;i++) {
		int x=a[i];
		dfs((N-1)&~x,x);
	}
	printf("%d\n",CC);

}