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

const int maxn = 100'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

ll qp(ll a,ll k)
{
    ll res=1;
    for(;k;a=a*a%mod,k>>=1) if(k&1) res=res*a%mod;
    return res;
}
inline int Madd(int x,int y) {return x+y<mod?x+y:x+y-mod;}
inline int Msub(int x,int y) {return x-y<0?x-y+mod:x-y;}

struct Transform
{
    const int g=3;
    int wn[30][2];
    vi r;
    int n2,len;

    void init()
    {   // mod = 998244353 supports length <= 2^23.
        rep(i,0,29)
        {
            wn[i][0]=qp(g,(mod-1)/(1<<i));
            wn[i][1]=qp(wn[i][0],mod-2);
        }
    }
    Transform(){init();}

    void NTT(vi &a,int is_inv) // is_inv == 1 -> iDFT.
    {
        rep(i,1,n2-1) if(r[i]>i) swap(a[i],a[r[i]]);
        rep(t,0,len-1)
        {
            int step=1<<t,step2=1<<(t+1);
            vi w(step); w[0]=1;
            rep(i,1,step-1) w[i]=1ll*w[i-1]*wn[t+1][is_inv]%mod;
            for(int i=0;i<n2;i+=step2)
            {
                rep(j,0,step-1)
                {
                    int tmp=1ll*w[j]*a[i+j+step]%mod;
                    a[i+j+step]=Msub(a[i+j],tmp);
                    a[i+j]=Madd(a[i+j],tmp);
                }
            }
        }
        if(is_inv==1) 
        {
            ll inv=qp(n2,mod-2);
            rep(i,0,n2-1) a[i]=a[i]*inv%mod;
        }
    }
    void pre(int n) // set n2, r;
    {
        len=0;
        for(n2=1;n2<n;n2<<=1) len++;
        r.resize(n2);
        rep(i,1,n2-1) r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
    }
    vi conv(vi A,vi B)
    {
        int n=A.size()+B.size()-1;
        pre(n);

        A.resize(n2,0);
        B.resize(n2,0);
        NTT(A,0);
        NTT(B,0);
        rep(i,0,n2-1) A[i]=1ll*A[i]*B[i]%mod;
        NTT(A,1);
        A.resize(n);
        return A;
    }
}ntt;

int pw[maxn+5];

int main()
{
    pw[0] = 1;
    rep(i,1,maxn) pw[i] = 1ll*pw[i-1]*2%mod;

    static int a[maxn+5],mark[maxn+5];
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,m)
    {
        int x; scanf("%d",&x);
        mark[x] = 1;
    }
    static int ps[maxn+5],suf[maxn+5];
    int ans = 0;
    function<void(int,int,int)> solve = [&](int l,int r,int rev) {
        if(l==r) return;
        int mid = (l+r)>>1;
        solve(l,mid,rev); solve(mid+1,r,rev);
        
        vi L(mid-l+1),LX(mid-l+1),R(r-mid+r-l+1);
        
        rep(i,l,mid) L[i-l] = mark[i] ? pw[ps[i]-1] : 0;
        rep(i,l,mid) LX[i-l] = mark[i] ? 1ll*pw[ps[i]-1]*i%mod : 0;
        rep(i,mid+1,r+r-l+1) R[i-mid-1] = i>n ? 1 : pw[suf[i]];
        
        auto res = ntt.conv(L,R);
        auto resX = ntt.conv(LX,R);
        rep(i,mid+1,r)
        {
            int pos = i*2+rev-l-mid-1;
            chadd(ans, 1ll*res[pos]*a[i]%mod*i%mod);
            chsub(ans, 1ll*resX[pos]*a[i]%mod);
        }
    };
    auto work = [&](int rev) {
        if(rev)
        {
            reverse(a+1,a+n+1);
            reverse(mark+1,mark+n+1);
        }
        rep(i,1,n) ps[i] = ps[i-1]+mark[i];
        per(i,1,n) suf[i] = suf[i+1]+mark[i];
        solve(1,n,rev);
    };
    work(0);
    work(1);
    ans = 1ll*ans*qp(pw[m]-1+mod,mod-2)%mod;
    printf("%d\n",ans);
    return 0;
}