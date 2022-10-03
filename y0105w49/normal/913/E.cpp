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





string ans[256];
string cache[5][256];

void filter(vector<pair<string,int> > &v,int ii) {
	int n=0;
	sort(v.begin(),v.end());
	for(const auto &P:v) if(!sz(cache[ii][P.se]) || P.fi<cache[ii][P.se])
		cache[ii][P.se]=P.fi;
	for(int i=0;i<sz(v);i++) {
		int mk=v[i].se;
		if(sz(cache[ii][mk])) {
			if(sz(cache[ii][mk])<sz(v[i].fi)) continue;
			v[i].fi=cache[ii][mk];
		}
		v[n++]=v[i];
	}
	sort(v.begin(),v.begin()+n);
	v.resize(unique(v.begin(),v.begin()+n)-v.begin());
}

vector<pair<string,int> > F(int);
vector<pair<string,int> > T(int);

vector<pair<string,int> > E(int l) {
	if(!l) return {};
	static bool seen[32];
	static vector<pair<string,int> > dp[32];
	if(seen[l]) return dp[l];
	seen[l]=1;
	vector<pair<string,int> > &ans=dp[l];
	ans=T(l);
	for(int a=2;a<l;a++) {
		auto v=E(a-1);
		auto w=T(l-a);
		for(const auto &P:v) for(const auto &Q:w) {
			ans.pb({P.fi+"|"+Q.fi,P.se|Q.se});
		}
	}
	filter(ans,0);
	return ans;
}
vector<pair<string,int> > T(int l) {
	static bool seen[32];
	static vector<pair<string,int> > dp[32];
	if(seen[l]) return dp[l];
	seen[l]=1;
	vector<pair<string,int> > &ans=dp[l];
	ans=F(l);
	for(int a=2;a<l;a++) {
		auto v=T(a-1);
		auto w=F(l-a);
		for(const auto &P:v) for(const auto &Q:w) {
			ans.pb({P.fi+"&"+Q.fi,P.se&Q.se});
		}
	}
	filter(ans,1);
	return ans;
}
vector<pair<string,int> > F(int l) {
	static bool seen[32];
	static vector<pair<string,int> > dp[32];
	if(seen[l]) return dp[l];
	seen[l]=1;
	vector<pair<string,int> > &ans=dp[l];
	if(l<=2) {
		ans.pb({"x",0x0F});
		ans.pb({"y",0x33});
		ans.pb({"z",0x55});
		if(l==2) for(auto &P:ans) {
			P.fi="!"+P.fi;
			P.se^=0xFF;
		}
		return ans;
	}
	vector<pair<string,int> > ans1=E(l-2);
	for(auto &P:ans1) P.fi="("+P.fi+")";
	vector<pair<string,int> > ans2=E(l-3);
	for(auto &P:ans2) P.fi="!("+P.fi+")", P.se^=0xFF;
	for(const auto &P:ans1) ans.pb(P);
	for(const auto &P:ans2) ans.pb(P);
	filter(ans,2);
	return ans;
}



int32_t main() {
	ans[105]="!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
	ans[150]="!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
	for(int l=1;;l++) {
		dbg(l);
		auto v=E(l);
		sort(v.begin(),v.end());
		for(const auto &P:v)
			if(!sz(ans[P.se])) ans[P.se]=P.fi;
		// if(l==7) dbg(v);
		for(int i=0;i<256;i++) if(sz(ans[i])==l) dbg(i,ans[i]);
		if(l>=15) for(int i=0;i<256;i++) if(!sz(ans[i])) dbg(l,i);
		for(int i=0;i<256;i++) if(!sz(ans[i])) goto ctu;
		break;
		ctu:;
		// if(l==14) break;
	}

	int n; scanf("%d",&n);
	for(;n--;) {
		static char s[12]; scanf("%s",s);
		int x=0;
		for(int i=0;i<8;i++) x<<=1, x|=(s[i]-'0');
		printf("%s\n",ans[x].c_str());
	}
}