#include <bits/stdc++.h>
#define Maxn 600007
using namespace std;
int n,q;
char s[Maxn];
int mx[Maxn],fa[Maxn],to[Maxn][26],suf[Maxn];
int tot=1,lst=1;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int now=0,dfn[Maxn],up[Maxn][21],dep[Maxn];
vector<int> son[Maxn];
int flag[Maxn],que[Maxn],stk[Maxn];
int f[Maxn][2];
long long ans=0;
void extend(int c)
{
    int p=lst,np=++tot;
    lst=tot;
    mx[np]=mx[p]+1;
    for (;p&&!to[p][c];p=fa[p])
        to[p][c]=np;
    if (!p) fa[np]=1;
    else
    {
        int q=to[p][c];
        if (mx[p]+1==mx[q]) fa[np]=q;
        else
        {
            int nq=++tot;
            mx[nq]=mx[p]+1;
            memcpy(to[nq],to[q],sizeof(to[nq]));
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for (;p&&to[p][c]==q;p=fa[p])
                to[p][c]=nq;
        }
    }
}
void suffix_automation()
{
    for (int i=n;i;i--)
    {
        extend(s[i]-'a');
        suf[i]=lst;
    }
}
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u)
{
    dfn[u]=++now;
    for (int i=1;i<=20;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        dep[v]=dep[u]+1;
        up[v][0]=u;
        dfs(v);
    }
}
int lca(int u,int v)
{
    if (dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for (int i=20;i>=0;i--)
        if (d&(1<<i)) u=up[u][i];
    if (u==v) return u;
    for (int i=20;i>=0;i--)
        if (up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    if (u==v) return u;
    return up[u][0];
}
void suffix_tree()
{
    suffix_automation();
    for (int i=1;i<=tot;i++)
        insert(fa[i],i);
    dfs(1);
}
bool cmp(int a,int b)
{
    return dfn[a]<dfn[b];
}
void dp(int u)
{
    f[u][0]=f[u][1]=0;
    if (flag[u]&1) f[u][0]=1;
    if (flag[u]&2) f[u][1]=1;
    ans+=1LL*f[u][0]*f[u][1]*mx[u];
    for (int i=0;i<(int)son[u].size();i++)
    {
        int v=son[u][i];
        dp(v);
        ans+=1LL*f[u][0]*f[v][1]*mx[u];
        ans+=1LL*f[u][1]*f[v][0]*mx[u];
        f[u][0]+=f[v][0];
        f[u][1]+=f[v][1];
    }
    flag[u]=0;
    son[u].clear();
}
void solve()
{
    int a,b,tmp=0;
    scanf("%d%d",&a,&b);
    for (int i=1;i<=a;i++)
    {
        int x;
        scanf("%d",&x);
        que[++tmp]=suf[x];
        flag[suf[x]]|=1;
    }
    for (int i=1;i<=b;i++)
    {
        int x;
        scanf("%d",&x);
        que[++tmp]=suf[x];
        flag[suf[x]]|=2;
    }
    sort(que+1,que+tmp+1,cmp);
    int ntmp=1;
    for (int i=2;i<=tmp;i++)
        if (que[ntmp]!=que[i]) que[++ntmp]=que[i];
    tmp=ntmp;
    int top=1;
    stk[top]=1;
    for (int i=1;i<=tmp;i++)
    {
        int u=lca(stk[top],que[i]);
        if (u==stk[top])
        {
            stk[++top]=que[i];
            continue;
        }
        while (top>1&&dep[stk[top-1]]>=dep[u])
        {
            son[stk[top-1]].push_back(stk[top]);
            --top;
        }
        if (dep[stk[top]]>dep[u])
        {
            son[u].push_back(stk[top]);
            --top;
        }
        if (u!=stk[top]) stk[++top]=u;
        stk[++top]=que[i];
    }
    while (top>1)
    {
        son[stk[top-1]].push_back(stk[top]);
        --top;
    }
    ans=0LL;
    dp(1);
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    suffix_tree();
    for (int i=1;i<=q;i++)
        solve();
    return 0;
}