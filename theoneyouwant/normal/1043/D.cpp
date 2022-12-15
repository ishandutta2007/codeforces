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
#define dbgm(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
typedef long long int  ll;
typedef long double  ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM = 2e5+5, MOD = 1e9+7;
int t,n,m,k,x,y;
int main(){
	fastio;
	cin>>n>>m;
	int a[n][m];
	int pos[m][n+1];
	forn(i,m){
		forn(j,n){
			cin>>a[j][i];
			pos[i][a[j][i]] = j;
		//	cout<<a[j][i]<<" ";
		}
	//	cout<<ln;
	}
	ll answer = 0;
	forn(i,n){
//		cout<<i<<ln;
		int s = i;
		int q = s;
		ll maxl = n;
		ll curr[m];
		forn(j,m){
			curr[j] = pos[j][a[s][0]];
		}
		ll currl = 1;
		bool br = 0;
		while(true){
			forn(j,m){
				if(curr[j]>=n-1) br = 1;
			}
			if(br==1) break;
			forn(j,m){
				if(a[curr[j]+1][j]!=a[curr[0]+1][0]) br = 1;
			}
			if(br==1) break;
			currl++;
			forn(j,m){
				curr[j]++;
			}
		//	cout<<" loop "<<ln;
		}
		    s = curr[0];
	//	    cout<<s<<ln;
			maxl = min(maxl,currl);
			answer+=(maxl)*(maxl+1)/2;
			i = s;
		//	cout<<s<<ln;
		}
	cout<<answer<<ln;
	return 0;
}