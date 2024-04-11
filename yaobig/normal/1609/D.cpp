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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1000;
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
    void merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
    }
}us;

int a[maxn+5];

int main()
{
    int n,d; scanf("%d%d",&n,&d);
    us.init(n);
    int red = 0;
    rep(i,1,d)
    {
        int x,y; scanf("%d%d",&x,&y);
        if(us.check(x,y)) red++;
        else us.merge(x,y);
        static vi S; S.clear();
        rep(i,1,n) if(us.getfa(i)==i) S.pb(us.sz[i]);
        //debug(S);
        nth_element(S.begin(),S.begin()+red,S.end(),greater<int>());
        int ans = 0;
        rep(i,0,red) ans+=S[i]; 
        printf("%d\n",ans-1);
    }
    
    return 0;
}