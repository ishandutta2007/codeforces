//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ans(v32 v){

	int last = -1;
	int curr = 0;
	int n = v.size();
	int rem[n] = {0};

	// cout << "started " << v << ln;

	forn(i, v.size()){
		if(last==v[i]) curr++;
		else{
			if(curr>=3){
				for(int j = i-1; j >= i-curr; j--){
					rem[j]=1;
				}
			}
			curr=1;
		}
		last=v[i];
	}
	if(curr>=3){
		for(int j = n-1; j >= n-curr; j--){
			rem[j]=1;
		}
	}

	// cout << "we have " << curr << ln;

	v32 vn;
	forn(i,n){
		if(rem[i]==0) vn.pb(v[i]);
	}

	// cout << "ended " << vn << " " << n << ln;

	if(vn.size()!=n) return ans(vn);
	return n;
}

int main(){
	fastio;

	int n, k, x;
	cin >> n >> k >> x;

	int c[n];
	forn(i, n) cin >> c[i];

	int mi = MOD;

	forn(i, n+1){

		v32 v;
		forn(j, i){
			v.pb(c[j]);
		}
		v.pb(x);
		forsn(j,i,n){
			v.pb(c[j]);
		}
		// cout << v << ln;
		mi = min(mi, ans(v));
	}

	cout << max(0,n-mi) << ln;

	return 0;
}