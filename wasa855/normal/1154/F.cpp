#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e12
int a[200005];
int f[200005];
int g[200005];
int s[200005];
signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld %lld",&x,&y);
        g[x]=max(g[x],y);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=k;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=k;i++)
    {
        f[i]=INF;
        for(int j=0;j<i;j++)
        {
            int del=g[i-j];
            int to=f[j]+s[i]-s[j+del];
            if(to<f[i])
            {
                f[i]=to;
            }
        }
    }
    // for(int i=1;i<=k;i++)
    // {
    //     printf("%lld ",f[i]);
    // }
    // cout<<"\n";
    cout<<f[k]<<endl;
    return 0;
}