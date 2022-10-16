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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

mt19937_64 rng(20000902);
int myrand(int l,int r) {return l+rng()%(r-l+1);}

vi pool[maxn+5];
int a[maxn+5],mark[maxn+5];

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]), pool[a[i]].pb(i);
    rep(i,1,q)
    {
        int l,r,k; scanf("%d%d%d",&l,&r,&k);
        int val = (r-l+1)/k;
        int ans = inf;
        rep(_,1,80)
        {
            int x = a[myrand(l,r)];
            if(mark[x] == i) continue;
            mark[x] = i;
            int pos = upper_bound(all(pool[x]),r) - pool[x].begin();
            if(pos>=val+1 && pool[x][pos-val-1]>=l) chmin(ans,x);
        }
        if(ans==inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}