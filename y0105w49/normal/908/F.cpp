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







int bestI(const vector<int> &v,int L,int R) {
	if(!sz(v)) return R-L;
	int Z=max(v[0]-L,R-v.back());
	for(int i=1;i<sz(v);i++) Z=max(Z,v[i]-v[i-1]);
	return Z;
}



int32_t main() {
	int n;
	scanf("%d",&n);
	vector<pair<int,char> > vv;
	for(int i=0;i<n;i++) {
		static char buf[4];
		int p;
		scanf("%d%s",&p,buf);
		vv.pb({p,*buf});
	}
	sort(vv.begin(),vv.end());
	bool hasG=0;
	for(int i=0;i<n;i++) if(vv[i].se=='G') hasG=1;

	ll Z=0;
	if(!hasG) {
		// no G
		vector<int> R,B;
		for(const auto &P:vv) {
			assert(P.se=='R' || P.se=='B');
			(P.se=='R' ? R : B).pb(P.fi);
		}
		assert(sz(R) || sz(B));
		if(sz(R)) Z+=R.back()-R[0];
		if(sz(B)) Z+=B.back()-B[0];
		printf("%lld\n",Z);
		return 0;
	}

	vector<int> Rs,Bs;
	int lastG=-1,lastR=-1,lastB=-1;
	for(const auto &P:vv) {
		int x=P.fi;
		char c=P.se;
		if(!~lastG) {
			if(c=='R' && !~lastR) Z-=x;
			if(c=='B' && !~lastB) Z-=x;
			if(c=='G') {
				if(~lastR) Z+=x;
				if(~lastB) Z+=x;
				Rs.clear();
				Bs.clear();
			}
		}
		if(~lastG && c=='G') {
			int w=x-lastG;
			Z+=min(2LL*w, 3LL*w-bestI(Rs,lastG,x)-bestI(Bs,lastG,x));
			Rs.clear();
			Bs.clear();
		}
		if(c=='G') lastG=x;
		if(c=='R') lastR=x, Rs.pb(x);
		if(c=='B') lastB=x, Bs.pb(x);
	}
	if(lastR>lastG) Z+=lastR-lastG;
	if(lastB>lastG) Z+=lastB-lastG;

	printf("%lld\n",Z);
}