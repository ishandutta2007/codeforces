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

//root is primitive root, root_1 is inverse of root_pw modulo mod
//root_pw = 1<<20 (or whatever pow of 2), mod is the prime
//inverse is modular inverse

//root is primitive root, root_1 is inverse of root_pw modulo mod
//root_pw = 1<<20 (or whatever pow of 2), mod is the prime
//inverse is modular inverse

//root is primitive root, root_1 is inverse of root_pw modulo mod
//root_pw = 1<<20 (or whatever pow of 2), mod is the prime
//inverse is modular inverse


ll power(ll a, ll p, ll mod){
    if(p==0) return 1;
    ll x = power(a,p/2,mod);
    x = (x*x)%mod;
    if(p%2==1) x = (x*a)%mod;
    return x;
}

ll inverse(ll a, ll x,ll mod){
    return power(a,mod-2,mod);
}


// ll	MOD2 = 7340033;
// ll	root2 = 5;
// ll	root_12 = 4404020;
// ll	root_pw2 = 1<<20;

//ll root_1 = inverse(root,mod);

void ntt(vector<int> & a, bool invert, ll root_1, ll root_pw, ll mod, ll root) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

int main(){
	fastio;
	int n,k;
	cin>>n>>k;
	v32 a,b;
	int mod = 998244353;
	ll root_pw = 1LL<<23;
	ll root = 15311432;
	ll root_1 = inverse(root,mod,mod);
	int act[1001]={0};
	forn(i,n){
		int x;
		cin>>x;
		act[x]++;
	}
	forn(i,1001) a.pb(act[i]);
	int y1=1;
	set<int> s;
	while(y1<1024*1024) y1<<=1;
	while(a.size()<y1) a.pb(0);
	b=a;
	//cout<<a.size()<<ln;
	ntt(a,false,root_1,root_pw,mod,root);
	forn(i,a.size()){
		a[i] =  power(a[i],k,mod);
	}
	ntt(a,true,root_1,root_pw,mod,root);
	forn(i,a.size()){
		 if(a[i]>0) s.insert(i);//cout<<i<<" ";
	}
	//cout<<"OK"<<ln;
	mod = 7340033;
	root_pw = 1<<20;
	root = 4404020;
	root_1 = 5;
	ntt(b,false,root_1,root_pw,mod,root);
	forn(i,b.size()){
		b[i] =  power(b[i],k,mod);
	}
	ntt(b,true,root_1,root_pw,mod,root);
	forn(i,b.size()){
		 if(b[i]>0) s.insert(i);//cout<<i<<" ";
	}
	forstl(r,s)cout<<r<<" ";
	cout<<ln;
	return 0;
}