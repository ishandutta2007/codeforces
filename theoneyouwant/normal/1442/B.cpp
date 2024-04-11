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
const int LIM=2e5+5,MOD=998244353;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int link[LIM] = {0};
int sz[LIM] = {0};
int ul[LIM] = {0};
int lef[LIM] = {0};
int righ[LIM] = {0};

int find(int x){
	if(x==link[x]) return x;
	return link[x] = find(link[x]);
}



void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	lef[a] = min(find(lef[a]), find(lef[b]));
	righ[a] = max(find(righ[a]), find(righ[b]));
	ul[a] = ul[a]+ul[b];
	link[b] = a;
}

int main(){
	fastio;
	int tests = 1;
	cin>>tests;
	
	while(tests--){

		int n, k;
		cin>>n>>k;
		forn(i,n+2){
			link[i] = i;
			sz[i] = 1;
			righ[i] = i+1;
			lef[i] = i-1;
		}
		ll ans = 1;
		int a[n];
		forn(i,n){
			int x; cin>>x;
			x--;
			a[x] = i;
		}
		int b[k];
		forn(i,n) ul[i] = 1;
		forn(i,k){
			cin>>b[i];
			b[i]--;
			ul[a[b[i]]] = 0;
		}
		// forn(i,n) cout<<i+1<<" "<<ul[i]<<ln;
		forn(i,k){
			int f = find(a[b[i]]);
			int l = find(lef[f]);
			int r = find(righ[f]);
			if(l>=0 && ul[l]>=1){
				if(r<=n-1 && ul[r]>=1){
					ans = (ans * 2) % MOD;
					unite(f,l);
					unite(f,r);
				}
				else{
					unite(f,l);
				}
			}
			else if(r<=n-1 && ul[r]>=1){
				unite(f,r);
			}
			else{
				ans = 0;
			}
			// cout<<i<<" "<<ans<<ln;
		}
		cout<<ans<<ln;

	}

	return 0;
}