#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300005;
const ll Mod=1000000007;

int cnt,m,n,x,y;
vector<int>G[maxn];
int vis[maxn],color[maxn],deg[maxn];
void dfs(int x)
{
    vis[x]=cnt;
    for(int i=0;i<G[x].size();i++)
    {
        int y=G[x][i];
        if(vis[y])
            continue;
        dfs(y);
    }
}
int main()
{
    sync;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }
    if(cnt>=2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        color[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<G[i].size();j++)
        {
            int v=G[i][j];
            if(color[i]!=color[v])
                continue;
            else
                color[v]++;
        }
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==1)
            cnt1++;
        else if(color[i]==2)
            cnt2++;
        else
            cnt3++;
    }
    if(cnt1&&cnt2&&cnt3)
        int s=0;
    else
    {
        cout<<-1<<endl;
        return 0;
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==1&&deg[i]!=n-cnt1)
            f=1;
        else if(color[i]==2&&deg[i]!=n-cnt2)
            f=1;
        else if(color[i]==3&&deg[i]!=n-cnt3)
            f=1;
        if(f==1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<' ';
    }
    cout<<endl;
    return 0;
}