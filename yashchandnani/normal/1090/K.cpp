//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(int i=0;i<(int)a;i++)
#define repp(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define fill(a,x) memset(a,x,sizeof(a))
#define foreach( gg, itit) for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
typedef vector<int> VI;
const int mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;
#define N5 100005

#define ld long double
//#define double long double
const ld EPS=1e-12;

vector<pair<string, string> > vec;
map<pair<string,string>, int> ma;
string S[100005];
string T[100005];

vector<vector<int> > comp;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,n){
		string s,t;
		cin>>s>>t;
		int m = s.size();
		int pt=m;
		int a[26];
		rep(i,26)a[i]=0;
		rep(i,t.size()){
			a[(int)(t[i]-'a')]=1;
		}
		for(int i=m-1;i>=0;i--){
			if(a[(int)(s[i]-'a')]){
				pt=i;
			}else{
				break;
			}
		}
		string ss;
		rep(i,pt)ss+=s[i];
		string tt;
		rep(i,26){
			if(a[i]){
				tt += (char)(i+'a');
			}
		}
		vec.pb(mp(tt, ss));
		S[i] = ss;
		T[i] = tt;
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	int ans = (int)(vec.size());
	cout<<ans<<endl;
	rep(i,vec.size()){
		ma[vec[i]]=i;
	}
	comp.resize(n+5);
	rep(i,n){
		int cp = ma[mp(T[i], S[i])];
		comp[cp].pb(i+1);
	}
	rep(i,ans){
		cout<<comp[i].size()<<" ";
		rep(j,comp[i].size()){
			cout<<comp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}