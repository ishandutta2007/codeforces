#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
bool vis[1000007];
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    cin>>n>>m>>k;
    ans=1;
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=m;i++) 
    {
        int t;
        t=read();
        if (t<=n) vis[t]=true;
    }
    for (int i=1;i<=k;i++)
    {
        int u,v;
        u=read(),v=read();
        if ((ans==u||ans==v)&&(!vis[ans])) ans=u+v-ans;
    }
    cout << ans << endl;
    return 0;
}