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

int rowcon;
int rowdata[10][5];
int n,m;

ll solve(int r1, int r2, int r3, int r4, int pos){
	if(pos == rowcon) return (r1+r2+r3+r4);
	
	ll answer = 0;
	if(n == 1){
		
		answer = solve(max(r1,rowdata[pos][0]),r2,r3,r4,pos+1);
	}
	else if(n == 2){
		
		answer = solve(max(r1,rowdata[pos][0]),max(r2,rowdata[pos][1]),r3,r4,pos+1);
		answer = max(answer,solve(max(r1,rowdata[pos][1]),max(r2,rowdata[pos][0]),r3,r4,pos+1));
	}
	else if(n == 3){
		
		answer = solve(max(r1,rowdata[pos][0]),max(r2,rowdata[pos][1]),max(r3,rowdata[pos][2]),r4,pos+1);
		answer = max(answer,solve(max(r1,rowdata[pos][2]),max(r2,rowdata[pos][0]),max(r3,rowdata[pos][1]),r4,pos+1));
		answer = max(answer,solve(max(r1,rowdata[pos][1]),max(r2,rowdata[pos][2]),max(r3,rowdata[pos][0]),r4,pos+1));	
	}
	else{
		
		answer = solve(max(r1,rowdata[pos][0]),max(r2,rowdata[pos][1]),max(r3,rowdata[pos][2]),max(r4,rowdata[pos][3]),pos+1);
		answer = max(answer,solve(max(r1,rowdata[pos][3]),max(r2,rowdata[pos][0]),max(r3,rowdata[pos][1]),max(r4,rowdata[pos][2]),pos+1));
		answer = max(answer,solve(max(r1,rowdata[pos][2]),max(r2,rowdata[pos][3]),max(r3,rowdata[pos][0]),max(r4,rowdata[pos][1]),pos+1));
		answer = max(answer,solve(max(r1,rowdata[pos][1]),max(r2,rowdata[pos][2]),max(r3,rowdata[pos][3]),max(r4,rowdata[pos][0]),pos+1));
	}
	return answer;
}

int main(){
	fastio;
	int tests;cin>>tests;
	while(tests--)
	{	
		forn(i,10){
			forn(j,5){
				rowdata[i][j] = 0;
			}
		}
		rowcon = 0;
		
		cin>>n>>m;

		int val[m] = {0};
		int a[n][m];
		forn(i,n){
			forn(j,m){
				cin>>a[i][j];
			}
		}
		forn(j,m){
			forn(i,n){
				val[j] = max(val[j], a[i][j]);
			}
		}
		vp32 v;
		forn(i,m){
			v.pb(mp(val[i],i));
		}
		sort(v.begin(),v.end(),greater<p32>());
		rowcon = min(m,4);
		forn(i,rowcon){
			forn(j,n){
				rowdata[i][j] = a[j][v[i].se];
				// cout<<i<<" "<<j<<" "<<rowdata[i][j]<<ln;
			}
		}
		// cout<<rowcon<<ln;
		// forn(i,rowcon){
		// 	cout<<i+1<<ln;
		// }
		cout<<solve(0, 0, 0, 0, 0)<<ln;
	}
	return 0;
}