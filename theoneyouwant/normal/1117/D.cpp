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

const ll MAX_N = 101; // Fibonacci matrix, increase/decrease this value as needed

struct Matrix { int mat[MAX_N][MAX_N]; }; // we will return a 2D array

void matMul(Matrix &a, Matrix b) {
	Matrix ans; int i, j, k;
	forn(i,MAX_N) forn(j,MAX_N) ans.mat[i][j]=0;
	for (i = 0; i < MAX_N; i++)
	for (k = 0; k < MAX_N; k++)
	for (j = 0; j < MAX_N; j++){
		ans.mat[i][j] += ((ll)a.mat[i][k] * b.mat[k][j])%MOD;
		ans.mat[i][j]%=MOD;
	}
	a=ans;
}

// if necessary, use modulo arithmetic

Matrix matPow(Matrix base, ll p) {
	// O(n^3 log p)
	Matrix ans; int i, j;
	for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++) 
	ans.mat[i][j] = (i == j); // prepare identity matrix
	while (p) {
		// iterative version of Divide & Conquer exponentiation
		if (p & 1) matMul(ans, base);	// if p is odd (last bit is on)
		matMul(base, base);	// square the base
		p >>= 1;
		// divide p by 2
	}
	return ans; 
}



int main(){
	fastio;
	ll n,m;
	cin>>n>>m;
	if(n<m) {
		cout<<1<<ln;
		return 0;
	}
	Matrix ans;
	forn(i,m){
		forn(j,m){
			ans.mat[i][j]=0;
		}
	}
	ans.mat[0][0]=1;	
	ans.mat[0][m-1]=1;
	forn(i,m-1){
		ans.mat[i+1][i]=1;
	}		
	// forn(i,m){
	// 	forn(j,m){
	// 		cout<<ans.mat[i][j]<<" ";
	// 	}
	// 	cout<<ln;
	// }
	Matrix final;
	final = matPow(ans,(n-m));
	//cout<<"OK"<<ln;
	ll ans2=0;
	forn(i,m){
		ans2+=final.mat[0][i];
		if(i==0) ans2+=final.mat[0][i];
		ans2%=MOD;
	}
	cout<<ans2<<ln;
	return 0;
}