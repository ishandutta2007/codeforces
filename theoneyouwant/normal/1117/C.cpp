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
ll n, totl, totr;

bool check(ll toright, ll curright,ll toup, ll currup,ll k, ll actions){
	if(abs(toright-curright-k*totr)+abs(toup-currup-k*totl)<=k*n+actions) return 1;
	return 0;
}

ll binsearch(ll toright, ll curright,ll toup, ll currup, ll actions){
	ll l=0;
	ll r=1e10;
	ll mid;
	while(l<=r){
		mid = (l+r)/2;
		//cout<<mid<<ln;
		bool b = check(toright,curright,toup,currup,mid,actions);
		if(b==1 && !check(toright,curright,toup,currup,mid-1,actions)){
			break;
		}
		else if(b){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return mid;
}	


int main(){
	fastio;
	ll x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	string s;
	cin>>s;
	bool possible=1, done=0;
	ll toright = x2-x1, toup = y2-y1;
	ll pup[n]={0},pright[n]={0};
	ll ans =1e15;
	ll initdist = abs(toright)+abs(toup);
	ll maxlength = 0;
	//cout<<toright<<" "<<toup<<ln;
	forn(i,s.length()){
		if(i==0){
			pup[i] = (int)(s[i]=='U')-(int)(s[i]=='D');
			pright[i] = -(int)(s[i]=='L')+(int)(s[i]=='R');
		}
		else{
			pup[i] = pup[i-1]+(int)(s[i]=='U')-(int)(s[i]=='D');
			pright[i] = pright[i-1]-(int)(s[i]=='L')+(int)(s[i]=='R');
		}
		if(abs(toright-pright[i])+abs(toup-pup[i])<=i+1){
			ans = i+1;
			done=1;
			break;
		}
		//cout<<i<<" "<<pup[i]<<" "<<pright[i]<<ln;
	}
	if(done){
		cout<<ans<<ln;
	}
	else{

		totr = pright[n-1];
		totl = pup[n-1];
		//cout<<initdist<<ln;
		if(initdist<=abs(toright-totr)+abs(toup-totl)-n){
			possible=0;
		}
		else{
			forn(i,n){
				ll finalans=0;
				finalans = i+1+(ll)n*binsearch(toright,pright[i],toup,pup[i],i+1);
				//cout<<i<<" "<<toright<<" "<<pright[i]<<" "<<toup<<" "<<pup[i]<<ln;
				//cout<<totr<<" "<<totl<<ln;
				ans = min(ans,finalans);
			}
		}
		if(possible && ans<1e15) cout<<ans<<ln;
		else cout<<-1<<ln;
	}
	return 0;
}