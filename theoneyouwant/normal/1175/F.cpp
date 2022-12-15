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

	int n; cin>>n;
	ll a[n+1];
	ll pref[n+2] = {0};
	forn(i,n) cin>>a[i+1];
	a[0] = 0;

	forsn(i,1,n+1){
		pref[i] = pref[i-1] + a[i];
	}
	pref[n+1] = pref[n];

	int left[n+1], cleft[n+1];

	left[0] = 0, cleft[0] = 0;
	m32 m;
	forsn(i,1,n+1){
		left[i] = m[a[i]]+1;
		cleft[i] = max(left[i], cleft[i-1]);
		m[a[i]] = i;
	}

	int right[n+2], cright[n+2];
	right[n+1] = n+1, cright[n+1] = n+1;
	m.clear();

	rforsn(i,n,1){
		right[i] = m[a[i]]-1;
		if(right[i] == -1) right[i] = n;
		cright[i] = min(right[i], cright[i+1]);
		m[a[i]] = i;
	}

	int ans = 0;

	forsn(i,1,n+1){
		if(a[i] == 1){
			ans++;
			ll mx = 1;
			int j = i+1;
			while(true){
				if(j == n+1) break;
				if(a[j] == 1) break;
				mx = max(mx, a[j]);
				int lpos = j - mx + 1;
				if(cleft[j] <= lpos){
					if(pref[j] - pref[lpos-1] == mx * (mx + 1) / 2) ans++;
				}
				j++;
			}
			mx = 1;
			j = i-1;
			while(true){
				if(j == 0) break;
				if(a[j] == 1) break;
				mx = max(mx, a[j]);
				int rpos = j + mx - 1;
				if(cright[j] >= rpos){
					if(pref[rpos] - pref[j-1] == mx * (mx + 1) / 2) ans++;
				}
				j--;
			}
		}
	}

	cout<<ans<<ln;

	return 0;
}