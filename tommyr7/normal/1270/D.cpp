#include <bits/stdc++.h>
#define Maxn 507
using namespace std;
int n,k;
int pos,v;
int val[Maxn],que[Maxn];
bool vis[Maxn],flag[Maxn];
void query()
{
    printf("? ");
    for (int i=1;i<=n;i++)
        if (vis[i]) printf("%d ",i);
    printf("\n");
    fflush(stdout);
}
int main()
{
    scanf("%d%d",&n,&k);
    memset(val,-1,sizeof(val));
    for (int i=1;i<=k;i++)
        vis[i]=true;
    for (int r=1;r<=n-k+1;r++)
    {
        query();
        scanf("%d%d",&pos,&v);
        val[pos]=v;
        vis[pos]=false;
        que[r]=pos;
        vis[k+r]=true;
    }
    memset(vis,false,sizeof(vis));
    vis[que[1]]=true;
    vis[que[2]]=true;
    if (val[que[1]]>val[que[2]]) swap(que[1],que[2]);
    for (int i=1;i<=n;i++)
        if (val[i]==-1) vis[i]=true;
    for (int r=1;r<=n;r++)
        if (val[r]==-1)
        {
            vis[r]=false;
            query();
            vis[r]=true;
            scanf("%d%d",&pos,&v);
            if (pos==que[2]) flag[r]=false; else flag[r]=true;
        }
    int m=1;
    for (int i=1;i<=n;i++)
        if (val[i]==-1&&flag[i]==false) ++m;
    printf("! %d\n",m);
    fflush(stdout);
    return 0;
}