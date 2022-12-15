//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int ll
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

signed main(){
	fastio;

	int n; cin>>n;
	ll m[n]; forn(i,n) cin>>m[i];
	int allot[n] = {0};
	stack<p32> s;
	ll ans[n] = {0};
	ans[0] = m[0];
	s.push(mp(m[0],0));

	forsn(i,1,n){
		while(!s.empty() && m[i]<s.top().fi){
			s.pop();
		}
		if(s.empty()){
			ans[i] = m[i]*(i+1);
		}
		else{
			int ind = s.top().se;
			ans[i] = m[i]*(i-ind)+ans[ind];
		}
		s.push(mp(m[i],i));
	}

	while(!s.empty()) s.pop();

	ll ans2[n] = {0};
	ans2[n-1] = m[n-1];
	s.push(mp(m[n-1],n-1));

	rforn(i,n-2){
		while(!s.empty() && m[i]<s.top().fi){
			s.pop();
		}
		if(s.empty()){
			ans2[i] = m[i]*(n-i);
		}
		else{
			int ind = s.top().se;
			ans2[i] = m[i]*(ind-i)+ans2[ind];
		}
		s.push(mp(m[i],i));
	}

	ll ind = -1; ll mx = 0;
	forn(i,n){
		// cout<<i<<" "<<ans[i]<<" "<<ans2[i]<<ln;
		if(ans[i]+ans2[i]-m[i]>=mx){
			// cout<<ans[i]+ans2[i]-m[i]<<" "<<i<<ln;
			mx = ans[i]+ans2[i]-m[i];
			ind = i;
		}
	}

	forn(k,1){
		int i = ind;
		ll temp = 0;
		ll take[n] = {0};
		take[i] = m[i];
		temp += m[i];
		forsn(j,i+1,n){
			take[j] = min(take[j-1],m[j]);
			temp += take[j];
		}
		rforn(j,i-1){
			take[j] = min(take[j+1],m[j]);
			temp += take[j];
		}
		if(temp>-1){
			forn(j,n) allot[j] = take[j];
		}
	}

	forn(i,n) cout<<allot[i]<<" ";
	cout<<ln;
	// cout<<ans<<ln;

	return 0;
}