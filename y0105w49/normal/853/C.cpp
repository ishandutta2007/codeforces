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
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
const ld eps=(ld)1e-8;
const ld tau=2*(ld)acosl(-1);
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;


typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update
> Tree;


// const int N=200<<10;
const int N=1<<18;
int n,q,ip[N],p[N];
int l[N],d[N],r[N],u[N];
vector<int> qs[N];
map<int,int> zs[N];

void INS(int x,int y) {
	qs[x].pb(y);
}

// Tree ss;

int ff[N+N];
void upd(int x) {
	x+=N;
	for(;x>0;x>>=1) ff[x]++;
}
int Q(int L,int R) {
	L+=N,R+=N;
	int Z=0;
	for(;;) {
		if(L&1) Z+=ff[L++];
		if(!(R&1)) Z+=ff[R--];
		if(L>R) return Z;
		L>>=1,R>>=1;
	}
}


int32_t main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	// for(int i=1;i<=n;i++) p[ip[i]]=i;
	for(int i=1;i<=q;i++) scanf("%d%d%d%d",l+i,d+i,r+i,u+i);
	for(int i=1;i<=q;i++) {
		INS(l[i]-1,d[i]-1);
		INS(l[i]-1,u[i]);
		INS(r[i],d[i]-1);
		INS(r[i],u[i]);
	}
	for(int x=0;x<=n;x++) {
		// if(x) ss.insert(p[x]);
		if(x) upd(p[x]);
		// for(int y:qs[x]) zs[x][y]=(int)ss.order_of_key(y+1);
		for(int y:qs[x]) zs[x][y]=Q(1,y);
	}
	for(int i=1;i<=q;i++) {
		static vector<int> ww; ww.clear();
		ww.pb(n);
		ww.pb(-(l[i]-1));
		ww.pb(-(d[i]-1));
		ww.pb(-(n-r[i]));
		ww.pb(-(n-u[i]));
		ww.pb(zs[l[i]-1][d[i]-1]);
		ww.pb((l[i]-1) - zs[l[i]-1][u[i]]);
		ww.pb((d[i]-1) - zs[r[i]][d[i]-1]);
		ww.pb(n - r[i] - u[i] + zs[r[i]][u[i]]);
		// dbg(ww);
		ll Z=0;
		for(int x:ww) {
			bool neg=(x<0);
			x=abs(x);
			ll y=1LL*x*(x-1)/2;
			if(neg) y=-y;
			Z+=y;
		}
		printf("%lld\n",Z);
	}
}