#include <bits/stdc++.h>
using namespace std;
#define Maxn 2000007
int n,a[Maxn],x;
bool vis[Maxn];
int main()
{
    scanf("%d%d",&n,&x);
    memset(vis,true,sizeof(vis));
    vis[x]=false;
    int cnt=0;
    for (int i=1;i<(1<<n);i++)
        if (vis[i]) 
        {
            vis[i^x]=false;
            a[++cnt]=i;
        }
    printf("%d\n",cnt);
    for (int i=cnt;i>=2;i--)
        a[i]^=a[i-1];
    for (int i=1;i<=cnt;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}