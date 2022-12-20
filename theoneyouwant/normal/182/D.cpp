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
vector<string> v;
int main(){
	fastio;
	string a,b;
	cin>>a>>b;
//	cout<<a[0]<<a[2]<<a[3]<<ln;
//	cout<<a<<" "<<a.length()<<ln;
	forn(i,a.length())
	{
//		cout<<i<<" "<<a.length()<<ln;
		if((a.length()%(i+1))!=0) continue;
	//	cout<<a.length()<<" "<<i+1<<ln;
		ll p=1;
		bool y=1;
		forn(j,i+1)
		{
			p=1;
			while((i+1)*p+j<a.length())
			{
				if(a[(i+1)*p+j]!=a[j]){
				//	cout<<i<<" "<<j<<" "<<p<<ln;
					y=0;
					break;
				}
				p++;
			}
		}
		if(y){
			v.pb(a.substr(0,i+1));
		}
	}
	int ans=0;
//	cout<<a.length()<<ln;
	forstl(r,v){
//		cout<<r.length()<<" "<<r<<ln;
		bool q=1;
		if(b.size()%r.size()!=0) continue;
		forn(j,r.size())
		{
			ll p=0;
			while(r.size()*p+j<b.size())
			{
			//	cout<<"OK"<<ln;
			//	cout<<r<<" "<<r.size()<<" "<<j<<" "<<b.size()<<ln;
				if(b[(r.size())*(ll)p+j]!=r[j]){
					q=0;
					break;
				}
				p++;
			}
		}
		if(q){
			//cout<<r<<ln;
			ans++;
		}
	}
	cout<<ans<<ln;
	return 0;
}