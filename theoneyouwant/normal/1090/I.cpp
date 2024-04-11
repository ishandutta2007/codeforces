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
typedef unsigned long long int ull;
const int LIM = 2e5+5, MOD = 1e9+7, EPS = 1e-9;
int t,n,m,k,x,y;
int main(){
	fastio;
	int tests;cin>>tests;
	while(tests--){	
		ll n,r,l;
		ull x,y,z;
		ull b1,b2;
		cin>>n>>l>>r>>x>>y>>z>>b1>>b2;
		ll a[n]= {0};
		ll fans = (ll)6e18;
		ull M = 1LL<<32;
		ull bcurr;
		ll a1= (b1%(r-l+1)) + l;
		ll a2 = (b2%(r-l+1)) + l;
		a[0] = a1;
		a[1] = a2;
		forn(i,n-2){
			bcurr = (b1*x)%M + (b2*y)%M + z;
			bcurr%=M;
			b1 = b2;
			b2 = bcurr;
			a[i+2] = (bcurr%(r-l+1))+l;
		}
		//forn(i,n) cin>>a[i];
		bool neg=0,pos=0;
		ll mnneg=0,mxpos=0,mxneg=-1-2e9,mnpos=1+2e9;
		forn(i,n){
			if(neg){
				if(a[i]>mnneg) fans=min(fans,a[i]*mnneg);
				if(a[i]>mxneg) fans=min(fans,a[i]*mxneg);
			}
			if(pos){
				if(a[i]>mxpos) fans=min(fans,a[i]*mxpos);
				if(a[i]>mnpos) fans=min(fans,a[i]*mnpos);
			}
			if(a[i]>=0){
				pos|=1;
				mxpos=max(mxpos,a[i]);
				mnpos=min(mnpos,a[i]);
			}
			if(a[i]<0){
				neg|=1;
				mnneg=min(mnneg,a[i]);
				mxneg=max(mxneg,a[i]);
			}
			a[i]=-a[i];
		}
		pos=0;
		mxpos=0,mnpos=2e9+1;
		rforn(i,n-1){
			if(a[i]>0){
				if(pos){
					if(a[i]>mnpos) fans=min(fans,mnpos*a[i]);
				}
				pos|=1;
				mnpos=min(mnpos,a[i]);
			}
		}
		if(fans!=(ll)6e18) cout<<fans<<ln;
		else cout<<"IMPOSSIBLE"<<ln;
	}
	return 0;
}