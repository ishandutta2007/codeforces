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

ll n,a,r,m;
ll cost[LIM];

ll co(ll mid){

	ll ext = 0, rem = 0;
	ll ans = 0;
	forn(i,n){
		if(cost[i]>mid){
			ext += cost[i]-mid;
		}
		else{
			rem += mid-cost[i];
		}
	}
	if(m<a+r){
		ll g = min(ext,rem);
		ans += g*m;
		ext -= g;
		rem -= g;
	}
	ans += a*rem;
	ans += r*ext;
	return ans;

}

int main(){
	fastio;

	cin>>n>>a>>r>>m;
	forn(i,n) cin>>cost[i];

	sort(cost,cost+n);

	ll l = 0, r = 1e9+1, mid1 = 0, mid2 = 0;
	ll ans = -1;

	if(co(0)<co(1)){
		cout<<co(0)<<ln;
		return 0;
	}

	while(true){
		mid1 = l+(r-l)/3;
		mid2 = r-(r-l)/3;

		if(co(mid1)<co(mid1-1) && co(mid1)<co(mid1+1)){
			ans = mid1;
			break;
		}
		if(co(mid2)<co(mid2-1) && co(mid2)<co(mid2+1)){
			ans = mid2;
			break;
		}
		if(co(mid1)<co(mid1+1)){
			r = mid1-1;
		}
		else if(co(mid2)>co(mid2+1)){
			l = mid2+1;
		}
		else{
			l = mid1+1;
			r = mid2-1;
		}
	}

	cout<<co(ans)<<ln;

	return 0;
}