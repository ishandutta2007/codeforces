#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans;
int x[210],y[210];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
    {
        bool vis[4]={0};
        for(int j=1;j<=n;j++)
        {
            
            if(x[j]>x[i]&&y[j]==y[i]) vis[0]=1;
            if(x[j]<x[i]&&y[j]==y[i]) vis[1]=1;
            if(x[j]==x[i]&&y[j]<y[i]) vis[2]=1;
            if(x[j]==x[i]&&y[j]>y[i]) vis[3]=1;
        }
        if(vis[0]&&vis[1]&&vis[2]&&vis[3]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}