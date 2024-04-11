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

const int maxn = 100000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}

struct Union_Set
{
    array<int,25> fa,sz;
    void init(int n) 
    {
        rep(i,1,n) fa[i]=i,sz[i]=1;
    }
    int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
	bool check(int x,int y) {return getfa(x)==getfa(y);}
    bool merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) return 0;
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
        return 1;
    }
}us;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        static char a[maxn+5],b[maxn+5];
        static int to[25];

        int n; scanf("%d",&n);
        scanf("%s%s",a+1,b+1);
        rep(i,0,19) to[i] = 0;
        us.init(20);
        
        int ans = 20;
        rep(i,1,n) if(a[i]!=b[i])
        {
            int x = a[i]-'a'+1;
            int y = b[i]-'a'+1;
            ans += us.merge(x,y);
            to[x-1] |= 1<<(y-1);
        }

        const int N = 1<<20;
        static int dp[N];
        dp[0] = 1;
        int mx = 0;
        rep(msk,1,N-1)
        {
            dp[msk] = 0;
            rep(i,0,19) if(msk>>i&1)
            {
                int nmsk = msk ^ (1<<i);
                if(dp[nmsk] && (nmsk & to[i])==0) {dp[msk] = 1; break;}
            }
            if(dp[msk]) chmax(mx,__builtin_popcount(msk));
        }
        ans -= mx;
        printf("%d\n",ans);
    }
    return 0;
}