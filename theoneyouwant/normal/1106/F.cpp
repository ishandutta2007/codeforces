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
const ll MOD = 998244353, LIM = 1e5+5, MOD2 = MOD-1;
const ld EPS = 1e-9;

ll t,n,m,k,x,y;


const int MAX_N = 100; // Fibonacci matrix, increase/decrease this value as needed

struct Matrix { ll mat[MAX_N][MAX_N]; }; // we will return a 2D array

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans; int i, j, k;
	for (i = 0; i < MAX_N; i++)
	for (j = 0; j < MAX_N; j++)
	for (ans.mat[i][j] = k = 0; k < MAX_N; k++){
		ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j])%MOD2;
		ans.mat[i][j]%=MOD2;
	}
	return ans; 
}

// if necessary, use modulo arithmetic

Matrix matPow(Matrix base, int p) {
	// O(n^3 log p)
	Matrix ans; int i, j;
	for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++) 
	ans.mat[i][j] = (i == j); // prepare identity matrix
	while (p) {
		// iterative version of Divide & Conquer exponentiation
		if (p & 1) ans = matMul(ans, base);	// if p is odd (last bit is on)
		base = matMul(base, base);	// square the base
		p >>= 1;
		// divide p by 2
	}
	return ans; 
}

// ll solve(ll a, ll b, ll m) {
//     ll n = sqrt (m + .0) + 1;

//     ll an = 1;
//     for (ll i = 0; i < n; ++i)
//         an = (an * a) % m;

//     map<ll, ll> vals;
//     for (ll p = 1, cur = an; p <= n; ++p) {
//         if (!vals.count(cur))
//             vals[cur] = p;
//         cur = (cur * an) % m;
//     }

//     for (ll q = 0, cur = b; q <= n; ++q) {
//         if (vals.count(cur)) {
//             ll ans = vals[cur] * n - q;
//             return ans;
//         }
//         cur = (cur * a) % m;
//     }
//     return -1;
// }
int gcd(int a, int b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int fastexp(int a, int p){
	if(p==0) return 1;
	ll z = fastexp(a,p/2);
	z = (z*z) %MOD;
	if(p%2) z = (z*a)%MOD;
	return z;
}

int solve(int a,ll b,ll m) {
    int n = (int) sqrt (m + .0) + 1;
    map<int,int> vals;
    for(int i=n; i>=1; --i)
        vals[fastexp(a,i*n)]=i;
    for (int i=0;i<=n;++i) {
        int cur=(fastexp(a,i)*b)%m;
        if(vals.count(cur)){
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
    }
    return -1;
}

int main(){
	fastio;
	cin>>k;
	int b[k];
	forn(i,k) cin>>b[i];
	cin>>n>>m;
	Matrix coef;
	forn(i,MAX_N){
		forn(j,MAX_N){
			coef.mat[i][j]=0;
		}
	}
	forn(i,k){
		coef.mat[0][i] = b[i];
	}
	forn(i,k-1){
		coef.mat[i+1][i]=1;
	}
	// forn(i,k){
	// 	forn(j,k){
	// 		cout<<coef.mat[i][j]<<" ";
	// 	}
	// 	cout<<ln;
	// }
	coef = matPow(coef, n-k);
	ll ans=coef.mat[0][0];
	//cout<<ans<<" ";
	//if(k==99 && b[0]==168251207) cout<<ans<<" ans here "<<ln;
	ll pow1 = solve(3,m,MOD);
	//cout<<pow1<<" ";
	//if(k==99 && b[0]==168251207) cout<<pow1<<" "<<fastexp(3,pow1)<<ln;
	//cout<<fastexp(3,pow1)<<ln;	
	ll k1,k2;
	ll y = gcd(ans,MOD2,k1,k2);
	//cout<<y<<" ";
	if(pow1%y!=0) cout<<-1<<ln;
	else{
		k1%=MOD2;
		if(k1<0) k1+=MOD2;
		k1*=(pow1/y);
		k1%=MOD2;
		//ll r = fastexp(3,k1);
		cout<<fastexp(3,k1)<<ln;
		//cout<<fastexp(r,23)<<ln;
	}
	return 0;
}