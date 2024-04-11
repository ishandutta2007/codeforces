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
string to_string(bool b) {return (b ? "true" : "false");}
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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res = res*a%mod;
    return res;
}

struct node {int v,p,q;};

int main()
{
    static int maxp[maxn+5],inv[maxn+5];
    rep(i,2,maxn) if(maxp[i]==0) for(int j=i;j<=maxn;j+=i) maxp[j] = i;
    inv[1] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;

    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static vector<node> e[maxn+5];
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int u,v,p,q; scanf("%d%d%d%d",&u,&v,&p,&q);
            e[u].pb(node{v,p,q});
            e[v].pb(node{u,q,p});
        }

        static int cnt[maxn+5],mx[maxn+5];
        rep(i,1,n) cnt[i] = mx[i] = 0;
        int ans = 0;
        function<void(int,int,int)> dfs = [&](int now,int fa,int rat) {
            chadd(ans, rat);
            for(auto [v,p,q]: e[now]) if(v!=fa)
            {
                vi P,Q;
                int nrat = 1ll*rat*q%mod*inv[p]%mod;
                while(p!=1) P.pb(maxp[p]), p /= maxp[p];
                while(q!=1) Q.pb(maxp[q]), q /= maxp[q];
                for(auto x: Q) cnt[x]--;
                for(auto x: P) cnt[x]++, chmax(mx[x], cnt[x]);
                dfs(v,now,nrat);
                for(auto x: Q) cnt[x]++;
                for(auto x: P) cnt[x]--;
            }
        };
        dfs(1,0,1);
        rep(i,1,n) if(mx[i]) ans = 1ll*ans*qp(i,mx[i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}