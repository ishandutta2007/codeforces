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
const int LIM = 2e5+5, MOD = 1e9+7, EPS = 1e-9;
int t,n,m,k,x,y;
int main(){
	fastio;
	cin>>n>>m;
	vp32 v;
	forn(i,m){
		cin>>x>>y;
		if(x<y) v.pb(mp(x,y));
		else v.pb(mp(y,x));
	}
	sort(v.begin(),v.end());
	if(v.size()==n*(n-1)/2 || n==1){
		cout<<"NO"<<ln;
		return 0;
	}
	cout<<"YES"<<ln;
	int a[n] = {0};
	int b[n] = {0};
	bool f = 0;
	p32 r;
	int qw = 0;
	forsn(i,1,n+1){
		forsn(j,i+1,n+1){
			if(qw>=v.size()){
				r = mp(i,j);
				f=1;
				break;
			}
			if(v[qw].first!=i || v[qw].second!=j){
				r = mp(i,j);
				f=1;
				break;
			}
			qw++;
		}
	if(f) break;
	}
	a[r.first-1] = 1;
	a[r.second-1] = 1;
	b[r.first-1]  = 1;
	b[r.second-1] = 2;
	int y=3;
	forn(i,n){
		if(i== r.first-1){
			continue;
		}
		if(i==r.second-1){
			continue;
		}
		a[i] = y;
		b[i] = y;
		y++;
	}
	forn(i,n){
		cout<<b[i]<<" ";
	}
	cout<<ln;
	forn(i,n){
		cout<<a[i]<<" ";
	}
	cout<<ln;
	return 0;
}