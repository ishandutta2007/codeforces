#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll dis2(pii a,pii b) {return 1ll*(a.FI-b.FI)*(a.FI-b.FI)+1ll*(a.SE-b.SE)*(a.SE-b.SE);}

pii p[maxn+5];
ll r2[maxn+5];

vi e[maxn+5];
ll dp[maxn+5][3];

ll dfs(int now,int msk)
{
    if(dp[now][msk]>-1ll<<60) return dp[now][msk];
    ll res=-1ll<<60;
    if(msk<2)
    {
        ll tmp=r2[now];
        for(auto v: e[now]) tmp+=dfs(v,msk+1);
        chmax(res,tmp);
    }
    if(msk>0)
    {
        ll tmp=-r2[now];
        for(auto v: e[now]) tmp+=dfs(v,msk-1);
        chmax(res,tmp);
    }
    return dp[now][msk]=res;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d%lld",&p[i].FI,&p[i].SE,&r2[i]),r2[i]=r2[i]*r2[i];
    r2[0]=1ll<<60;
    vi id{0};
    rep(i,1,n) id.pb(i);
    sort(id.begin(),id.end(),[](int a,int b){return r2[a]>r2[b];});
    assert(id[0]==0);
    rep(i,1,n)
    {
        int now=id[i];
        per(j,0,i-1)
        {
            int v=id[j];
            if(dis2(p[now],p[v])<=r2[v]) 
            {
                e[v].pb(now); break;
            }
        }
    }
    memset(dp,0x80,sizeof dp);
    ll ans=0;
    for(auto u: e[0]) ans+=dfs(u,0);
    printf("%.13f\n",acos(-1.0)*ans);
    return 0;
}