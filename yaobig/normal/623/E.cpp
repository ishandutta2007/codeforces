#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 30'000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res = res*a%mod;
    return res;
}

const double pi=acos(-1.0);
struct Transform
{
    typedef complex<double> cp;
    vi r;
    int n2;
    void FFT(vector<cp> &a,int opt) // opt=1 -> DFT, opt=-1 -> iDFT
    {
        rep(i,1,n2-1) if(r[i]>i) swap(a[i],a[r[i]]);
        vector<cp> w;
        for(int step=1;step<n2;step<<=1)
        {
            w.resize(step);
            rep(j,0,step-1) 
            {
                db theta=pi*j/step*opt;
                w[j]=cp{cos(theta),sin(theta)};
            }
            for(int step2=step<<1,i=0;i<n2;i+=step2)
            {
                rep(j,0,step-1)
                {
                    cp even=a[i+j];
                    cp odd=a[i+j+step];
                    cp tmp=w[j]*odd;
                    a[i+j]=even+tmp;
                    a[i+j+step]=even-tmp;
                }
            }
        }
    }
    void pre(int n) // set n2, r;
    {
        int len=0;
        for(n2=1;n2<n;n2<<=1) len++;
        r.resize(n2);
        rep(i,1,n2-1) r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
    }
    void work(vector<cp> &a,vector<cp> &b,vi &ans,int w,int mod)
    {
        static vector<cp> tmp; tmp.resize(n2);
        rep(i,0,n2-1) tmp[i]=a[i]*b[i];
        FFT(tmp,-1);
        rep(i,0,n2-1) ans[i]=(ans[i]+(ll)(tmp[i].real()/n2+0.5)%mod*w)%mod;
    }
    vi conv(const vi &A,const vi &B,int mod)
    {
        int M = sqrt(mod)+0.5;
        int n = A.size()+B.size()-1;
        vector<cp> a(n2,0),b(n2,0),c(n2,0),d(n2,0);
        rep(i,0,sz(A)-1) a[i] = A[i]/M, b[i] = A[i]%M;
        rep(i,0,sz(B)-1) c[i] = B[i]/M, d[i] = B[i]%M;

        FFT(a,1); FFT(b,1); FFT(c,1); FFT(d,1);
        vi res(n2,0);
        work(a,c,res,1ll*M*M%mod,mod);
        work(b,d,res,1,mod);
        work(a,d,res,M,mod);
        work(b,c,res,M,mod);
        res.resize(n);
        return res;
    }
}fft;

int fac[maxn+5],ifac[maxn+5],inv[maxn+5];

int main()
{
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;
    
    ll n; int k; scanf("%lld%d",&n,&k);
    if(n>k) return puts("0"), 0;
    vi res(k+1); res[0] = fac[k];
    vi a(k+1); rep(i,1,k) a[i] = ifac[i];
    fft.pre(k*2+1); // move the precalculation out, since the length is fixed.
    rep(bit,0,14) 
    {
        if(n>>bit&1)
        {
            vi b = res;
            rep(i,0,k) b[i] = 1ll*b[i]*qp(2,i<<bit)%mod;
            res = fft.conv(b,a,mod);
            res.resize(k+1);
        }
        vi b = a;
        rep(i,0,k) b[i] = 1ll*b[i]*qp(2,i<<bit)%mod;
        a = fft.conv(b,a,mod);
        a.resize(k+1);
    }
    int ans = 0;
    rep(i,0,k) chadd(ans, 1ll*res[i]*ifac[k-i]%mod);
    printf("%d\n",ans);
    return 0;
}