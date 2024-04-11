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
const int inf = 0x3f3f3f3f;
//const int mod = 998244353;

int main()
{
    int n,m,q; scanf("%d%d%d",&n,&m,&q);
    static ll a[maxn+5];
    rep(i,1,n) scanf("%lld",&a[i]);
    static vi S[maxn+5];
    rep(i,1,m)
    {
        int k; scanf("%d",&k);
        S[i].resize(k);
        for(auto &x: S[i]) scanf("%d",&x);
    }
    int sz = 330;
    vi hv;
    rep(i,1,m) if(sz(S[i])>=sz) hv.pb(i);
    static vector<vi> cnt(m+1, vi(sz(hv), 0));
    static ll sum[maxn+5];
    rep(i,0,sz(hv)-1)
    {
        int now = hv[i];
        static int mark[maxn+5];
        for(auto x: S[now]) mark[x] = now, sum[now] += a[x];
        rep(id,1,m) for(auto x: S[id]) cnt[id][i] += mark[x]==now;
    }
    static ll lz[maxn+5];
    while(q--)
    {
        char op[5]; int id; scanf("%s%d",op,&id);
        if(op[0]=='+')
        {
            int val; scanf("%d",&val);
            if(sz(S[id])>=sz) lz[id] += val;
            else 
            {
                for(auto x: S[id]) a[x] += val;
                int i = 0;
                for(auto now: hv) sum[now] += 1ll*val*cnt[id][i++];
            }
        }
        else
        {
            ll ans = sum[id];
            if(sz(S[id])<sz) for(auto x: S[id]) ans += a[x];
            rep(i,0,sz(hv)-1)
            {
                int now = hv[i];
                ans += 1ll*lz[now]*cnt[id][i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}