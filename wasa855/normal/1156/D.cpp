#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[200005][4];
int find(int x,int y)
{
    int i=x;
    while(i!=f[i][y]) i=f[i][y];
    while(x!=f[x][y])
    {
        int j=f[x][y];
        f[x][y]=i;
        x=f[j][y];
    }
    return i;
}
int a[200005],b[200005];
signed main()
{
    int n;
    cin>>n;
    int u,v,w;
    for(int i=1;i<=n;i++)
    {
        f[i][0]=i;
        f[i][1]=i;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%I64d %I64d %I64d",&u,&v,&w);
        int x=find(u,w),y=find(v,w);
        if(x!=y) f[x][w]=y;
    }
    for(int i=1;i<=n;i++)
    {
        a[find(i,0)]++;
        b[find(i,1)]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+(a[find(i,0)]*b[find(i,1)])-1;
    }
    cout<<ans<<endl;
    return 0;
}