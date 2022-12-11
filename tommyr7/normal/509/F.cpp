#include <bits/stdc++.h>
#define Maxn 507
#define modp 1000000007
using namespace std;
int n;
int a[Maxn];
int f[Maxn][Maxn];
bool vis[Maxn][Maxn];
int calc(int lx,int rx)
{
    if (vis[lx][rx]) return f[lx][rx];
    if (lx==rx) return 1;
    vis[lx][rx]=true;
    int &res=f[lx][rx];
    for (int i=lx+1;i<=rx;i++)
        if (i==rx||a[i+1]>a[lx+1])
        {
            int tmp=calc(lx+1,i);
            if (i<rx) tmp=(1LL*tmp*calc(i,rx))%modp;
            res=(res+tmp)%modp;
        }
    return res;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    memset(vis,false,sizeof(vis));
    printf("%d\n",calc(1,n));
    return 0;
}