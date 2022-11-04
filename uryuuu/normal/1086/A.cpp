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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

struct node
{
    int x,y;
}a[10],ans[maxn*10];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

int vis[1050][1050];

int main()
{
    sync;
    for(int i=1;i<=3;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    
    sort(a+1,a+4,cmp);
    int x=a[1].x;
    int y=a[1].y;
    int cnt=0;
    while(x<a[2].x)
    {
        ans[++cnt].x=x;
        ans[cnt].y=y;
        vis[x][y]=1;
        x++;
    }
    
    if(y<a[2].y)
    {
        while(y<a[2].y)
        {
            ans[++cnt].x=x;
            ans[cnt].y=y;
            vis[x][y]=1;
            y++;
        }
        ans[++cnt].x=x;
        ans[cnt].y=y;
        vis[x][y]=1;
    }
    else
    {
        while(y>a[2].y)
        {
            ans[++cnt].x=x;
            ans[cnt].y=y;
            vis[x][y]=1;
            y--;
        }
        ans[++cnt].x=x;
        ans[cnt].y=y;
        vis[x][y]=1;
    }
    
    int mn=99999999;
    for(int i=1;i<=cnt;i++)
    {
        if(abs(ans[i].x-a[3].x)+abs(ans[i].y-a[3].y)<mn)
        {
            x=ans[i].x;
            y=ans[i].y;
            mn=abs(ans[i].x-a[3].x)+abs(ans[i].y-a[3].y);
        }
    }
    
    while(x<a[3].x)
    {
        if(vis[x][y]==0)
        {
            ans[++cnt].x=x;
            ans[cnt].y=y;
            vis[x][y]=1;
        }
        x++;
    }
    
    if(y<a[3].y)
    {
        while(y<a[3].y)
        {
            if(vis[x][y]==0)
            {
                ans[++cnt].x=x;
                ans[cnt].y=y;
                vis[x][y]=1;
            }
            y++;
        }
        if(vis[x][y]==0)
        {
            ans[++cnt].x=x;
            ans[cnt].y=y;
            vis[x][y]=1;
        }
    }
    else
    {
        while(y>a[3].y)
        {
            if(vis[x][y]==0)
            {
                ans[++cnt].x=x;
                ans[cnt].y=y;
                vis[x][y]=1;
                
            }
            y--;
        }
        if(vis[x][y]==0)
        {
            ans[++cnt].x=x;
            ans[cnt].y=y;
            vis[x][y]=1;
        }
    }
    
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<ans[i].x<<' '<<ans[i].y<<endl;
    }
    
    
    return 0;
}