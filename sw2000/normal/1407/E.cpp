#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

vector<pii> edg[N];
int n,m,dp[N][2];
bool vis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    memset(dp,0x3f,sizeof(dp));
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edg[b].push_back({a,c});
    }

    priority_queue<pii>q;
    dp[n][0]=0;dp[n][1]=0;
    q.push({0,n});
    while(!q.empty())
    {
        pii tmp=q.top();q.pop();
        int u=tmp.y,w=-tmp.x;
        if(vis[u])continue;
        vis[u]=1;

        for(auto i:edg[u])
        {
            int v=i.x;
            if(vis[v])continue;
            dp[v][i.y]=min(dp[v][i.y],w+1);
            q.push({-max(dp[v][0],dp[v][1]),v});
        }
    }

    int ans=max(dp[1][0],dp[1][1]);
    if(ans==inf)ans=-1;
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(dp[i][0]>dp[i][1])cout<<0;
        else cout<<1;
    }
    return 0;
}