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
template <typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template <typename A> string to_string(A v) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}
inline int Madd(const int &x,const int &y) {return x+y<mod?x+y:x+y-mod;}

int fac[maxn+5],inv[maxn+5],ifac[maxn+5];

ll binom(int n,int m) 
{
    if(m<0 || n-m<0) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main()
{
    inv[1]=ifac[0]=fac[0]=1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;
    int n; scanf("%d",&n);

    int lb=0,lw=0,lq=0,rb=0,rw=0,rq=0;
    int bb=0,ww=0,qq=0;
    int LB=0;

    rep(i,1,n)
    {
        char s[5]; scanf("%s",s);
        if(s[0]=='B') lb++;
        else if(s[0]=='W') lw++;
        else lq++;
        if(s[1]=='B') rb++;
        else if(s[1]=='W') rw++;
        else rq++;
        bb += s[0]=='B' && s[1]=='B';
        ww += s[0]=='W' && s[1]=='W';
        qq += s[0]=='?' && s[1]=='?';
        if(s[0]=='B' || s[1]=='W') LB++;
    }
    int ans=0;
    rep(X,0,n)
    {
        int ways = 1ll*binom(lq,X-lb)*binom(rq,X-rw)%mod;
        //debug(X,ways);
        chadd(ans,ways);
        if(bb==0 && ww==0 && n>1 && X>0 && X<n)
        {
            int tmp = binom(qq,X-LB);
            chsub(ans,tmp);
        }
    }
    printf("%d\n",ans);
    return 0;
}