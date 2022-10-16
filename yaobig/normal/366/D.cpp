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

const int maxn = 3000;
const int mod = 998244353;
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

struct node
{
    int u,v,l,r;
}e[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int u,v,l,r; scanf("%d%d%d%d",&u,&v,&l,&r);
        e[i] = node{u,v,l,r};
    }
    sort(e+1,e+m+1,[](const node &a,const node &b){return a.r>b.r;});
    int ans = 0;
    rep(_,1,m)
    {
        int L = e[_].l;
        us.init(n);
        rep(i,1,m) if(e[i].r>=L && e[i].l<=L)
        {
            auto [u,v,l,r] = e[i];
            if(us.merge(u,v) && us.check(1,n)) 
            {
                chmax(ans,r-L+1);
                break;
            }
        }
    }
    if(ans==0) puts("Nice work, Dima!");
    else printf("%d\n",ans);
    return 0;
}