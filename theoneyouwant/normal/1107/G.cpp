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
const int LIM = 3e5+5, MOD = 1e9+7, EPS = 1e-9;
ll d[LIM],prof[LIM];
	ll n,a;

ll solve(ll l,ll r){
	if(l>r) return 0;
	if(l==r) return max(0LL,prof[l]);
	 if(r==l+1){
	 	ll z = 0;
	 	z = max(z,prof[l]);
	 	z = max(z,prof[r]);
	 	z = max(z,prof[l]+prof[r]-(d[r]-d[l])*(d[r]-d[l]));
	 	return z;
	 }
	ll z = (l+r)/2;
	ll ans = 0;
	ans = max({ans,solve(l,z),solve(z,r)});
	//if(ans==16) cout<<"HERE"<<ln;
	ll currdiff=0;
	ll y = prof[z];
	ll j = z-1,i=z+1;
	//cout<<z<<ln;
	ll rmaxoverall=0,lmaxoverall=0;
	ll r1=0,l1=0;
	while(i<=r || j>=l){
		while(i<=r && (d[i]-d[i-1])*(d[i]-d[i-1])<=currdiff){
			//cout<<"HERE "<<i<<" "<<j<<" "<<currdiff<<" "<<y<<ln;
			r1+=prof[i];
			rmaxoverall = max(rmaxoverall,r1);
			i++;
		}
		while(j>=l && (d[j]-d[j+1])*(d[j]-d[j+1])<=currdiff){
			l1+=prof[j];
			lmaxoverall = max(lmaxoverall,l1);
			j--;
		}
		ans = max(ans,lmaxoverall+rmaxoverall+prof[z]-currdiff);
	//	if(n==300000 && a== 644299426 && ans==43256190809837) cout<<i<<" "<<j<<ln;
		//cout<<"HERE "<<y<<ln;
		//if(ans==16) cout<<currdiff<<" "<<i<<" "<<j<<" "<<l<<" "<<r<<ln;
		if(i>r && j<l) break;
		else if (j<l) currdiff = (d[i]-d[i-1])*(d[i]-d[i-1]);
		else if (i>r) currdiff = (d[j]-d[j+1])*(d[j]-d[j+1]);
		else currdiff = min((d[i]-d[i-1])*(d[i]-d[i-1]),(d[j]-d[j+1])*(d[j]-d[j+1]));
		//cout<<"HERE "<<y<<ln;
	}
	return ans;
}

int main(){
	fastio;
	cin>>n>>a;
	forn(i,LIM){
		d[i]=0;
		prof[i]=0;
	}
	forn(i,n){
		ll x,y;
		cin>>x>>y;
		d[i]=x;
		prof[i] = a-y;
	}
	//forn(i,n) cout<<i<<" "<<d[i]<<ln;
	//cout<<solve(1,3)<<ln;
	cout<<solve(0,n-1)<<ln;
	return 0;
}