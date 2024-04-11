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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int a[1005][1005];
int vis[1005][1005];
string s[1005];
queue<pair<int,int>>q;

int main()
{
    sync;
    int n,m,t;
    cin>>n>>m>>t;
    memset(a,inf,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=m;j++)
        {
            a[i][j]=int(s[i][j-1]-'0');
        }
    }
    
    int x,y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                x=i+d[k][0];
                y=j+d[k][1];
                if(a[x][y]==a[i][j])
                {
                    q.push(mkp(i,j));
                    vis[i][j]=1;
                }
            }
        }
    }
    
    ll p;
    if(q.empty())
    {
        for(int i=1;i<=t;i++)
        {
            cin>>x>>y>>p;
            cout<<a[x][y]<<endl;
        }
        return 0;
    }
    int xx,yy;
    while(q.size())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            xx=x+d[k][0];
            yy=y+d[k][1];
            if(xx<1||xx>n||yy<1||yy>m)
                continue;
            if(vis[xx][yy])
                continue;
            vis[xx][yy]=vis[x][y]+1;
            q.push(mkp(xx,yy));
        }
    }
    for(int i=1;i<=t;i++)
    {
        cin>>x>>y>>p;
        if(p<1ll*vis[x][y])
            cout<<a[x][y]<<endl;
        else
        {
            cout<<(1ll*(1ll*p+1ll-1ll*vis[x][y]+1ll*a[x][y])%2ll)<<endl;
        }
    }
    
    
    
    return 0;
}