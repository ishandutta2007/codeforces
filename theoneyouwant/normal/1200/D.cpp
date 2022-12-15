//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
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
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const ll MOD = 1e9+7, LIM = 1e5+5;
const ld EPS = 1e-9;
int n,k;



int main(){
	fastio;
	int n,k;
	cin>>n>>k;

	string s[n];
	forn(i,n) cin>>s[i];

	int row[n][2];
	int col[n][2];
	forn(i,n){
		row[i][0] = LIM;
		row[i][1] = -1;
		col[i][0] = LIM;
		col[i][1] = -1;
	}

	forn(i,n){
		forn(j,n){
			if(s[i][j] == 'B'){
				row[i][0] = min(row[i][0],j);
				row[i][1] = max(row[i][1],j);
				col[j][0] = min(col[j][0],i);
				col[j][1] = max(col[j][1],i);
			}
		}
	}
	int c = 0;
	forn(i,n){
		if(row[i][1] == -1) c++;
		if(col[i][1] == -1) c++;
	}
	// forn(i,n){
	// 	// cout<<i<<" "<<row[i][0]<<" "<<row[i][1]<<ln;
	// 	// cout<<i<<" "<<col[i][0]<<" "<<col[i][1]<<ln;
	// }

	int ans[n][n];
	int ans2[n][n];
	forn(i,n){
		forn(j,n){
			ans[i][j] = 0;
			ans2[i][j] = 0;
		}
	}

	rforn(j,n-1){
		rforn(i,n-1){
			if(i>=n-k){
				if(row[i][0]>=j && row[i][1]<j+k && row[i][1]!=-1) ans[i][j]++;
				if(i!=n-1) ans[i][j] += ans[i+1][j];
				continue;
			}
			ans[i][j] = ans[i+1][j];
			if(row[i][0]>=j && row[i][1]<j+k && row[i][1]!=-1) ans[i][j]++;
			if(row[i+k][0]>=j && row[i+k][1]<j+k && row[i+k][1]!=-1) ans[i][j]--;
		}
	}

	rforn(i,n-1){
		rforn(j,n-1){
			if(j>=n-k){
				if(col[j][0]>=i && col[j][1]<i+k && col[j][1]!=-1) ans2[i][j]++;
				if(j!=n-1) ans2[i][j] += ans2[i][j+1];
				continue;
			}
			ans2[i][j] = ans2[i][j+1];
			if(col[j][0]>=i && col[j][1]<i+k && col[j][1]!=-1) ans2[i][j]++;
			if(col[j+k][0]>=i && col[j+k][1]<i+k && col[j+k][1]!=-1) ans2[i][j]--;
		}
	}
	int maxval = 0;
	forn(i,n){
		forn(j,n){
			// cout<<i<<" "<<j<<" "<<ans[i][j]<<" "<<ans2[i][j]<<ln;
			maxval = max(maxval,ans[i][j]+ans2[i][j]);
		}
	}
	cout<<maxval+c<<ln;
	
	 
	return 0;
}