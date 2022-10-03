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
// typedef __uint128_t ull;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
const ld eps=(ld)1e-8;
const int inf=e9+99;
const ll linf=1LL*e9*e9+99;
// const int P=e9+7;
const int P=998244353;

// #define int ll

void add(int &x,int y) {
	x+=y;
	if(x>=P) x-=P;
}
void sub(int &x,int y) {
	x-=y;
	if(x<0) x+=P;
}
ull powq_ull(ull x,ull e,ull p) {
	if(!e) return 1;
	if(e&1) return x*powq_ull(x,e-1,p)%p;
	x=powq_ull(x,e>>1,p);
	return x*x%p;
}
const ull PP=(119ULL<<23)+1;
const int AA=119;
const ull ROOT = 3;
const ull INV_ROOT = 332748118;
const ull TWO_INV = 499122177;

vector<ull> fft(const vector<ull>& input,const bool inv=0) {
	const ull P=PP;
	const int A=AA;
	const ull RT=ROOT;
	const ull IRT=INV_ROOT;
	const ull I2=TWO_INV;
	const int N = (int)input.size();
	vector<ull> arr(input);
	for (ull& x : arr)
		x %= P;
	for (int half=inv?1:N/2; 1<=half&&half<N; inv?half<<=1:half>>=1) {
		ull wm = inv ? IRT : RT;
		wm = powq_ull(wm,A,P);
		for (int ord = int((P - 1) / A); ord > 2 * half; ord >>= 1)
			wm = (wm * wm) % P;
		for (int st = 0; st < N; st += 2 * half) {
			ull w = 1;
			for (int j = st; j < st + half; ++j) {
				if(inv) arr[j+half] = arr[j+half]*w%P;

				ull a=arr[j], b=arr[j+half];
				arr[j] = a+b; if(arr[j]>=P) arr[j]-=P;
				arr[j+half] = a+P-b; if(arr[j+half]>=P) arr[j+half]-=P;

				if(!inv) arr[j+half] = arr[j+half]*w%P;

				w = (w * wm) % P;
			}
		}
	}
	if(inv) {
		ull size_inv = 1;
		for (int sz = 2; sz <= N; sz <<= 1)
			size_inv = (size_inv * I2) % P;
		for (ull& x : arr)
			x = (x * size_inv) % P;
	}
	return arr;
}
vector<int> mulfst(const vector<int> &A,const vector<int> &B) {
	int m=sz(A),n=sz(B);
	int w=m+n-1;
	for(;w&(w-1);) ++w;
	vector<ull> AA(w,0), BB(w,0);
	for(int i=0;i<m;i++) AA[i]=A[i];//%PP;
	for(int i=0;i<n;i++) BB[i]=B[i];//%PP;
	AA=fft(AA);
	BB=fft(BB);
	for(int i=0;i<w;i++) AA[i]*=BB[i];
	AA=fft(AA,1);
	for(;sz(AA)>m+n-1;) assert(!AA.back()), AA.pop_back();
	vector<int> Z;
	for(ull x:AA) Z.pb((int)x);
	return Z;
}

vector<int> mulslo(const vector<int> &A,const vector<int> &B) {
	int n=sz(A),m=sz(B);
	int w=m+n-1;
	vector<int> Z(w,0);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		add(Z[i+j],int(1LL*A[i]*B[j]%P));
	return Z;
}

#define mul mulfst

const int N=100<<10;
int n,k;
set<int> adj[N];
int p[N],sz[N];
int nn;
int dfs_sz(int u,int _p=-1) {
	p[u]=_p;
	sz[u]=1;
	for(int v:adj[u]) if(v!=_p) sz[u]+=dfs_sz(v,u);
	if(!~_p) nn=sz[u];
	return sz[u];
}
int siz(int u,int _p) {
	if(p[u]==_p) return sz[u];
	assert(p[_p]==u);
	return nn-sz[_p];
}

vector<int> ml(const vector<int> &szs,int l,int r) {
	if(l==r) return {1,szs[l]};
	int m=(l+r)>>1;
	return mul(ml(szs,l,m),ml(szs,m+1,r));
}

int ff(int x) {
	if(!x) return 1;
	static bool seen[N];
	static int dp[N];
	bool &sn=seen[x];
	int &ans=dp[x];
	if(sn) return ans;
	sn=1;
	return ans=int(1LL*ff(x-1)*x%P);
}
int iff(int x) {
	// return (int)powq_ull(ff(x),P-2,P);
	if(x==N-3) return (int)powq_ull(ff(x),P-2,P);
	static bool seen[N];
	static int dp[N];
	bool &sn=seen[x];
	int &ans=dp[x];
	if(sn) return ans;
	sn=1;
	return ans=int(1LL*iff(x+1)*(x+1)%P);
}

int slow_eval(const vector<int> &p,int x) {
	int Z=0;
	int qq=0;
	for(int i=0;i<sz(p);i++) {
		qq=int((p[i]+P-1LL*qq*x%P)%P);
		int fxqq=int(1LL*qq*ff(k)%P*iff(k-i)%P);
		add(Z,fxqq);
	}
	// dbg("eval",p,x,Z);
	return Z;
}


// int ZZ[N];
map<int,int> WW[N];
int RR[N];


void solve(int u) {
	vector<int> sizs;
	for(int v:adj[u]) sizs.pb(siz(v,u));
	vector<int> poly=ml(sizs,0,sz(sizs)-1);
	// dbg(u,poly);
	for(;sz(poly)>k+1;) poly.pop_back();
	RR[u]=0;
	for(int x:poly) add(RR[u],x);
	sort(sizs.begin(),sizs.end());
	sizs.resize(unique(sizs.begin(),sizs.end())-sizs.begin());
	map<int,int> edp;
	for(int x:sizs) edp[x]=slow_eval(poly,x);
	for(int v:adj[u]) {
		int zz=edp[siz(v,u)];
		// add(ZZ[u],zz);
		WW[u][v]=zz;
	}
}

int dfs_ins(int u,int p) {
	assert(WW[u].count(p));
	int z=WW[u][p];
	for(int v:adj[u]) if(v!=p) add(z,dfs_ins(v,u));
	return z;
}
int FF;
int dfs_zz(int u,int p) {
	assert(WW[u].count(p));
	int Z=int(1LL*WW[u][p]*FF%P);
	for(int v:adj[u]) if(v!=p) add(Z,dfs_zz(v,u));
	return Z;
}

int decomp(int u) {
	dfs_sz(u);
	loop:;
	for(int v:adj[u]) if(siz(v,u)>siz(u,v)) { u=v; goto loop; }

	int Z=0;
	FF=0;
	for(int v:adj[u]) {
		add(Z,dfs_zz(v,u));
		int r=dfs_ins(v,u);
		add(FF,r);
		add(Z,int(1LL*r*WW[u][v]%P));
	}

	for(int v:adj[u]) adj[v].erase(u), add(Z,decomp(v));
	adj[u].clear();
	return Z;
}




int32_t main() { // CURSOR START
	dbg(ff(3),ff(7),iff(3),iff(2),iff(1));
	assert(P==PP);
	scanf("%d%d",&n,&k);
	assert(k==1 || k>=n-1);
	for(int i=1;i<=n-1;i++) {
		int u,v; scanf("%d%d",&u,&v);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	if(n==1) return printf("0\n"),0;
	if(k==1) return printf("%d\n",int((1LL*n*(n-1)/2)%P)),0;
	dfs_sz(1);
	assert(n==nn);

	for(int u=1;u<=n;u++) solve(u);

	printf("%d\n",decomp(1));
}