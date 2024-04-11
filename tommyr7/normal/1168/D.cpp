#include <bits/stdc++.h>
#define Maxn 150007
using namespace std;
int n,q;
vector<int> g[Maxn],son[Maxn];
int len[Maxn],top[Maxn],pos[Maxn],f[Maxn][26],sum[Maxn][26],cnt[Maxn];
char ch[Maxn];
int now=0;
bool check=true;
int dfs(int u)
{
    for (int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        pos[u]=dfs(v);
        if (len[u]!=0&&len[u]!=len[v]+1) check=false;
        len[u]=len[v]+1;
    }
    if ((int)g[u].size()==0) pos[u]=u;
    if (u==0||(int)g[u].size()==2)
    {
        pos[u]=u;
        for (int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            top[pos[v]]=u;
            son[u].push_back(pos[v]);
        }
    }
    return pos[u];
}
void update(int u,int x,int val)
{
    sum[u][x]+=val;
    for (u=top[u];u!=-1;u=top[u])
    {
        if (cnt[u]>len[u]) --now;
        cnt[u]-=f[u][x];
        f[u][x]=0;
        for (int i=0;i<(int)son[u].size();i++)
        {
            int v=son[u][i];
            f[u][x]=max(f[u][x],f[v][x]+sum[v][x]);
        }
        cnt[u]+=f[u][x];
        if (cnt[u]>len[u]) ++now;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=2;i<=n;i++)
    {
        int u;
        scanf("%d",&u);
        g[u].push_back(i);
        ch[i]=getchar();
        while ((ch[i]<'a'||ch[i]>'z')&&(ch[i]!='?')) ch[i]=getchar();
    }
    g[0].push_back(1);
    dfs(0);
    --len[0];
    top[0]=-1;
    if (!check)
    {
        while (q--) printf("Fou\n");
        return 0;
    }
    for (int i=2;i<=n;i++)
        if (ch[i]!='?') update(pos[i],ch[i]-'a',1);
    while (q--)
    {
        int u;
        scanf("%d",&u);
        if (ch[u]!='?') update(pos[u],ch[u]-'a',-1);
        ch[u]=getchar();
        while ((ch[u]<'a'||ch[u]>'z')&&(ch[u]!='?')) ch[u]=getchar();
        if (ch[u]!='?') update(pos[u],ch[u]-'a',1);
        if (now>0) printf("Fou\n"); else
        {
            long long ans=0LL;
            for (int i=0;i<26;i++)
                ans+=1LL*(i+1)*(len[0]-cnt[0]+f[0][i]);
            printf("Shi %lld\n",ans);
        }
    }
    return 0;
}