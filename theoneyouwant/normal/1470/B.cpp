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
const int LIM=3e5+5,MOD=1e9+7;
const ld EPS = 1e-9;
const int UPTO = 1e6+10;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int link[LIM] = {0};
int sz[LIM] = {0};
int gg[LIM] = {0};

int find(int x){
	if(x==link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	link[b] = a;
}

int smallest[UPTO];

void precomp(){
	forsn(i,2,UPTO){
		if(smallest[i] == 0){
			smallest[i] = i;
			int j = 2*i;
			while(j < UPTO){
				if(smallest[j]==0) smallest[j] = i;
				j += i;
			}
		}
	}
}

int main(){
	fastio;

	precomp();

	int tests = 1;
	cin>>tests;
	
	while(tests--){

		int n; cin>>n;
		forn(i,n) link[i] = i;
		forn(i,n) sz[i] = 1;
		forn(i,n) gg[i] = 1;
		ll a[n]; forn(i,n) cin>>a[i];
		map<int,int> m;
		forn(i,n){
			ll g = 1;
			while(a[i]>1){
				ll z = smallest[a[i]];
				if(a[i]%(z*z) == 0){
					a[i] /= z;
					a[i] /= z;
				}
				else{
					a[i] /= z;
					g *= z;
				}
			}
			// cout<<i<<" "<<g<<ln;
			gg[i] = g;
			if(m[g]!=0) unite(i,m[g]-1);
			m[g] = i+1;
		}
		set<int> s;
		forn(i,n){
			s.insert(find(i));
		}
		int mx1 = 0, mx2 = 0;
		forstl(r,s){
			mx1 = max(mx1, sz[r]);
			if((sz[r]%2)==0) mx2 += sz[r];
			if(((sz[r]%2) == 1) && (gg[r] == 1)) mx2 += sz[r];
		}
		// cout<<mx1<<" "<<m2<<ln;
		int q; cin>>q;
		while(q--){
			ll w; cin>>w;
			if(w == 0) cout<<mx1<<ln;
			else cout<<max(mx1, mx2)<<ln;
		}
	}

	return 0;
}