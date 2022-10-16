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
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

struct Union_Set
{
    array<int,maxn+5> fa,sz;
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

int to[maxn+5],ind[maxn+5],cnt[maxn+5],key[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    us.init(n);
    rep(i,1,n) scanf("%d",&to[i]), us.merge(i,to[i]), ind[to[i]]++;
    rep(i,1,n) if(ind[i]==0) cnt[us.getfa(i)]++;
    vector<pii> vec;
    static bool mark[maxn+5];
    rep(i,1,n) if(us.getfa(i)==i)
    {
        int now = i;
        while(mark[now]==0)
        {
            mark[now] = 1; 
            now = to[now];
        }
        key[i] = now;
        if(cnt[i]==0) vec.pb({key[i],key[i]});
        if(cnt[i]==0 && us.sz[i]==n) return puts("0"),0;
    }
    rep(i,1,n) if(ind[i]==0)
    {
        int rt = us.getfa(i);
        vec.pb({i,key[rt]});
    }
    int N = sz(vec);
    printf("%d\n",N);
    rep(i,0,N-1) printf("%d %d\n",vec[i].SE,vec[(i+1)%N].FI);
    return 0;
}