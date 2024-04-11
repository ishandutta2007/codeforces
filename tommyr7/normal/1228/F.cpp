#include <bits/stdc++.h>
#define Maxn 3000007
using namespace std;
int n;
int last[Maxn],pre[Maxn],other[Maxn],cntt=0;
int d[Maxn],tot[Maxn];
int cnt[5];
int tmp[Maxn],ansss;
int sz[Maxn],ssz[Maxn];
bool ck;
vector<int> qq;
int qqq[Maxn];
void insert(int u,int v)
{
    other[++cntt]=v,pre[cntt]=last[u],last[u]=cntt;
    ++d[u];
}
void pre_dfs(int u,int fa,int st)
{
    bool flag=false;
    tmp[u]=1;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            pre_dfs(v,u,st^1);
            if (tmp[v]==0) tmp[u]=0;
            flag=true;
        }
    }
    if (!flag) tmp[u]=st;
    if (tmp[u]==1) ansss=u;
}
void get_sz(int u,int fa)
{
    ssz[u]=1;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            get_sz(v,u);
            ssz[u]+=ssz[v];
        }
    }
}
void dfs(int u,int ans,int fa,int dep)
{
    if (dep>n) 
    {
        ck=false;
        return;
    }
    if (u!=ans)
    {
        sz[u]=1;
        int now=0;
        for (int q=last[u];q;q=pre[q])
        {
            int v=other[q];
            if (v!=fa)
            {
                dfs(v,ans,u,dep+1);
                sz[u]+=sz[v];
                now++;
            }
        }
        if (now!=0&&now!=2) ck=false;
        if (sz[u]!=(1<<(n-dep))-1) ck=false;
    } else
    {
        int mx=0,now=0;
        sz[u]=2;
        for (int q=last[u];q;q=pre[q])
        {
            int v=other[q];
            if (v!=fa&&ssz[v]>ssz[mx]) mx=v;
            if (v!=fa) ++now;
        }
        if (now!=3&&now!=1) ck=false;
        dfs(mx,ans,u,dep+1);
        sz[u]+=sz[mx];
        int z=0;
        for (int q=last[u];q;q=pre[q])
        {
            int v=other[q];
            if (v!=fa&&v!=mx)
            {
                dfs(v,ans,u,dep+2);
                sz[u]+=sz[v];
                ++z;
            }
        }
        if (sz[u]!=(1<<(n-dep))-1) ck=false;
    }
}
bool check(int rt,int ans)
{
    ck=true;
    get_sz(rt,-1);
    dfs(rt,ans,-1,0);
    return ck;
}
int main()
{
    scanf("%d",&n);
    if (n==2)
    {
        printf("%d\n",2);
        printf("%d %d\n",1,2);
        return 0;
    }
    for (int i=1;i<=(1<<n)-3;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);
        insert(v,u);
    }
    int m=(1<<n)-2;
    for (int i=1;i<=m;i++)
        if (d[i]>4)
        {
            printf("%d\n",0);
            return 0;
        }
    for (int i=1;i<=m;i++)
        ++tot[d[i]];
    if (tot[4]==1&&tot[2]==1&&tot[1]==(1<<(n-1))&&tot[3]==(1<<(n-1))-4)
    {
        int rt=0,ans=0;
        for (int i=1;i<=m;i++)
            if (d[i]==2) rt=i;
            else if (d[i]==4) ans=i;
        if (check(rt,ans)) qq.push_back(ans);
    }
    if (tot[2]==2&&tot[1]==(1<<(n-1))-1&&tot[3]==(1<<(n-1))-3)
    {
        int rt=0,ans=0;
        for (int i=1;i<=m;i++)
            if (d[i]==2&&rt==0) rt=i; else if (d[i]==2) ans=i;
        bool ck1=check(rt,ans);
        if (ssz[ans]!=2) ck1=false;
        bool ck2=check(ans,rt);
        if (ssz[rt]!=2) ck2=false;
        if (ck1&&ck2)
        {
            qq.push_back(rt);
            qq.push_back(ans);
        } else if (ck1)
        {
            qq.push_back(ans);
        } else if (ck2)
        {
            qq.push_back(rt);
        }
    }
    if (tot[1]==(1<<(n-1))&&tot[3]==(1<<(n-1))-2)
    {
        int now=1;
        for (int i=1;i<=m;i++)
            if (d[i]==1) now=i;
        pre_dfs(now,-1,0);
        if (ansss!=0)
        {
            int rt=ansss;
            int ans=ansss;
            if (check(rt,ans)&&rt==ans)
            {
                now=1;
                for (int v=1;v<=(1<<n)-2;v++)
                    if (d[v]==1&&tmp[v]==1) now=v;
                ansss=0;
                pre_dfs(now,-1,0);
                if (ansss==0)
                {
                    qq.push_back(ans);
                } else 
                {
                    rt=ansss;
                    int anss=ansss;
                    if (check(rt,anss)&&rt==anss)
                    {
                        qq.push_back(ans);
                        qq.push_back(anss);
                    } else
                    {
                        qq.push_back(ans);
                    }
                    
                }
            }
        }
    }
    cntt=0;
    for (int i=0;i<(int)qq.size();i++)
        if (qqq[cntt]!=qq[i]) qqq[++cntt]=qq[i];
    sort(qqq+1,qqq+cntt+1);
    printf("%d\n",cntt);
    for (int i=1;i<=cntt;i++)
        printf("%d ",qqq[i]);
    printf("\n");
    return 0;
}