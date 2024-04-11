// SUBLIME HAX
	/*nope
	cat
	// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars// sixteen chars
	// ayy
	// ' lamo
	*/
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


void add(int &x,int y) {
	x+=y;
	if(x>=P) x-=P;
}
int mul(int x,int y) {
	return int(1LL*x*y%P);
}

struct dat {
	int ans;
	int pp,pm,mp,mm;
	int PP,PM,MP,MM;
	void init(int P,int M) {
		ans=P;
		pp=pm=mp=mm=0;
		PP=PM=MP=MM=0;

		pp=mm=1;
		PP=P;
		MM=M;
	}
};


const int N=200<<10;
int n;
vector<int> adj[N];
int a[N],b[N];
dat dfs(int u,int p=-1) {
	vector<dat> rec;
	for(int v:adj[u]) if(v!=p) rec.pb(dfs(v,u));
	dat Z; Z.init(a[u],b[u]);
	for(const dat &D:rec) {
		add(Z.ans,D.ans);

		int x,y;
		x=mul(D.pp,Z.MP);
		y=mul(D.PP,Z.mp);
		add(x,y); add(x,x);
		add(Z.ans,x);
		x=mul(D.mp,Z.PP);
		y=mul(D.MP,Z.pp);
		add(x,y); add(x,x);
		add(Z.ans,x);

		add(Z.pp,D.mp);
		add(Z.pm,D.mm);
		add(Z.mp,D.pp);
		add(Z.mm,D.pm);
		add(Z.PP,mul(a[u],D.mp));
		add(Z.PP,D.MP);
		add(Z.PM,mul(a[u],D.mm));
		add(Z.PM,D.MM);
		add(Z.MP,mul(b[u],D.pp));
		add(Z.MP,D.PP);
		add(Z.MM,mul(b[u],D.pm));
		add(Z.MM,D.PM);
	}

	// dbg(u,Z.pp,Z.pm,Z.mp,Z.mm,Z.PP,Z.PM,Z.MP,Z.MM,Z.ans);
	return Z;
}






int32_t main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) a[i]%=P, a[i]+=P, a[i]%=P;
	for(int i=1;i<=n;i++) b[i]=(P-a[i])%P;
	for(int i=1;i<=n-1;i++) {
		int u,v; scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dat Z=dfs(1);
	dbg(Z.pp,Z.pm,Z.mp,Z.mm,Z.PP,Z.PM,Z.MP,Z.MM,Z.ans);
	printf("%d\n",Z.ans);
}