#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e6+10;
const ll mod=1e9+7;
char mp[70][70];
int n,m;

void solve()
{
    bool f1=0,f2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='A')f1=1;
            if(mp[i][j]=='P')f2=1;
        }
    }
    if(!f1)
    {
        puts("MORTAL");
        return;
    }
    if(!f2)
    {
        puts("0");
        return;
    }
    bool f3=0;
    for(int i=1;i<=n;i++)
    {
        if(mp[i][1]=='A'||mp[i][m]=='A')f3=1;
    }
    for(int i=1;i<=m;i++)
        if(mp[1][i]=='A'||mp[n][i]=='A')f3=1;
    if(!f3)
    {
        puts("4");
        return;
    }
    bool vis1[70]={0},vis2[70]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='P')
            {
                vis1[i]=1;
                vis2[j]=1;
            }
        }
    }
    if(mp[1][1]=='P'&&mp[1][m]=='P'&&mp[n][1]=='P'&&mp[n][m]=='P')
    {
        f1=0;
        for(int i=1;i<=n;i++)if(!vis1[i])f1=1;
        for(int i=1;i<=m;i++)if(!vis2[i])f1=1;
        if(f1)
        {
            puts("2");
        }
        else puts("3");
        return;
    }
    if(!vis1[1]||!vis2[1]||!vis1[n]||!vis2[m])
    {
        puts("1");
    }
    else puts("2");
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",mp[i]+1);
        solve();
    }
    return 0;
}