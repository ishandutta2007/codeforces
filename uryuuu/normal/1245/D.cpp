#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn=100005;
const ll Mod=1000000007;


struct node
{
    ll x,y,c,k;
}a[2005];

ll mp[2005][2005];
ll dis[2050];
int vis[2050];
int fa[2050];
int b[2050];
struct nod
{
    int u,v;
}t[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].c;
        mp[0][i]=mp[i][0]=a[i].c;
        dis[i]=a[i].c;
        fa[i]=0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i].k;
    int cnt=0;
    int dnt=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(i==j)
            {
                mp[i][j]=inf;
                continue;
            }
            mp[i][j]=mp[j][i]=(a[i].k+a[j].k)*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
        }
    }
    dis[0]=0;
    vis[0]=1;
    for(int k=1;k<=n;k++)
    {
        ll zx=1e18,pos;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0&&dis[i]<=zx)
            {
                zx=dis[pos=i];
            }
        }
        vis[pos]=1;
        sum+=zx;
        for(int j=0;j<=n;j++)
        {
            if(mp[pos][j]==zx&&vis[j]==1)
            {
                fa[pos]=j;
                break;
            }
        }
        for(int j=1;j<=n;j++)
        {
            dis[j]=min(dis[j],mp[pos][j]);
        }
    }
    
    
    
    
    
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==0)
            b[cnt++]=i;
        else
        {
            t[dnt].u=fa[i];
            t[dnt++].v=i;
        }
    }
    
    cout<<sum<<endl;
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    cout<<dnt<<endl;
    for(int i=0;i<dnt;i++)
        cout<<t[i].u<<' '<<t[i].v<<endl;
    return 0;
}