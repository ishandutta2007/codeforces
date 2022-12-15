//By Tushar Gautam
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
const int LIM=2e6+5,MOD=1e9+7;
int t,n,m,k,x,y,w;
int a[LIM];
int b[LIM];
int sss[LIM],cc[LIM];
signed main(){
	fastio;
	cin>>t;
	forn(ii,t){
		cin>>n;
		forn(i,n){
			cin>>x; --x;
			a[x]++;
		}
		int c=0;
		forn(i,n) if(a[i]>0) b[a[i]]++,c++;
		forsn(i,1,1+n){
			if(b[i]>0){
				bool c[i+3] = {0};
				int ss[i+3];
				forn(j,i+2) ss[j+1]=MOD;
				ss[1]=i;c[1]=1;
				ss[2]=(i+1)/2,c[2]=1;
				forsn(s,3,i+2){
					int t=i%(s-1);
					int t1=t+((i/s - t)/(s-1))*(s-1);
					int cc=(i-t1)/(s-1);
					if(cc>=t1 && i/s>=t && t1<=i){
						// dbg(i,s,b[i],cc);
						ss[s] = min(cc,ss[s]);
						c[s] = 1;
					}
				}
				forn(j,i+1) if(c[j+1]){
					sss[j+1] += ss[j+1]*b[i];
					cc[j+1] += b[i];
					// dbg(j+1,cc[j+1],ss[j+1],sss[j+1]);
				}
			}
		}
		int ans = n;
		forn(i,n+1){
			if(cc[i+1]==c){
				ans = min(sss[i+1],ans);
			}
		}
		cout<< ans <<ln;
		forn(i,n+1) a[i]=0,b[i+1]=0,sss[i+1]=0,cc[i+1]=0;
	}
	return 0;
}