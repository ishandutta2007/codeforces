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
const int mod = 1'000'000'007;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

using base = array<int,5>;

bool operator +=(base &a,int x)
{
    per(i,0,4) if(x>>i&1) x ^= a[i];
    if(x==0) return 1;
    per(i,0,4) if(x>>i&1) 
    {
        a[i] = x; 
        per(j,i+1,4) if(a[j]>>i&1) a[j] ^= x;
        break;
    }
    return 0;
}
bool operator +=(base &a,const base &b)
{
    per(i,0,4) if(b[i] && (a += b[i])) return 1;
    return 0;
}

vector<pii> e[maxn+5];
base b[maxn+5];
int cyc[maxn+5],dep[maxn+5],dis[maxn+5];
int mark[maxn+5],bad[maxn+5];

void dfs(int now,int fa,int from,int d)
{
    dep[now] = dep[fa]+1;
    dis[now] = d;
    for(auto [v,w]: e[now]) if(v!=fa)
    {
        if(dep[v]==0) 
        {
            dfs(v, now, from ? from : v, d^w);
            if(now==1) mark[v] = 1;
        }
        else if(dep[v]<dep[now])
        {
            int len = dis[v] ^ d ^ w;
            if(v==1) cyc[from] = len;
            else if(b[from] += len) bad[from] = 1;
        }
    }
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x].pb({y,w});
        e[y].pb({x,w});
    }
    memset(cyc,-1,sizeof cyc);
    dfs(1,0,0,0);
    map<base,int> M; int tot = 0; M[base{}] = ++tot;
    vector<base> vec(1); vec.pb(base{});
    vi dp[2]; int cur = 0; dp[cur].resize(505); dp[cur][1] = 1;

    int tran[505][505]; memset(tran,-1,sizeof tran);

    rep(i,2,n) if(mark[i] && bad[i]==0)
    {
        int old = cur; cur ^= 1;
        dp[cur] = dp[old];
        auto upd = [&](base &rhs,int ways) {
            int &j = M[rhs];
            if(j==0) j = ++tot, vec.pb(rhs);
            rep(i,1,tot) if(dp[old][i])
            {
                int &k = tran[i][j];
                if(k==-1)
                {
                    base tmp = vec[i];
                    if(tmp += rhs) k = 0;
                    else 
                    {
                        int &kp = M[tmp];
                        if(kp==0) kp = ++tot, vec.pb(tmp);
                        k = kp;
                    }
                }
                if(k!=0) chadd(dp[cur][k], 1ll*dp[old][i]*ways%mod);
            }
        };
        if(cyc[i]==-1) upd(b[i],1);
        else 
        {
            upd(b[i],2);
            if(cyc[i]!=0 && (b[i] += cyc[i])==0) upd(b[i],1);
        }
    }
    int ans = 0;
    rep(i,1,tot) chadd(ans, dp[cur][i]);
    printf("%d\n",ans);
    return 0;
}