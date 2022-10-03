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
// const int P=e9+7;

const int P=998244353;
int sum(int x,int y) {
	int z=x+y;
	return z>=P ? z-P : z;
}


const int N=256<<10;
// unordered_set<int> partial[N+N],full[N+N];
int lzf[N+N],lzc[N+N];
int val[N+N];
int _L[N+N],_R[N+N];

unordered_map<int,char> tre[N];
void makeful(int i,int x) {
	tre[x][i]=2;
	if(tre[x].count(i+i)) tre[x].erase(i+i);
	if(tre[x].count(i+i+1)) tre[x].erase(i+i+1);
}
void makepat(int i,int x) {
	tre[x][i]=1;
}
bool isful(int i,int x) { return tre[x].count(i) && tre[x][i]==2; }
bool ispat(int i,int x) { return tre[x].count(i) && tre[x][i]==1; }


#define lc (i+i)
#define rc (i+i+1)
#define M ((L+R)>>1)
#define lr lc,L,M
#define rr rc,M+1,R


void MOD(int i,int f,int c) {
	val[i]=int((1LL*val[i]*f+1LL*c*(_R[i]-_L[i]+1))%P);
	lzc[i]=int((1LL*lzc[i]*f+c)%P);
	lzf[i]=int(1LL*lzf[i]*f%P);
}
void push(int i) {
	assert(i<N);
	if(lzf[i]==1 && lzc[i]==0) return;
	MOD(i+i,lzf[i],lzc[i]);
	MOD(i+i+1,lzf[i],lzc[i]);
	lzf[i]=1;
	lzc[i]=0;
}
void pull(int i) {
	assert(i<N);
	assert(lzf[i]==1 && lzc[i]==0);
	val[i]=sum(val[i+i],val[i+i+1]);
}

#define mul2(i) MOD(i,2,0)
#define add1(i) MOD(i,1,1)

bool INS(int l,int r,int x,bool ff=0,int i=1,int L=0,int R=N-1) {
	if(r<L || l>R) return isful(i,x);
	if(l<=L && R<=r) {
		if(ispat(i,x)) {
			assert(!ff);
			push(i);
			INS(l,r,x,0,lr);
			INS(l,r,x,0,rr);
			makeful(i,x); // clrs children
			pull(i);
			return 1;
		}
		if(ff || isful(i,x)) {
			mul2(i);
			return 1;
		}
		makeful(i,x);
		add1(i);
		return 1;
	}
	push(i);
	if(!ff && isful(i,x)) ff=1;
	bool f1=INS(l,r,x,ff,lr);
	bool f2=INS(l,r,x,ff,rr);
	if(!ff && f1 && f2) makeful(i,x);
	else if(!ff) makepat(i,x);
	pull(i);
	return ff;
}
int Q(int l,int r,int i=1,int L=0,int R=N-1) {
	if(r<L || l>R) return 0;
	if(l<=L && R<=r) return val[i];
	push(i);
	return sum(Q(l,r,lr),Q(l,r,rr));
}

void build(int i=1,int L=0,int R=N-1) {
	_L[i]=L;
	_R[i]=R;
	lzf[i]=1;
	if(L<R) build(lr), build(rr);
}

#undef QQ
int32_t main() { // CURSOR START
	build();
	#ifdef QQ
	int n=200000,q=200000;
	for(;q--;) {
		int l=rand()%n+1,r=rand()%n+1,x=rand()%n+1;
		if(l>r) swap(l,r);
		if(q&1) printf("%d\n",Q(l,r));
		else INS(l,r,x);
	}
	#else


	int n,q; scanf("%d%d",&n,&q);
	for(;q--;) {
		int t; scanf("%d",&t);
		if(t==1) {
			int l,r,x; scanf("%d%d%d",&l,&r,&x);
			INS(l,r,x);
		} else
		if(t==2) {
			int l,r; scanf("%d%d",&l,&r);
			printf("%d\n",Q(l,r));
		} else
		assert(0);
	}
	#endif
}