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

const int maxn = 300;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int msk_in[maxn+5],msk_out[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    auto getmask = [&]() {
        int msk = 0;
        rep(i,0,2) {int x; scanf("%d",&x); msk |= x<<i;}
        return msk;
    };
    rep(i,1,n) msk_in[i] = getmask();
    rep(i,1,n) msk_out[i] = getmask();
    static vi pool[maxn+5];
    rep(i,1,n) pool[msk_in[i]].pb(i);
    static int out[8]; out[7] = 1;
    vector<pii> ans;
    for(auto i: pool[7]) if(i!=out[7])
    {
        ans.pb({1,i});
        int msk = msk_out[i];
        if(msk!=0 && msk!=7) out[msk] = i;
    }
    rep(c,0,7) if(__builtin_popcount(c)==2 && out[c]!=0) for(auto i: pool[c])
    {
        ans.pb({out[c],i});
        int msk = msk_out[i] & c;
        if(__builtin_popcount(msk)==1) out[msk] = i;
    }
    rep(c,0,7) if(__builtin_popcount(c)==1)
    {
        if(sz(pool[c]) && out[c]==0) return puts("Impossible"),0;
        for(auto i: pool[c]) ans.pb({out[c],i});
    }
    static int mark[maxn+5];
    rep(c,0,7) if(out[c]) mark[out[c]] = 1;
    rep(c,0,7) if(__builtin_popcount(c)==2 && out[c]==0 && sz(pool[c])>0)
    {
        int a = -1;
        rep(i,0,2) if(c>>i&1) {a = 1<<i; break;}
        int b = a^c;
        if(out[a] && out[b])
        {
            out[c] = pool[c][0];
            ans.pb({out[a],out[c]});
            ans.pb({out[b],out[c]});
            for(auto i: pool[c]) if(i!=out[c]) ans.pb({out[c],i});
        }
        else return puts("Impossible"),0;
    }

    puts("Possible");
    rep(i,1,n) printf("%d%c",mark[i]," \n"[i==n]);
    assert(sz(ans)<=264);
    printf("%d\n",sz(ans));
    for(auto [x,y]: ans) printf("%d %d\n",x,y);
    return 0;
}