// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// -------------------</optimizations>--------------------
 
// ---------------<Headers and namespaces>----------------
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
*/
 
// ---------------</Headers and namespaces>---------------
 
// -----------------<Defines and typedefs>----------------
// typedef tree<int,null_type,less<int>,rb_tree_tag, \
tree_order_statistics_node_update> indexed_set; // use less_equal for multiset
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
typedef long double LD;
typedef long long ll;
// #define int ll
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define ITR :: iterator it
#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define TR(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define sqr(x) ((x)*(x))
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
 
// -----<SCANF>-----
#define sfi(x) scanf("%d",&x);
#define sfi2(x,y) scanf("%d%d",&x,&y);
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z);
 
#define sfl(x) scanf("%lld",&x);
#define sfl2(x,y) scanf("%lld%lld",&x,&y);
#define sfl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
#define sfl4(x,y,z,x1) scanf("%lld%lld%lld%lld",&x,&y,&z,&x1);
#define sfl5(x,y,z,x1,y1) scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1);
#define sfl6(x,y,z,x1,y1,z1) scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1,&z1);
 
#define sfs(x) scanf("%s",x);
#define sfs2(x,y) scanf("%s%s",x,y);
#define sfs3(x,y,z) scanf("%s%s%s",x,y,z);
// ----</SCANF>-----
 
// ----<PRINTF>-----
#define pfi(x) printf("%d\n",x);
#define pfi2(x,y) printf("%d %d\n",x,y);
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z);
 
#define pfl(x) printf("%lld\n",x);
#define pfl2(x,y) printf("%lld %lld\n",x,y);
#define pfl3(x,y,z) printf("%lld %lld %lld\n",x,y,z);
 
#define pfs(x) printf("%s\n",x);
#define pfs2(x,y) printf("%s %s\n",x,y);
#define pfs3(x,y,z) printf("%s %s %s\n",x,y,z);
 
#define pwe(x) printf("%lld ",x); // print without end
// ----</PRINTF>----
 
#define FLSH fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x) cout << fixed << setprecision(x); 
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
// ----------------</Defines and typedefs>----------------
 
// -------------------<Debugging stuff>-------------------
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
// ------------------</Debugging stuff>-------------------
 
// ------------------------<Consts>-----------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
 
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
#endif
 
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
 
// -----------------------</Consts>-----------------------
 
// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.
 
// ------------------------</RNG>-------------------------
 
// ----------------------<MATH>---------------------------
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int add(int a, int b, int c = MOD){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c = MOD){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;return(res>=c?res%c:res);}
int muln(int a, int b, int c = MOD){ll res=(ll)a*b;return ((res%c)+c)%c;}
ll mulmod(ll a,ll b, ll m = MOD){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
 
const int FACSZ = 1; // Make sure to change this
 
int fact[FACSZ],ifact[FACSZ];
 
void precom(int c = MOD){
	fact[0] = 1;
	FOR(i,1,FACSZ) fact[i] = mul(fact[i-1],i,c);
	ifact[FACSZ-1] = mod_inverse(fact[FACSZ-1],c);
	REPD(i,FACSZ-1){
		ifact[i] = mul(i+1,ifact[i+1],c);
	}
}
 
int ncr(int n,int r,int c = MOD){
	return mul(mul(ifact[r],ifact[n-r],c),fact[n],c);
} 
// ----------------------</MATH>--------------------------
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
 
vi divs[200005];

void solvethetestcase();
 
signed main(){
	FOR(i,1,200001){
		for(int j = i; j <= 200000; j += i) divs[j].pb(i);
	}
	// (UNCOMMENT FOR CIN/COUT) \
	FAST_IO
	PRECISION(10)
 
	int t = 1;
	// (UNCOMMENT FOR MULTIPLE TEST CASES) 
	sfi(t);
	FOR(testcase,1,t+1){
		// (UNCOMMENT FOR CODEJAM) \
		printf("Case #%lld: ",testcase); 
		solvethetestcase();
	}
}   
 
int n;
int p[200005],c[200005];

bitset<200005> vis;
bitset<200005> vis2;

vi comp,comp2;
int lol[200005],lol2[200005];
vi gg;
vi compi[21];

void dfs(int u){
	comp.pb(u);
	comp2.pb(u);
	vis[u] = 1;
	if(!vis[p[u]]) dfs(p[u]);
	// trace(u,vis[u]);
}

vi mkc(vi v1,vi v2){
	vi res;
	REP(i,v1.size()) res.pb(v2[v1[i]]);
	return res;
}

void f(int x){
	int lmao = 1;
	while(x){
		if(x%2){
			vi res;
			REP(i,comp.size()) res.pb(compi[lmao][comp[i]]);
			comp = res;
		}
		x /= 2;
		lmao++;
	}
}

int flag,col;

void dfs2(int u){
	// trace(u,lol2[u],col);
	vis2[u] = 1;
	if(col == -1) col = lol2[u];
	else if(col != lol2[u]){
		flag = 0;
	}
	if(!vis2[comp[u]]) dfs2(comp[u]);
}
 
void solvethetestcase(){
	sfi(n)
	FOR(i,1,n+1) sfi(p[i])
	FOR(i,1,n+1) sfi(c[i])
	REP(i,n+2) vis[i] = 0;
	int ans = n;
	FOR(i,1,n+1){
		if(vis[i]) continue;
		comp.clear();
		comp2.clear();
		dfs(i);
		sort(all(comp2));
		// trace(i);
		// FOR(j,1,n+1) trace(j,vis[j]);
		sort(all(comp));
		REP(j,comp.size()) comp[j] = p[comp[j]];
		// for(auto x:comp) trace(x);
		REP(j,comp.size()) lol[comp2[j]] = j;
		REP(j,comp.size()){
			lol2[j] = c[comp2[j]];
			// trace(j,lol2[j]);
		}
		REP(j,comp.size()) comp[j] = lol[comp[j]];
		// for(auto y:comp) trace(y);
		compi[1] = comp;
		FOR(lmao,2,21) compi[lmao] = mkc(compi[lmao-1],compi[lmao-1]);
		REP(fuck,divs[comp.size()].size()){
			if(divs[comp.size()][fuck] >= ans) break;
			if(fuck) f(divs[comp.size()][fuck]-divs[comp.size()][fuck-1]);
			REP(j,comp.size()+2) vis2[j] = 0;
			REP(j,comp.size()){
				if(vis2[j]) continue;
				col = -1;
				flag = 1;
				dfs2(j);
				if(flag){
					remin(ans,divs[comp.size()][fuck]);
					break;
				}
			}
			if(flag) break;
		}
	}
	pfi(ans)
}