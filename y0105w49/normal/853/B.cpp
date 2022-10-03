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



void add(ll &x,ll y) {
	if(x==linf || y==inf || y==linf) x=linf;
	else x+=y;
}

const int N=1<<20;
vector<pair<int,int> > arr[100<<10],dep[100<<10];
int n,m,k;

ll Z[N+N];
void del(int L,int R,int d) {

	if(L<0) L=0;
	if(R<0) R=0;
	assert(L<=R);
	L+=N,R+=N;
	for(;;) {
		if(L&1) add(Z[L++],d);
		if(!(R&1)) add(Z[R--],d);
		if(L>R) return;
		L>>=1,R>>=1;
	}
}
ll Q(int i) {
	ll W=0;
	for(i+=N;i>0;i>>=1) add(W,Z[i]);
	return W;
}



int32_t main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		int d,f,t,c; scanf("%d%d%d%d",&d,&f,&t,&c);
		assert(int(f==0) + int(t==0) == 1);
		if(f==0) {
			arr[t].pb({d,c});
		}
		if(t==0) {
			dep[f].pb({d,c});
		}
	}

	for(int i=1;i<=n;i++) {
		dep[i].pb({N,inf});
		sort(dep[i].begin(),dep[i].end());
		int bes=inf;
		int pr=1;
		for(const auto &P:dep[i]) {
			if(P.fi>pr) del(pr,P.fi-1,bes);
			pr=P.fi;
			bes=min(bes,P.se);
		}
		sort(arr[i].rbegin(),arr[i].rend());
		arr[i].pb({0,inf});
		bes=inf;
		pr=N+k;
		for(const auto &P:arr[i]) {
			if(P.fi<pr) del(P.fi+1-(k+1),pr-(k+1),bes);
			pr=P.fi;
			bes=min(bes,P.se);
		}
	}

	ll Z=linf;
	// for(int i=1;i<N-k-3;i++) if(Q(i)==10500) dbg(i,Q(i));
	for(int i=1;i<N;i++) Z=min(Z,Q(i));
	if(Z==linf) Z=-1;
	printf("%lld\n",Z);
}