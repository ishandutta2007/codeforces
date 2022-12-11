#include <bits/stdc++.h>
#define Maxn 600007
using namespace std;
int n;
bool vis[Maxn];
int main()
{
    scanf("%d",&n);
    memset(vis,false,sizeof(vis));
    int now=n;
    printf("%d ",1);
    for (int i=1;i<=n;i++)
    {
       int x;
       scanf("%d",&x);
       vis[x]=true;
       while (vis[now]) --now;
       printf("%d ",i+now+1-n);
    }
    printf("\n");
    return 0;
}