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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

using hashv = pair<int,int>;
const int mod1 = 1000000007;
const int mod2 = 1000050131;

inline int Madd(int x,int y,int M) {return x+y<M?x+y:x+y-M;}
inline int Msub(int x,int y,int M) {return x-y>=0?x-y:x-y+M;}

hashv operator +(const hashv &a,const hashv &b) {return {Madd(a.FI,b.FI,mod1), Madd(a.SE,b.SE,mod2)};}
hashv operator +(const hashv &a,const int &b) {return {Madd(a.FI,b,mod1), Madd(a.SE,b,mod2)};}
hashv operator -(const hashv &a,const hashv &b) {return {Msub(a.FI,b.FI,mod1), Msub(a.SE,b.SE,mod2)};}
hashv operator *(const hashv &a,const hashv &b) {return {1ll*a.FI*b.FI%mod1, 1ll*a.SE*b.SE%mod2};}
hashv operator *(const hashv &a,const int &b) {return {1ll*a.FI*b%mod1, 1ll*a.SE*b%mod2};}

const hashv base={500009,500029}; 
hashv pw[maxn+5];

// indices start from 1.
hashv get_hash(vector<hashv> &hx,int l,int r) {return hx[r]-hx[l-1]*pw[r-l+1];}

char s[maxn+5],t[maxn+5];

int main()
{
    pw[0] = {1,1};
    rep(i,1,maxn) pw[i] = pw[i-1]*base;

    int n,m; scanf("%d%d",&n,&m);
    scanf("%s%s",s+1,t+1);
    vi last(26);
    vi diff(n+1);
    vector<hashv> ps(n+1); hashv B = {0,0};
    rep(i,1,n)
    {
        int c = s[i]-'a';
        int x = last[c]==0 ? n : i - last[c];
        diff[i] = x;
        ps[i] = ps[i-1]*base + x;
        last[c] = i;
    }
    last.assign(26,0);
    rep(i,1,m)
    {
        int c = t[i]-'a';
        int x = last[c]==0 ? n : i - last[c];
        B = B*base + x;
        last[c] = i;
    }
    last.assign(26,n+1);
    vi ans;
    per(i,1,n)
    {
        last[int(s[i]-'a')] = i;
        if(i<=n-m+1)
        {
            hashv hx = get_hash(ps,i,i+m-1);
            rep(c,0,25) if(last[c]<i+m)
            {
                int pos = last[c], l = i+m-1-pos;
                hx = hx - pw[l]*diff[pos] + pw[l]*n;
            }
            if(hx==B)
            {
                static vi to; to.assign(26,-1);
                int ok = 1;
                rep(c,0,25) if(last[c]<i+m)
                {
                    int pos = last[c];
                    int a = s[pos]-'a', b = t[pos-i+1]-'a';
                    if(to[a]==-1) to[a] = b;
                    if(to[b]==-1) to[b] = a;
                    if(to[a]!=b || to[b]!=a) {ok = 0; break;}
                }
                if(ok) ans.pb(i);
            }
        }
    }
    sort(all(ans));
    printf("%d\n",sz(ans));
    rep(i,0,sz(ans)-1) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
    return 0;
}