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
const int inf=1.1e9;
const ll linf=1e18+99;
const int P=1e9+7;



const int N=200<<10;
int n,a[N];




bool poss(int L,int R,int LL,int RR,int tg,int l=29) {
	if(L>R || LL>RR) return 0;
	if(l<0) return 1;
	if(tg & (1<<l)) {
		//allow anything
		// skip if same at this bit anywhere.
		if((a[R] ^ a[RR]) <= tg) return 1;
		if((a[L] ^ a[LL]) <= tg) return 1;
		// they all differ at this bit, continue.
		return poss(L,R,LL,RR,tg,l-1);
	}

	int mask1=(a[L]>>l)<<l;
	int M=int(lower_bound(a+L,a+R+1,mask1|(1<<l))-a)-1;
	int mask2=(a[LL]>>l)<<l;
	int MM=int(lower_bound(a+LL,a+RR+1,mask2|(1<<l))-a)-1;
	return poss(L,M,LL,MM,tg,l-1) || poss(M+1,R,MM+1,RR,tg,l-1);
}

int minxor(int L,int R,int LL,int RR) {
	assert(L<=R && LL<=RR);
	int lef=0,rig=1<<30;
	for(;lef<rig;) {
		int mid=(lef+rig)>>1;
		if(poss(L,R,LL,RR,mid)) rig=mid;
		else lef=mid+1;
	}
	return lef;
}

ll mst(int L,int R,int l=29) {
	if(l<0) return 0;

	if(a[L] & (1<<l)) return mst(L,R,l-1);
	if(!(a[R] & (1<<l))) return mst(L,R,l-1);
	int mask=((a[L]>>l)<<l);
	int M=int(lower_bound(a+L,a+R+1,mask | (1<<l))-a)-1;
	// dbg(L,M,R,vector<int>(a+L,a+R+1));
	assert(L<=M && M<R);

	int bes=minxor(L,M,M+1,R);

	ll Z=mst(L,M,l-1)+mst(M+1,R,l-1);
	return Z+bes;
}





int32_t main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	printf("%lld\n",mst(1,n));
}