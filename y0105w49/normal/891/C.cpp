// // ayy
// // ' lamo
// // SUBLIME HAX
// 	#include <bits/stdc++.h>
// 	using namespace std;
// 	template<class T,class U>
// 	ostream &operator<<(ostream &os,const pair<T,U> &x) {
// 		return os<<"("<<x.first<<","<<x.second<<")";
// 	}
// 	namespace dbg_ns {
// 		template<typename C>
// 		struct is_iterable {
// 			template<class T> static long check(...);
// 			template<class T> static char check(int,
// 				typename T::const_iterator = C().end());
// 			enum {
// 				value = sizeof(check<C>(0)) == sizeof(char),
// 				neg_value = sizeof(check<C>(0)) != sizeof(char)
// 			};
// 		};
// 		template<class T> ostream &_out_str(ostream &os,const T &x) {
// 			return os<<'"'<<x<<'"';
// 		}
// 		template<class T> ostream &_dbg2_5(ostream &,const T &);
// 		template<bool B,typename T=void> using eit=typename enable_if<B,T>::type;
// 		template<class T>
// 		inline ostream &_dbg3(ostream &os,eit<is_iterable<T>::neg_value,const T> &x) {
// 			return os<<x;
// 		}
// 		template<class T>
// 		inline ostream &_dbg3(ostream &os,eit<is_iterable<T>::value,const T> &V) {
// 			os<<"{";
// 			bool ff=0;
// 			for(const auto &E:V) _dbg2_5(ff?os<<",":os,E), ff=1;
// 			return os<<"}";
// 		}
// 		template<>
// 		inline ostream &_dbg3<string>(ostream &os,const string &x) {
// 			return _out_str(os,x);
// 		}
// 		template<>
// 		inline ostream &_dbg3<const char *>(ostream &os,const char *const &x) {
// 			return _out_str(os,x);
// 		}
// 		template<class T> inline ostream &_dbg2_5(ostream &os,const T &x) {
// 			return _dbg3<T>(os,x);
// 		}
// 		template<class T,typename... Args> ostream &_dbg2(ostream &os,vector<string>::iterator nm,const T &x,Args&&... args);
// 		inline ostream &_dbg2(ostream &os,vector<string>::iterator) { return os; }
// 		template<typename... Args>
// 		inline ostream &_dbg2(ostream &os,vector<string>::iterator nm,const char *x,Args&&... args) {
// 			return _dbg2(_dbg3<const char *>(os<<"  ",x),nm+1,args...);
// 		}
// 		template<class T,typename... Args>
// 		inline ostream &_dbg2(ostream &os,vector<string>::iterator nm,const T &x,Args&&... args) {
// 			return _dbg2(_dbg3<T>(os<<"  "<<*nm<<"=",x),nm+1,args...);
// 		}
// 		vector<string> split(string s) {
// 			vector<string> Z;
// 			string z="";
// 			s+=',';
// 			int dep=0;
// 			for(char c:s) {
// 				if(c==',' && !dep) Z.push_back(z),z="";
// 				else z+=c;
// 				if(c=='(') ++dep;
// 				if(c==')') --dep;
// 			}
// 			return Z;
// 		}
// 		template<typename... Args> inline ostream &_dbg1(int ln,const string &nm,Args&&... args) {
// 			auto nms=split(nm);
// 			return _dbg2(cerr<<"L"<<ln<<":",nms.begin(),args...)<<endl;
// 		}
// 	}
// 	#define dbg(...) dbg_ns::_dbg1(__LINE__,#__VA_ARGS__,__VA_ARGS__)
// 	#define sz(x) (int(x.size()))
// 	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
// 	#define fi first
// 	#define se second
// 	#define pb push_back
// // END SUBLIME HAX
// // #include <bits/extc++.h>
// // using namespace __gnu_pbds;
// typedef unsigned long long ull;
// typedef long long ll;
// typedef long double ld; //CARE
// typedef complex<ld> pt;
// const ld eps=(ld)1e-8;
// const ld tau=2*(ld)acosl(-1);
// const int inf=1e9+99;
// const ll linf=1e18+99;
// const int P=1e9+7;

// #include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
template<class T> int sz(const vector<T> &v) { return int(v.size()); }

const int N=1<<19;

int n,m,q;
int u[N],v[N],w[N];

int da[N],rk[N];
int da2[N],rk2[N],st[N];
int qq=3;

int rt(int u) { return da[u]==u ? u : da[u]=rt(da[u]); }
int rt2(int u) {
	if(st[u]!=qq) {
		st[u]=qq;
		da2[u]=rt(u);
		rk2[u]=rk[u];
	}
	return da2[u]==u ? u : da2[u]=rt2(da2[u]);
}
bool un(int u,int v) {
	u=rt(u), v=rt(v);
	if(u==v) return 0;
	if(rk[u]>rk[v]) swap(u,v);
	if(rk[u]==rk[v]) ++rk[v];
	da[u]=v;
	return 1;
}
bool un2(int u,int v) {
	u=rt2(u), v=rt2(v);
	if(u==v) return 0;
	if(rk2[u]>rk2[v]) swap(u,v);
	if(rk2[u]==rk2[v]) ++rk2[v];
	da2[u]=v;
	return 1;
}


vector<pair<int,int> > ES[N];
vector<int> rel[N];
vector<pair<int,pair<int,int> > > QS[N];
int jj[N];
bool FAIL[N];




int32_t main() {
	scanf("%d%d",&n,&m);
	assert(n<N && m<N);
	assert(n>=1 && m>=0);
	for(int i=1;i<=n;i++) da[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",u+i,v+i,w+i);
		u[i]=n+1-u[i];
		v[i]=n+1-v[i];
		w[i]+=33;
		assert(1<=w[i] && w[i]<N);
		assert(u[i]!=v[i]);
		assert(1<=min(u[i],v[i]) && max(u[i],v[i])<=n);
		ES[w[i]].pb(mp(u[i],v[i]));
	}
	scanf("%d",&q); assert(0<=q && q<N);
	for(int i=1;i<=q;i++) {
		int k; scanf("%d",&k);
		assert(1<=k && k<=n-1);
		QS[i].reserve(k);
		for(int j=1;j<=k;j++) {
			int x; scanf("%d",&x);
			assert(1<=x && x<=m);
			QS[i].pb(mp(w[x],mp(u[x],v[x])));
		}
		sort(QS[i].begin(),QS[i].end());
		for(const auto &P:QS[i]) rel[P.fi].pb(i);
	}

	for(int ww=0;ww<N;ww++) {
		if(!sz(ES[ww])) continue;
		sort(rel[ww].begin(),rel[ww].end());
		int pr=-1;
		for(int i:rel[ww]) {
			if(pr==i) continue;
			pr=i;
			if(FAIL[i]) continue;
			++qq;
			assert(qq<N+17);
			assert(QS[i][jj[i]].fi==ww);
			for(;!FAIL[i] && jj[i]<sz(QS[i]) && QS[i][jj[i]].fi==ww;++jj[i]) {
				if(!un2(QS[i][jj[i]].se.fi,QS[i][jj[i]].se.se)) FAIL[i]=1;
			}
		}
		for(const auto &P:ES[ww]) un(P.fi,P.se);
	}
	for(int i=1;i<=q;i++) assert(FAIL[i] || jj[i]==sz(QS[i]));
	for(int i=1;i<=n;i++) assert(rt(i)==rt(1));

	for(int i=1;i<=q;i++) {
		if(FAIL[i]) printf("NO\n");
		else printf("YES\n");
	}
}