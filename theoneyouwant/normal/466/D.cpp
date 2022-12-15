//by Shriram Lokhande
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define testcases(t) int t,myzx;cin>>myzx;forsn(t,1,myzx+1) 
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits 
#define ln "\n"
#define kyahai(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr<<ln; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t\t";
	err(++it, args...);
}
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(n) n.begin() , n.end() 
#define sz(n) (int) n.size()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
 
template<typename T>
using oset =  tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
//like set just find_by_order()(returns a pointer) and order_of_key() are extra
 
#pragma GCC optimize ("-O3")
const int LIM = 2e5+5 ,MOD = 1e9+7;
const ld EPS = 1e-9 , PI = 2*atan2((ld)1,(ld)0);
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n,h;
	cin>>n>>h;
	int a[n+1];
	forn(i,n) {
		cin>>a[i+1];	 
		a[i+1] = h - a[i+1];
	}
	ll dp[n+1][n+1];
	forn(j,n+1) forn(i,n+1) dp[j][i] = 0;
	dp[0][0] = 1;
 
	
	forsn(i,1,n+1){
		forsn(j,0,n+1){
			//open one
			if(a[i] == j+1 and i != n) dp[i][j+1] += dp[i-1][j];
			//close and open
			if(a[i] == j+1 and i != n and i != 1 and j > 0) dp[i][j] += j*dp[i-1][j];
			// open and close
			if(a[i] == j+1) dp[i][j] += dp[i-1][j];
			//close
			if(a[i] == j and j > 0 and i != 1) dp[i][j-1] += j*dp[i-1][j];
			//nothing
			if(a[i] == j) dp[i][j] += dp[i-1][j];
 
			if(j != n) dp[i][j+1] %= MOD;
			dp[i][j] %= MOD;
			if(j != 0) dp[i][j-1] %= MOD;
		}
	}
 
	cout<<dp[n][0]<<ln;
 
}