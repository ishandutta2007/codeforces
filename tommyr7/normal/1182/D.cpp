#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int d[Maxn];
int size[Maxn],num[Maxn],dep[Maxn];
int rt=1,mn=Maxn,mx;
int father[Maxn],rk[Maxn];
int r[Maxn],t[Maxn];
bool flag;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    size[u]=1;
    num[u]=0;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dfs(v,u);
            size[u]+=size[v];
            num[u]=max(num[u],size[v]);
        }
    }
    num[u]=max(num[u],n-size[u]);
    if (num[u]<mn)
    {
        mn=num[u];
        rt=u;
    }
}
int find(int x)
{
    if (father[x]==x) return x;
    father[x]=find(father[x]);
    return father[x];
}
void mdf(int x,int y)
{
    x=find(x),y=find(y);
    if (x==y) return;
    if (rk[x]<rk[y]) swap(x,y);
    rk[x]+=rk[y];
    father[y]=x;
}
void check_dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    if (t[dep[u]]==0) t[dep[u]]=d[u];
    else if (t[dep[u]]!=d[u]) flag=false;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa) check_dfs(v,u);
    }
}
bool check(int x)
{
    flag=true;
    memset(t,0,sizeof(t));
    check_dfs(x,0);
    return flag;
}
bool calc(int x)
{
    if (d[x]<=2) return true;
    if (x==rt) return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        father[i]=i,rk[i]=1;
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
        ++d[u],++d[v];
    }
    dfs(1,0);
    if (check(rt))
    {
        printf("%d\n",rt);
        return 0;
    }
    for (int i=1;i<=n;i++)
        for (int q=last[i];q;q=pre[q])
        {
            int v=other[q];
            if (calc(i)&&calc(v)) mdf(v,i);
        }
    int tot=0;
    for (int i=1;i<=n;i++)
        if (find(rt)==find(i)&&d[i]==1) ++tot;
    if (tot<=2)
    {
        for (int i=1;i<=n;i++)
            if (find(rt)==find(i)&&d[i]==1)
            {
                if (check(i))
                {
                    printf("%d\n",i);
                    return 0;
                }
            }
    } else
    {
        for (int i=1;i<=n;i++)
            if (d[i]>=3&&i!=rt)
            {
                printf("%d\n",-1);
                return 0;
            }
        dfs(rt,0);
        tot=0,mx=0;
        for (int i=1;i<=n;i++)
            if (d[i]==1) ++r[dep[i]],++tot;
        for (int i=0;i<=n;i++)
            mx=max(mx,r[i]);
        if (mx==tot)
        {
            for (int i=1;i<=n;i++)
                if (d[i]==1)
                {
                    printf("%d\n",i);
                    return 0;
                }
        } else if (mx==tot-1)
        {
            for (int i=1;i<=n;i++)
                if (d[i]==1&&r[dep[i]]==1)
                {
                    printf("%d\n",i);
                    return 0;
                }
        }
    }
    printf("%d\n",-1);
    return 0;
}