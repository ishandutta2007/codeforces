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
const ll MOD = 1e9+7, LIM = 1e5+5, MAXN = LIM;
const ld EPS = 1e-9;


int n;
p32 t[4*MAXN];
int a[MAXN];
int g[4*MAXN];

int gcd(int a1,int b1){
	return __gcd(a1,b1);
}

void build(int a[], int v, int tl, int tr) { 

//Call this with original array a, v=1, tl=0, tr=n-1

    if (tl == tr) {
        t[v] = mp(a[tl],1);
        g[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        g[v] = gcd(g[2*v],g[2*v+1]);
        int z = min(t[2*v].fi,t[2*v+1].fi);
        if(z!=g[v]){
        	t[v] = mp(z,0);
        }
        else{
        	int ans=0;
        	if(t[2*v].fi==g[v]) ans+=t[2*v].se;
        	if(t[2*v+1].fi==g[v]) ans+=t[2*v+1].se;
        	t[v] = mp(g[v],ans);
        }
        // CHANGE TO t[v] = 0 if using lazy propagation
    }
}

p32 sum(int v, int tl, int tr, int l, int r,int& curr) {

//Call this with v=1, tl=0, tr=n-1, l and r of original query

    if (l > r) {
    	curr = 1e9+5;
        return mp(1e9+5,0);
    }
    if (l == tl && r == tr) {
    	curr = g[v];
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int goin1,goin2;
    p32 a = sum(v*2, tl, tm, l, min(r, tm),goin1);
    p32 b = sum(v*2+1, tm+1, tr, max(l, tm+1), r,goin2);
    p32 toret;
    curr = gcd(goin1,goin2);
    if(goin1==1e9+5||goin2==1e9+5) curr = min(goin1,goin2);
    int z = min(a.fi,b.fi);
    if(z!=curr){
      	toret = mp(z,0);
    }
    else{
    	int ans=0;
      	if(a.fi==z) ans+=a.se;
       	if(b.fi==z) ans+=b.se;
       	toret = mp(z,ans);
    }
    return toret;	
}

int main(){
	fastio;
	cin>>n;
	forn(i,n) cin>>a[i];
	int t;
	cin>>t;
	build(a,1,0,n-1);
	forn(i,t){
		int l,r;
		cin>>l>>r;
		int goin;
		p32 p = sum(1,0,n-1,l-1,r-1,goin);
	//	cout<<p.fi<<" "<<p.se<<ln;
		cout<<r-l+1-p.se<<ln;
	}

	return 0;
}