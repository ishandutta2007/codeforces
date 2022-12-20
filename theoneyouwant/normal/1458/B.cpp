//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld dp[2][101][10001];

int main(){
	fastio;

	int n; cin>>n;

	vp64 v;
	forn(i,n){
		ll a, b; cin>>a>>b;
		v.pb(mp(a,b));
	}
	sort(all(v), greater<p64>());

	ll a[n], b[n];
	forn(i,n){
		a[i] = v[i].fi;
		b[i] = v[i].se;
	}
	// cerr<<"OK"<<endl;
	// n -> number of glasses = 10^2
	// k -> number taken = 10^2
	// c -> total capacity = 100 * 100 = 10^4
	// dp[n][k][c] = max filled

	forn(i,2){
		forn(j,n+1){
			forn(k,100*n + 1){
				// cerr<<i<<" "<<j<<" "<<k<<endl;
				dp[i][j][k] = -MOD;
				if(j == 0 && k == 0) dp[i][j][k] = 0;
			}
		}
	}

	// cerr<<"OK"<<endl;

	forn(i,n){
		int curr = i%2;
		int prev = (i+1)%2;
		forn(j,n+1){
			forn(k,100*n+1){
				dp[curr][j][k] = dp[prev][j][k];
			}
		}
		forn(j,n+1){
			forn(k,100*n+1){
				// either take this
				// or fill something
				dp[curr][j][k] = max(dp[curr][j][k], dp[prev][j][k]+((ld)b[i])/2.0);
				if(k >= a[i]){
					if(j != 0) dp[curr][j][k] = max(dp[curr][j][k], dp[prev][j-1][k-a[i]] + b[i]);
					else if(j == 1 && k == a[i]) dp[curr][j][k] = max(dp[curr][j][k], (ld)b[i]);
				}
			}
		}
		// cout<<"check "<<i<<" "<<dp[curr][1][10]<<ln;
	}

	int curr = (n-1)%2;
	cout<<setprecision(12)<<fixed;
	forsn(j,1,n+1){
		ld ans = 0;
		forn(k,100*n+1){
			ans = max(ans, min((ld)k,dp[curr][j][k]));
		}
		cout<<ans<<" ";
	}
	cout<<ln;

	return 0;
}