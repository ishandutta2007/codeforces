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
	ll n,m,k;
	cin>>n;
	ll a[n/2];
	forn(i,n/2) cin>>a[i];
	ll b[n+1] = {0};
	b[n] = 1e14;
	forn(i,n){
		if(i%2==1) b[i] = a[i/2];
	}
	vector<ll> v1,v2;
	forsn(i,1,sqrt(1e13)+1+EPS){
		v2.pb((ll)i*i);
	}
//	forstl(r,v2) cout<<r<<" ";
	v1 = v2;
	forn(i,1){
		v2.clear();
		//cout<<"ok"<<ln;
		map<ll,ll> m;
		//	cout<<"ok"<<ln;
		for(int j=sqrt(a[i])+EPS;j>=1;j--){
			if(a[i]%j==0){
				if((a[i]/j-j)%2==0 && a[i]/j !=j){
					v2.pb((a[i]/j-j)/2 * (a[i]/j-j)/2);
				
					m[(a[i]/j-j)/2 * ((a[i]/j)-j)/2] = (a[i]/j+j)/2 * (a[i]/j+j)/2;
				}
			}
		}
	//	cout<<i<<" ";
	
		vector<ll> v3;
		std::set_intersection(  v1.begin(), v1.end(),
                        v2.begin(), v2.end(),
                        std::back_inserter(v3) );
		v1.clear();
		forstl(r,v3){
			v1.pb(r);
		}
		//if(i==0)	forstl(r,v1) cout<<r<<" "; 
	}
	if(v1.size()==0){
		cout<<"No"<<ln;
		return 0;
	}
	b[0] = v1[0];
	ll curr = b[0]+b[1];
	forsn(i,1,n/2){
		forsn(j,1,sqrt(b[2*i+1]+EPS)){
			if(b[2*i+1]%j==0){
				if((b[2*i+1]/j -j)%2==0 && (b[2*i+1]/j -j)/2*(b[2*i+1]/j -j)/2>curr){
					b[2*i] = (b[2*i+1]/j -j)/2*(b[2*i+1]/j -j)/2 - curr; 
				}
			}
		}
		curr+=b[2*i];
		curr+=b[2*i+1];
	}
//	forn(i,n) cout<<b[i]<<" ";
	bool p=1;
	forn(i,n){
		if(b[i]<1 || b[i]>1e13) p=0;
	}
	if(!p) cout<<"No"<<ln;
	else{
		cout<<"Yes"<<ln;
		forn(i,n) cout<<b[i]<<" ";
	}
	return 0;
}