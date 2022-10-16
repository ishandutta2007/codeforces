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

using hashv = pair<int,int>;
const int mod1 = 1000000007;
const int mod2 = 1000050131;

inline int Madd(int x,int y,int mod) {return x+y<mod?x+y:x+y-mod;}
inline int Msub(int x,int y,int mod) {return x-y>=0?x-y:x-y+mod;}

hashv operator +(const hashv &a,const hashv &b) {return {Madd(a.FI,b.FI,mod1), Madd(a.SE,b.SE,mod2)};}
hashv operator +(const hashv &a,const int &b) {return {Madd(a.FI,b,mod1), Madd(a.SE,b,mod2)};}
hashv operator -(const hashv &a,const hashv &b) {return {Msub(a.FI,b.FI,mod1), Msub(a.SE,b.SE,mod2)};}
hashv operator *(const hashv &a,const hashv &b) {return {1ll*a.FI*b.FI%mod1, 1ll*a.SE*b.SE%mod2};}
hashv operator *(const hashv &a,const int &b) {return {1ll*a.FI*b%mod1, 1ll*a.SE*b%mod2};}

const hashv base{500009,500029};
hashv pw[maxn*5+5];

array<int,6> a[maxn+5];

int main()
{
    pw[0] = {1,1};
    rep(i,1,maxn*5) pw[i] = pw[i-1]*base;

    int n,m; scanf("%d%d",&n,&m);
    vi vec;
    rep(i,1,n) 
    {
        rep(j,1,m) scanf("%d",&a[i][j]), vec.pb(a[i][j]);
        scanf("%d",&a[i][0]);
    }
    sort(a+1,a+n+1);
    sort(all(vec)); vec.erase(unique(all(vec)),vec.end());
    rep(i,1,n) rep(j,1,m) a[i][j] = lower_bound(all(vec),a[i][j]) - vec.begin();
    
    vector<pair<hashv,int>> A;
    int M = 1<<m;
    rep(i,1,n)
    {
        rep(msk,0,M-1)
        {
            hashv hx = {0,0};
            rep(d,0,m-1) if(msk>>d&1) hx = hx + pw[a[i][d+1]];
            A.pb(mp(hx,i));
        }
    }
    sort(all(A));
    int ptr = n, ans = inf*2;
    rep(i,1,n)
    {
        int ok = 0;
        while(ptr>0)
        {
            int cnt = 0;
            rep(msk,0,M-1)
            {
                hashv hx = {0,0};
                rep(d,0,m-1) if(msk>>d&1) hx = hx + pw[a[i][d+1]];
                auto pos = upper_bound(all(A),mp(hx,ptr)) - lower_bound(all(A),mp(hx,0));
                if(__builtin_popcount(msk)&1) cnt -= pos;
                else cnt += pos;
            }
            if(cnt>0)
            {
                ok = 1;
                ptr--;
            }
            else break;
        }
        if(ok)
        {
            ptr++;
            chmin(ans, a[i][0]+a[ptr][0]);
        }
    }
    if(ans==inf*2) puts("-1"); 
    else printf("%d\n",ans);
    return 0;
}