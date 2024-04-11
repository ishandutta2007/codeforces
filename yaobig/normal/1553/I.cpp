#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template <typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x : v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
ll qp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}
inline int Madd(int x,int y) {return x+y<mod?x+y:x+y-mod;}
inline int Msub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

struct Transform
{
    const int g=3;
    int wn[30][2];
    vi r;
    int n2,len;

    void init()
    {
        rep(i,0,20)
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
    vi conv(vi &A,vi B)
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

using poly = vi;
poly& operator +=(poly &a,const poly &b)
{
    if(a.size()<b.size()) a.resize(b.size(),0);
    rep(i,0,(int)b.size()-1) a[i]=Madd(a[i],b[i]);
    return a;
} 
poly operator +(const poly &a,const poly &b) {auto c=a; return c+=b;}
poly& operator *=(poly &a,const poly &b)
{
    if(min(a.size(),b.size())<128)
    {
        vi c=a;
        a.assign(a.size()+b.size()-1,0);
        rep(i,0,(int)c.size()-1) rep(j,0,(int)b.size()-1) a[i+j]=(a[i+j]+1ll*c[i]*b[j])%mod;
    } 
    else a=ntt.conv(a,b);
    return a;
}
poly operator *(const poly &a,const poly &b) {auto c=a; return c*=b;}

using node = array<array<poly,2>,2>;

int main()
{
    int n; scanf("%d",&n);
    vi a(n+1);
    rep(i,1,n) scanf("%d",&a[i]);
    vi b;
    int ok=1;
    for(int l=1;l<=n;l+=a[l])
    {
        int r=l+a[l]-1;
        if(r>n) {ok=0; break;}
        rep(i,l,r) if(a[i]!=a[l]) ok=0;
        b.pb(a[l]);
    }
    if(ok==0) return puts("0"),0;

    function<node(int,int)> solve = [&] (int l,int r)
    {
        if(l==r)
        {
            node res{};
            res[0][1] = res[1][0] = res[1][1] = poly{2};
            res[0][0] = poly{b[l]==1 ? 1 : 2};
            return res;
        }
        int mid = (l+r)>>1;
        node A = solve(l,mid), B = solve(mid+1,r);
        node res{};
        rep(L,0,1) rep(R,0,1)
        {
            auto c = A[L][0] * B[0][R];
            auto d = A[L][1] * B[1][R];
            res[L][R] += c;
            if(sz(res[L][R]) == sz(c)) res[L][R].pb(0);
            rep(it,1,sz(c)) res[L][R][it] = (res[L][R][it] + 1ll*(mod+1)/2*d[it-1])%mod;
        }
        //rep(i,0,1) rep(j,0,1) debug(l,r,i,j, res[i][j]);
        return res;
    };
    int N = sz(b);
    auto res = solve(0,N-1)[0][0];
    vi fac(N+1,1);
    rep(i,1,N) fac[i] = 1ll*fac[i-1]*i%mod;
    int ans = 0;
    rep(i,0,sz(res)-1) 
    {
        if(i&1) chsub(ans, 1ll*res[i]*fac[N-i]%mod);
        else chadd(ans, 1ll*res[i]*fac[N-i]%mod);
    }
    printf("%d\n",ans);
    return 0;
}