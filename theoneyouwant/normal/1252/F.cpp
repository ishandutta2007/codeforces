
//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
const int LIM=1e5+5;
const ld EPS = 1e-9;

//root is primitive root, root_1 is inverse of root_pw modulo mod
//root_pw = 1<<20 (or whatever pow of 2), mod is the prime
//inverse is modular inverse

int fastpow(int a, int p, int m){
	if(p == 0) return 1;
	ll z = fastpow(a,p/2,m);
	z = (z*z)%m;
	if(p&1) z = (a*z)%m;
	return z;
}

int inverse(int a, int m){
	return fastpow(a,m-2,m);
}
const int mod=998244353;
// 998244353=1+7*17*2^23 : g=3
// 1004535809=1+479*2^21 : g=3
// 469762049=1+7*2^26 : g=3
// 7340033=1+7*2^20 : g=3
// For below change mult as overflow:
    // 10000093151233=1+3^3*5519*2^26 : g=5
    // 1000000523862017=1+10853*1373*2^26 : g=3
    // 1000000000949747713=1+2^29*3*73*8505229 : g=2
// For rest find primitive root using Shoup's generator algorithm
// root_pw: power of 2 >= maxn, Mod-1=k*root_pw => w = primitive^k 
template<long long Mod,long long root_pw,long long primitive>
struct NTT{
    inline long long powm(long long x,long long pw){
        x%=Mod;
        if(abs(pw)>Mod-1) pw%=(Mod-1);
        if(pw<0) pw+=Mod-1;
        ll res=1;
        while(pw){
            if(pw&1LL) res=(res*x)%Mod;
            pw>>=1;
            x=(x*x)%Mod;
        }
        return res;
    }
    inline ll inv(ll x){
        return powm(x,Mod-2); 
    }
    ll root,root_1;
    NTT(){
        root=powm(primitive,(Mod-1)/root_pw);
        root_1=inv(root);
    }
    void ntt(vector<long long> &a,bool invert){
        int n=a.size();
        for(long long i=1,j=0;i<n;i++){
            long long bit=n>>1;
            for(;j&bit;bit>>=1) j^=bit;
            j^=bit;
            if(i<j) swap(a[i],a[j]);
        }
        for(long long len=2;len<=n;len<<=1){
            long long wlen= invert ? root_1:root;
            for(long long i=len;i<root_pw;i<<=1) wlen=wlen*wlen%Mod;
            for(long long i=0;i<n;i+=len){
                long long w=1;
                for(long long j=0;j<len/2;j++){
                    long long u=a[i+j],v=a[i+j+len/2]*w%Mod;
                    a[i+j]= u+v<Mod ? u+v:u+v-Mod;
                    a[i+j+len/2]= u-v>=0 ? u-v:u-v+Mod;
                    w=w*wlen%Mod;
                }
            }
        }
        if(invert){
            ll n_1=inv(n);
            for(long long &x: a) x=x*n_1%Mod;
        }
    }
    vector<long long> multiply(vector<long long> const& a,vector<ll> const& b){
        vector<long long> fa(a.begin(),a.end()),fb(b.begin(),b.end());
        int n=1;
        while(n<a.size()+b.size()) n<<=1;
        point(fa,1,n);
        point(fb,1,n);
        for(int i=0;i<n;++i) fa[i]=fa[i]*fb[i]%Mod;
        coef(fa);
        return fa;
    }
    void point(vector<long long> &A,bool not_pow=1,int atleast=-1){
        if(not_pow){
            if(atleast==-1){
                atleast=1;
                while(atleast<A.size()) atleast<<=1;
            }
            A.resize(atleast,0);
        }
        ntt(A,0);
    }
    void coef(vector<long long> &A,bool reduce=1){
        ntt(A,1);
        if(reduce) while(A.size() and A.back()==0) A.pop_back(); 
    }
    void point_power(vector<long long> &A,long long k){
        for(long long &x: A) x=powm(x,k);
    }
    void coef_power(vector<long long> &A,int k){
        while(A.size() and A.back()==0) A.pop_back();
        int n=1;
        while(n<k*A.size()) n<<=1;
        point(A,1,n);
        point_power(A,k);
        coef(A);
    }
    vector<long long> power(vector<long long> a,ll p){
        while(a.size() and a.back()==0) a.pop_back();
        vector<long long> res;
        res.pb(1);
        while(p){
            if(p&1) res=multiply(res,a);
            a=multiply(a,a);
            p/=2;
        }
        return res;
    }
};

void fill(v64 & a, int m, int mo){

	ll st = 1;
	a.pb(1);	
	forsn(i,1,m+1){
		st *= (m-i+1);
		st %= mo;
		st *= inverse(i,mo);
		st %= mo;
		a.pb(st);
	}
	return;
}

signed main(){
	fastio;

	int n,k;
	cin>>n>>k;

	int a[n], b[k];
	map<int,int> m;
	forn(i,n){
		cin>>a[i];
		if(m[a[i]]<2) m[a[i]]++;
	} 	
	forn(i,k) cin>>b[i];

	sort(b,b+k);

	v64 ans[5];

	NTT<mod,1<<20,3> ntt;

	forn(i,k){

		v64 va,vb;
		int x = 0, y = 0;
		forstl(r,m){
			if(r.fi >= b[i]) break;
			if(r.se == 1) x++;
			else y++;
		}
		fill(va, x, mod);
		fill(vb, 2*y, mod);

		ll two = 1;
		forn(j,va.size()){
			va[j] = (va[j]*two)%mod;
			two = (two*2)%mod;
		}
		ans[i] = ntt.multiply(va,vb);
		// cout<<"iter "<<i<<" arrays "<<va<<" "<<vb<<ln;
	}


	int q;
	cin>>q;

	forn(i,q){
		
		ll x, an = 0;
		cin>>x;

		forn(j,5){
			int target = (x-(2*b[j]))/2;
			target -= 1;
			if(target>=0 && ans[j].size()>target) an += ans[j][target];
		}
		an %= mod;
		cout<<an<<ln;
	}


	return 0;
}