#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e3+10;
const ll mod=1e9+7;
int n,m,ta[maxn],tb[maxn],sz[maxn];
vector<int>v[maxn];
struct DP
{
    int a;
    ll b;
}dp[maxn][maxn];
const DP dpinf={0,-linf};
bool operator<(DP a,DP b)
{
    if(a.a!=b.a)return a.a<b.a;
    return a.b<b.b;
}
void dfs(int x,int f)
{
    sz[x]=1;
    dp[x][0]={0,tb[x]-ta[x]};
    for(auto y:v[x])if(y!=f)
    {
        dfs(y,x);
        DP tmp[maxn];
        for(int i=0;i<sz[x]+sz[y];i++)tmp[i]=dpinf;
        for(int i=0;i<sz[x];i++)
            for(int j=0;j<=sz[y];j++)
                tmp[i+j]=max(tmp[i+j],(DP){dp[x][i].a+dp[y][j].a,dp[x][i].b+dp[y][j].b});

        sz[x]+=sz[y];
        for(int i=0;i<sz[x];i++)dp[x][i]=tmp[i];
    }
    dp[x][sz[x]]=dpinf;
    for(int i=sz[x];i;i--)
    {
        dp[x][i]=max(dp[x][i],(DP){dp[x][i-1].a+(dp[x][i-1].b>0),0});
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",ta+i);
        for(int i=1;i<=n;i++)scanf("%d",tb+i);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,0);
        printf("%d\n",dp[1][m-1].a+(dp[1][m-1].b>0));
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}