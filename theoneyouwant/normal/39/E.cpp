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
const int LIM=1e5+5;
const ll MOD=1e9+7;
const ld EPS = 1e-9;

int dp[LIM][35];

int main(){
	fastio;

	ll a, b, n;
	cin>>a>>b>>n;

	forn(i,LIM){
		forn(j,35) dp[i][j] = -1;
	}

	ll val[LIM][35];
	forn(i,LIM){
		forn(j,35) val[i][j] = 0;
	}


	forn(i,LIM){
		forn(j,35){
			if(j == 0){
				val[i][j] = 1;
			}
			else{
				val[i][j] = min(val[i][j-1]*i, MOD);
			}
		}
	}

	forn(i,LIM){
		forn(j,35){
			if(val[i][j]>=n) dp[i][j] = 0;
		}
	}

	rforn(i, LIM-1){
		rforn(j,34){
			if(dp[i][j]!=-1) continue;

			if(j == 34){
				if(dp[i+1][j] == 0) dp[i][j] = 1;
				else dp[i][j] = 0;
				continue;
			}

			if(i == LIM-1){
				if(dp[i][j+1]==1) dp[i][j] = 0;
				else dp[i][j] = 1;
			}

			bool done = 0;

			if(dp[i+1][j]==1 || dp[i][j+1]==1) done = 1;

			if(done) dp[i][j] = 0;
			else dp[i][j] = 1;
		}
	}
	// forsn(i,1,2){
	// 	forsn(j,1,35){
	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<ln;
	// 	}
	// }

	// if(a == 1){
	// 	if((1LL<<(b+1)) >= n) cout<<"Missing"<<ln;
	// 	else{
	// 		if(dp[a][b] == 0) cout<<"Masha"<<ln;
	// 		else cout<<"Stas"<<ln;
	// 	}
	// 	return 0;
	// }


	if(a == 1){
		if(dp[a+1][b] == 1){
			cout<<"Masha"<<ln;
		}
		else{
			int p = 0;
			forsn(i,b,35){
				// cout<<i<<" "<<dp[1][i]<<ln;
				if(dp[2][i] == 1){
					p = i;
					break;
				}
			} 
			// cout<<p<<ln;
			if(p == 0) cout<<"Missing"<<ln;
			else{
				if((p-b)%2==0) cout<<"Masha"<<ln;
				else cout<<"Stas"<<ln;
			}
		}
		// else cout<<"Missing"<<ln;
		return 0;
	}

	if(dp[a][b] == 0) cout<<"Masha"<<ln;
	else cout<<"Stas"<<ln;


	return 0;
}