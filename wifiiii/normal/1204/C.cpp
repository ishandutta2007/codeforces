
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dis[105][105];
int a[1000005],mk[1000005];
int vis[105];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        for(int j=1;j<=s.size();++j) if(s[j-1]=='1') dis[i][j]=1;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;++i) dis[i][i]=0;
    int m;
    cin>>m;
    for(int i=1;i<=m;++i) cin>>a[i];
    int cnt=1;mk[1]=1;
    for(int i=1;i<=m;)
    {
        if(i==m) break;
        memset(vis,0,sizeof(vis));
        int r=i+1;
        for(int j=i+1;j<=m;++j)
        {
            if(vis[a[j]]) break;
            if(dis[a[i]][a[j]]==j-i) r=j;
            vis[a[j]]=1;
        }
        ++cnt,mk[r]=1,i=r;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=m;++i) if(mk[i]) cout<<a[i]<<" ";
}