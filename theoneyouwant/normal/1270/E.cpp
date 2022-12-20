//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;

	int n;
	cin>>n;
	vector<pair<p32,int>> v[4];

	forn(i,n){
		int x,y;
		cin>>x>>y;
		x += 1e6;
		y += 1e6;
		int cnt = 2*(x%2)+(y%2);
		v[cnt].pb(mp(mp(x,y),i+1));
	}
	while(true){
		bool p = 1;
		forn(i,4){
			if(v[i].size() == n) p = 0;
		}
		if(p) break;
		// cout<<"WTF"<<ln;
		vector<pair<p32,int>> newv[4];
		forn(i,4){
			forstl(r,v[i]){
				r.fi.fi /= 2;
				r.fi.se /= 2;
				int cnt = 2*(r.fi.fi%2)+(r.fi.se%2);
				// cout<<i<<" "<<r<<" "<<cnt<<endl;
				newv[cnt].pb(r);
			}
		}
		forn(i,4) v[i].clear();
		forn(i,4){
			forstl(r,newv[i]) v[i].pb(r);
		}
	}
	v32 ans;
	if((v[0].size()+v[3].size() == n) || (v[1].size()+v[2].size() == n)){
		forstl(r,v[0]) ans.pb(r.se);
		forstl(r,v[1]) ans.pb(r.se);
	}
	else{
		forstl(r,v[0]) ans.pb(r.se);
		forstl(r,v[3]) ans.pb(r.se);
	}
	cout<<ans.size()<<ln;
	forstl(r,ans) cout<<r<<" ";
	cout<<ln;

	return 0;
}