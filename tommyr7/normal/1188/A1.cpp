#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int d[Maxn];
int main()
{
    scanf("%d",&n);
    if (n==2)
    {
        printf("YES\n");
        return 0;
    }
    if (n==3)
    {
        printf("NO\n");
        return 0;
    }
    memset(d,0,sizeof(d));
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
        ++d[u],++d[v];
    }
    for (int i=1;i<=n;i++)
        if (d[i]==2)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}