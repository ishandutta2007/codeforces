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




const int N=300<<10;
int n,k;
int q[N];
bool dead[N];
int excl[N];
int ss_head[N];
int nxt[N],prv[N];
set<int> nonmt;
bool nmt[N];

void fix(int u) {
	bool b=(ss_head[u]!=0);
	if(b==nmt[u]) return;
	nmt[u]=b;
	if(b) nonmt.insert(u);
	else nonmt.erase(u);
}
int next_bang(int up) {
	int hi=up;
	auto it=nonmt.upper_bound(hi);
	--it;
	up=hi=*it;
	for(;;) {
		assert(up>0);
		assert(ss_head[hi]);

		int u=ss_head[hi];
		ss_head[hi]=nxt[u];
		if(nxt[u]) prv[nxt[u]]=0;
		fix(hi);

		dead[u]=1;
		return u;
	}
}
void dec(int u) {
	if(dead[u]) return;

	if(nxt[u]) prv[nxt[u]]=prv[u];
	if(prv[u]) nxt[prv[u]]=nxt[u];
	else ss_head[q[u]]=nxt[u];
	fix(q[u]);

	--q[u];

	nxt[u]=ss_head[q[u]];
	if(nxt[u]) prv[nxt[u]]=u;
	prv[u]=0;
	ss_head[q[u]]=u;
	fix(q[u]);
}


int32_t main() {
	scanf("%d%d",&n,&k);
	for(int x=1;x<=n;x++) {
		for(int y=x+x;y<=n;y+=x) {
			++q[x],++q[y];
		}
	}

	int Z=0;
	for(int x=1;x<=n;x++) {
		nxt[x]=ss_head[q[x]];
		if(nxt[x]) prv[nxt[x]]=x;
		ss_head[q[x]]=x;
		Z+=q[x];
		fix(q[x]);
	}
	Z/=2;
	if(Z<k) return printf("No\n"),0;

	bool flag=0;
	for(;Z>k;) {
		if(flag) --n;
		int u;
		if(Z-q[n] >= k) {
			u=n;
			flag=1;
		} else {
			u=next_bang(Z-k);
			flag=0;
		}
		assert(q[u]>=0);
		int del=q[u];

		assert(Z-del >= k);
		Z-=del;

		excl[u]=1;
		int d;
		if(u>1) dec(1);
		for(d=2;d*d<u;d++) {
			if(u%d) continue;
			dec(d),dec(u/d);
		}
		assert(d*d>=u);
		if(d*d==u) dec(d);
		for(int v=u+u;v<=n;v+=u) dec(v);
	}
	assert(Z==k);

	int m=n-accumulate(excl+1,excl+1+n,0);
	printf("Yes\n%d\n",m);
	for(int u=1;u<=n;u++) if(!excl[u]) printf("%d%c",u," \n"[!--m]);
}