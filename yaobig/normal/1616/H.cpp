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

const int maxn = 150000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}

int pw2[maxn+5];

int solve2(int dep,vi &L,vi &R,int k)
{
    if(sz(L)==0 || sz(R)==0) return pw2[sz(L)+sz(R)];
    if(dep==-1) return pw2[sz(L)+sz(R)];
    vi Lhi,Llo,Rhi,Rlo;
    for(auto &x: L) if(x>>dep&1) Lhi.pb(x); else Llo.pb(x);
    for(auto &x: R) if(x>>dep&1) Rhi.pb(x); else Rlo.pb(x);
    L.clear(); R.clear();
    if((k>>dep&1)==0) 
    {
        int res = 0;
        chadd(res,pw2[sz(Lhi)+sz(Llo)]);
        chadd(res,pw2[sz(Rhi)+sz(Rlo)]);
        chsub(res,(1ll*pw2[sz(Lhi)]+pw2[sz(Llo)]+pw2[sz(Rhi)]+pw2[sz(Rlo)])%mod);
        chadd(res,solve2(dep-1,Lhi,Rhi,k));
        chadd(res,solve2(dep-1,Llo,Rlo,k));
        chadd(res,1);
        return res;
    }
    else return 1ll*solve2(dep-1,Lhi,Rlo,k)*solve2(dep-1,Llo,Rhi,k)%mod;
}

int solve(int dep,vi &a,int k)
{
    if(sz(a)==0) return 1;
    if(dep==-1) return pw2[sz(a)];
    vi b,c;
    for(auto &x: a) if(x>>dep&1) c.pb(x); else b.pb(x);
    a.clear();
    if(k>>dep&1) return solve2(dep-1,b,c,k);
    else return (1ll*solve(dep-1,b,k)+solve(dep-1,c,k)+mod-1)%mod;
}

int main()
{
    pw2[0] = 1;
    rep(i,1,maxn) pw2[i] = pw2[i-1] * 2%mod;

    int n,k; scanf("%d%d",&n,&k);
    vi a(n);
    rep(i,0,n-1) scanf("%d",&a[i]);
    int ans = solve(29,a,k);
    printf("%d\n",(ans+mod-1)%mod);
    return 0;
}