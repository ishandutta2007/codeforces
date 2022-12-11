#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,k,ans;
int u[100007],v[100007],l[100007];
bool vis[100007];
int main()
{
    n=read(),m=read(),k=read();ans=inf;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++) u[i]=read(),v[i]=read(),l[i]=read();
    for (int i=1;i<=k;i++) vis[read()]=1;
    for (int i=1;i<=m;i++)
        if (vis[u[i]]+vis[v[i]]==1&&l[i]<ans) ans=l[i];
    if (ans==inf) ans=-1;
    cout << ans << endl;
    return 0;
}