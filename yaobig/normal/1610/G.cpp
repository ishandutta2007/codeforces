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
    for(const auto &x: v) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 300000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}

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

const hashv base={131,10007}; //{100003,100019}, {500009,500029}
const int LG = __lg(maxn);
hashv hx[maxn+5][LG],pw[maxn+5];

char s[maxn+5];
int ps[maxn+5],last[maxn+5];
int nxt[maxn+5][LG],best[maxn+5];

int main()
{
    pw[0] = {1,1};
    rep(i,1,maxn) pw[i] = pw[i-1]*base;

    scanf("%s",s+1);
    int n = strlen(s+1);
    rep(i,1,n) ps[i] = ps[i-1] + (s[i]=='('?1:-1);
    int mn = *min_element(ps,ps+n+1);
    rep(i,0,n) ps[i] += -mn;
    rep(i,0,n) last[i] = -1;
    last[ps[n]] = n;

    rep(j,0,LG-1) nxt[n+1][j] = n+1;
    best[n+1] = n+1;

    per(i,1,n) 
    {
        nxt[i][0] = best[i+1];
        hx[i][0] = hashv{s[i],s[i]};
        rep(j,1,LG-1) 
        {
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
            hx[i][j] = hx[i][j-1] + hx[nxt[i][j-1]][j-1]*pw[1<<(j-1)];
        }
        best[i] = i;
        int c = ps[i-1];
        if(last[c]!=-1 && s[i]=='(') 
        {
            int x = best[last[c]+1];
            auto cmp = [&](int x,int y) {
                per(i,0,LG-1) if(hx[x][i]==hx[y][i]) x=nxt[x][i],y=nxt[y][i];
                return s[x]<s[y];
            };
            if(cmp(x,i)) best[i] = x;
        }
        last[c] = i-1;
    }
    int now = 1;
    while(best[now]!=n+1)
    {
        now = best[now];
        putchar(s[now]);
        now++;
    }
    puts("");
    return 0;
}