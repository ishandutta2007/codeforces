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



int powq(int x,int e) {
	if(!e) return 1;
	if(e&1) return int(1LL*x*powq(x,e-1)%P);
	x=powq(x,e>>1);
	return int(1LL*x*x%P);
}



int n,m;
char T[52][1024];
bool A[1024][1024];
bool seen[1024];
int F[1024],iF[1024],B[1024];

int dfs(int u) {
	if(seen[u]) return 0;
	seen[u]=1;
	int Z=1;
	for(int v=1;v<=m;v++) if(A[u][v]) Z+=dfs(v);
	return Z;
}
void add(int &x,int y) {
	x+=y;
	if(x>=P) x-=P;
}
int C(int n,int k) {
	return int(1LL*F[n]*iF[k]%P*iF[n-k]%P);
}


int32_t main() {
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++) scanf("%s",T[i]+1);
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) A[i][j]=1;
	for(int k=1;k<=n;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)
		if(T[k][i]!=T[k][j]) A[i][j]=0;
	vector<int> v;
	for(int i=1;i<=m;i++) if(!seen[i]) v.pb(dfs(i));

	F[0]=1;
	for(int i=1;i<1024;i++) F[i]=int(1LL*F[i-1]*i%P);
	for(int i=0;i<1024;i++) iF[i]=powq(F[i],P-2);
	B[0]=1;
	for(int n=0;n<1023;n++) for(int k=0;k<=n;k++)
		add(B[n+1],int(1LL*C(n,k)*B[k]%P));

	ll Z=1;
	for(int x:v) Z=Z*B[x]%P;
	// dbg(v,B[999]);
	printf("%d\n",int(Z));
}