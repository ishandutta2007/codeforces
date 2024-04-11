#include <bits/stdc++.h>
using namespace std;
#define inf 300000007
#define Maxn 507
int T,n,k;
vector<int> e[Maxn];
int f[107][107],g[107][107],gg[107][107][107],idx[107][107][107];
int g1[107][107][107],g2[107][107][107];
int sum1[107],sum2[107];
int sz[107];
void dfs(int u)
{
    sz[u]=1;
    int k=0;
    for (int id=0;id<(int)e[u].size();id++)
    {
        ++k;
        int v=e[u][id];
        dfs(v);
        sz[u]+=sz[v];
    }
    for (int i=0;i<=k;i++)
        for (int j=0;j<=sz[u];j++)
            g1[u][i][j]=inf;
    int now=1;
    g1[u][0][0]=0;
    g1[u][0][1]=0;
    sum1[0]=1;
    for (int id=0;id<(int)e[u].size();id++)
    {
        int v=e[u][id];
        for (int i=1;i<=sz[v];i++)
            for (int j=0;j<=now;j++)
                g1[u][id+1][i+j]=min(g1[u][id+1][i+j],g1[u][id][j]+g[v][i]+2);
        for (int j=0;j<=now;j++)
            g1[u][id+1][j]=min(g1[u][id+1][j],g1[u][id][j]);
        now+=sz[v];
        sum1[id+1]=now;
    }
    for (int i=0;i<=k;i++)
        for (int j=0;j<=sz[u];j++)
            g2[u][i][j]=inf;
    g2[u][0][0]=0;
    sum2[0]=1;
    now=1;
    for (int id=(int)e[u].size()-1;id>=0;id--)
    {
        int v=e[u][id];
        for (int i=1;i<=sz[v];i++)
            for (int j=0;j<=now;j++)
                g2[u][k-id][i+j]=min(g2[u][k-id][i+j],g2[u][k-id-1][j]+g[v][i]+2);
        for (int j=0;j<=now;j++)
            g2[u][k-id][j]=min(g2[u][k-id][j],g2[u][k-id-1][j]);
        now+=sz[v];
        sum2[k-id]=now;
    }
    for (int i=0;i<=sz[u];i++)
        g[u][i]=inf,f[u][i]=inf;
    for (int i=0;i<=sz[u];i++)
        g[u][i]=min(g[u][i],g1[u][k][i]);
    f[u][0]=0;
    f[u][1]=0;
    for (int id=0;id<(int)e[u].size();id++)
    {
        int v=e[u][id];
        for (int i=0;i<=sz[u];i++)
            gg[u][id][i]=inf;
        int id1=id,id2=k-id-1;
        for (int i=0;i<=sum1[id1];i++)
            for (int j=0;j<=sum2[id2];j++)
                if (g1[u][id1][i]+g2[u][id2][j]<gg[u][id][i+j])
                {
                    gg[u][id][i+j]=g1[u][id1][i]+g2[u][id2][j];
                    idx[u][id][i+j]=i;
                }
        for (int i=0;i<=sz[u]-sz[v];i++)
            for (int j=0;j<=sz[v];j++)
                f[u][i+j]=min(f[u][i+j],gg[u][id][i]+f[v][j]+1);
    }
}
void calc(int u,int k,int type)
{
    printf("%d ",u);
    if (k==1) return;
    if (type==1)
    {
        int now=k;
        for (int i=(int)e[u].size()-1;i>=0;i--)
        {
            int v=e[u][i];
            if (g1[u][i+1][now]!=g1[u][i][now])
            {
                for (int j=0;j<=sz[v]&&j<=now;j++)
                    if (g1[u][i+1][now]==g[v][j]+g1[u][i][now-j]+2)
                    {
                        calc(v,j,1);
                        printf("%d ",u);
                        now-=j;
                        break;
                    }
            }
        }
    } else
    {
        int kk=(int)e[u].size();
        int tmp_v=0,tmp_sz=0,tmp_id=0;
        bool flag=true;
        for (int id=(int)e[u].size()-1;id>=0&&flag;id--)
        {
            int v=e[u][id];
            for (int j=0;j<=sz[v]&&j<=k;j++)
                if (f[u][k]==gg[u][id][k-j]+f[v][j]+1) 
                {
                    tmp_v=v;
                    tmp_id=id;
                    tmp_sz=j;
                    flag=false;
                    break;
                }
        }
        k-=tmp_sz;
        int sz1=idx[u][tmp_id][k];
        int sz2=k-sz1;
        for (int i=tmp_id-1;i>=0;i--)
        {
            int v=e[u][i];
            if (g1[u][i+1][sz1]!=g1[u][i][sz1])
            {
                for (int j=0;j<=sz[v]&&j<=sz1;j++)
                    if (g1[u][i+1][sz1]==g[v][j]+g1[u][i][sz1-j]+2)
                    {
                        calc(v,j,1);
                        printf("%d ",u);
                        sz1-=j;
                        break;
                    }
            }
        }
        for (int i=tmp_id+1;i<(int)e[u].size();i++)
        {
            int v=e[u][i];
            if (g2[u][kk-i][sz2]!=g2[u][kk-i-1][sz2])
            {
                for (int j=0;j<=sz[v]&&j<=sz2;j++)
                    if (g2[u][kk-i][sz2]==g[v][j]+g2[u][kk-i-1][sz2-j]+2)
                    {
                        calc(v,j,1);
                        printf("%d ",u);
                        sz2-=j;
                        break;
                    }
            }
        }
        calc(tmp_v,tmp_sz,0);
    }
}
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<=n+1;i++)
        e[i].clear();
    for (int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        e[x].push_back(i);
    }
    dfs(1);
    printf("%d\n",f[1][k]);
    calc(1,k,0);
    printf("\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}