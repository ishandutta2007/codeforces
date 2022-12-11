#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt;
int last[200007],pre[200007],other[200007];
int color[200007];
bool check;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u)
{
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (color[v]==0)
        {
            color[v]=3-color[u];
            dfs(v);
        } else if (color[v]+color[u]!=3) check=false;
    }
}
int main()
{
    n=read(),m=read(),cnt=0;
    for (int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        insert(u,v),insert(v,u);
    }
    memset(color,0,sizeof(color));
    check=true;
    for (int i=1;i<=n;i++)
        if (color[i]==0)
        {
            color[i]=1;
            dfs(i);
        }
    if (!check) cout << -1 << endl; else
    {
        int tot=0;
        for (int i=1;i<=n;i++) if (color[i]==1) ++tot;
        cout << tot << endl;
        for (int i=1;i<=n;i++) if (color[i]==1) cout << i << ' ';
        cout << endl;
        tot=0;
        for (int i=1;i<=n;i++) if (color[i]==2) ++tot;
        cout << tot << endl;
        for (int i=1;i<=n;i++) if (color[i]==2) cout << i << ' ';
        cout << endl;
    }
}