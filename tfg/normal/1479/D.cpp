#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
#define BU 775
int l[300005],stt[300005],ent[300005],ans[300005],cnt[300005],bl[BU],dp[20][300005],dep[300005];
vector<int> v[300005],e;
void dfs(int node,int p)
{
    stt[node]=e.size();
    e.push_back(l[node]);
    dp[0][node]=p;
    for (int i=1;i<20;i++)
    dp[i][node]=dp[i-1][dp[i-1][node]];
    dep[node]=dep[p]+1;
    for (int u:v[node])
    {
        if (u!=p)
        dfs(u,node);
    }
    ent[node]=e.size();
    e.push_back(l[node]);
}
int lca(int u,int v)
{
    if (dep[u]<dep[v])
    swap(u,v);
    int dist=dep[u]-dep[v];
    for (int i=0;i<20;i++)
    {
        if (dist&(1<<i))
        u=dp[i][u];
    }
    if (u==v)
    return u;
    for (int i=19;i>=0;i--)
    {
        if (dp[i][u]!=dp[i][v])
        {
            v=dp[i][v];
            u=dp[i][u];
        }
    }
    return dp[0][u];
}
struct query
{
    int u,v,l,r,lo,ro,i;
    bool f;
    query(int uu,int vv,int ii,int ll,int rr)
    {
        u=uu;
        v=vv;
        i=ii;
        lo=ll;
        ro=rr;
        if (stt[u]>stt[v])
        swap(u,v);
        r=stt[v];
        if (lca(u,v)==u)
        {
            l=stt[u];
            f=0;
        }
        else
        {
            l=ent[u];
            f=1;
        }
    }
    bool operator<(const query &q) const
    {
        if (l/BU==q.l/BU)
        return ((r<q.r)^((l/BU)%2));
        return (l<q.l);
    }
};
void upd(int i)
{
    i=e[i];
    bl[i/BU]-=cnt[i];
    cnt[i]^=1;
    bl[i/BU]+=cnt[i];
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    scanf("%d",&l[i]);
    for (int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    vector<query> qu;
    for (int i=0;i<q;i++)
    {
        int a,b,l,r;
        scanf("%d%d%d%d",&a,&b,&l,&r);
        qu.push_back(query(a,b,i,l,r));
        ans[i]=-1;
    }
    sort(qu.begin(),qu.end());
    int cl=0,cr=-1;
    for (auto c:qu)
    {
        while (cl>c.l)
        upd(--cl);
        while (cr<c.r)
        upd(++cr);
        while (cl<c.l)
        upd(cl++);
        while (cr>c.r)
        upd(cr--);
        if (c.f)
        upd(stt[lca(c.u,c.v)]);
        int cur=c.lo;
        while (cur<=c.ro && cur%BU)
        {
            if (cnt[cur])
            ans[c.i]=cur;
            cur++;
        }
        while (cur+BU-1<=c.ro)
        {
            if (bl[cur/BU])
            {
                while (!cnt[cur])
                cur++;
                ans[c.i]=cur;
                break;
            }
            cur+=BU;
        }
        if (ans[c.i]==-1)
        {
            while (cur<=c.ro)
            {
                if (cnt[cur])
                ans[c.i]=cur;
                cur++;
            }
        }
        if (c.f)
        upd(stt[lca(c.u,c.v)]);
    }
    for (int i=0;i<q;i++)
    printf("%d\n",ans[i]);
}