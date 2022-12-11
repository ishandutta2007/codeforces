#include <bits/stdc++.h>
#define Maxn 2000007
using namespace std;
int T,n;
int a[Maxn],nxt[Maxn];
bool vis[Maxn];
int path[Maxn],tot;
bool flag;
bool ans[Maxn];
void dfs(int u)
{
    if (flag) return;
    vis[u]=true;
    path[++tot]=u;
    if (vis[nxt[u]])
    {
        flag=true;
        for (int i=tot;i;i--)
        {
            ans[path[i]]=true;
            if (path[i]==nxt[u]) break;
        }
        return;
    }
    dfs(nxt[u]);
    --tot;
    vis[u]=false;
}
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        nxt[i]=i-a[i];
    for (int i=1;i<=n;i++)
        vis[i]=false,ans[i]=false;
    tot=0;
    flag=false;
    dfs(1);
    int sum=0;
    for (int i=1;i<=n;i++)
        if (ans[i]) ++sum;
    printf("%d\n",sum);
    for (int i=1;i<=n;i++)
        if (ans[i]) printf("%d ",i);
    printf("\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}