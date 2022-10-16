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

const int maxn = 1000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

struct node
{
    int from[maxn+5],to[maxn+5];
    void init(int n,int *a)
    {
        rep(i,1,n) to[a[i]] = i;
        rep(i,1,n) from[i] = i;
    }
    int get(int n,int x)
    {
        rep(i,1,n) if(from[i]==x) return i;
        assert(0);
    }
}X,Y;

int a[maxn+5],b[maxn+5];
int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);   
    rep(i,1,n) scanf("%d",&b[i]);
    X.init(n,a);
    Y.init(n,b);
    vector<pair<pii,pii>> ans;
    rep(i,1,n)
    {
        int x = X.get(n,X.to[i]), y = Y.get(n,Y.to[i]);
        debug(i,x,y);
        if(x==i && y==i) continue;
        ans.pb(mp(pii{x,i},pii{i,y}));
        swap(X.from[i],X.from[x]);
        swap(Y.from[i],Y.from[y]);
    }
    printf("%d\n",sz(ans));
    for(auto [f,s]: ans) printf("%d %d %d %d\n",f.FI,f.SE,s.FI,s.SE);
    return 0;
}