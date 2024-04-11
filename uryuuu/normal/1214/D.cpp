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
#include<unordered_map>
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
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;
const ll p=998857459;


string s;

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int a[n+5][m+5];
    int b[n+m+10];
    bool mp[n+5][m+5];
    bool vis[n+5][m+5];
    mm(a);
    mm(b);
    mm(mp);
    mm(vis);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='#')
            {
                a[i][j]=1;
            }
            else
                a[i][j]=0;
        }
    }
    queue<pii>q;
    q.push(pii(1,1));
    int f=0;
    int x,y;
    while(q.size())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
//        cout<<x<<' '<<y<<endl;
        if(x==n&&y==m)
        {
            f=1;
            break;
        }
        if(mp[x+1][y]==0&&x+1<=n&&a[x+1][y]==0)
        {
            mp[x+1][y]=1;
            q.push(pii(x+1,y));
        }
        if(mp[x][y+1]==0&&y+1<=m&&a[x][y+1]==0)
        {
            mp[x][y+1]=1;
            q.push(pii(x,y+1));
        }
    }
    if(f==0)
    {
//        cout<<"FUCK"<<endl;
        cout<<0<<endl;
        return 0;
    }
    while(q.size())
        q.pop();
    
    q.push(pii(n,m));
    while(q.size())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        if(x==1&&y==1)
        {
            break;
        }
        if(vis[x-1][y]==0&&x-1>=1&&a[x-1][y]==0)
        {
            vis[x-1][y]=1;
            if(mp[x-1][y])
            {
//                cout<<x-1<<' '<<y<<endl;
                b[x-1+y-1]++;
                q.push(pii(x-1,y));
            }
        }
        if(vis[x][y-1]==0&&y-1>=1&&a[x][y-1]==0)
        {
            vis[x][y-1]=1;
            if(mp[x][y-1])
            {
//                cout<<x<<' '<<y-1<<endl;
                b[x-1+y-1]++;
                q.push(pii(x,y-1));
            }
        }
    }
    int zd=999;
    for(int i=2;i<=n+m-2;i++)
    {
        zd=min(zd,b[i]);
    }
    cout<<min(2,zd)<<endl;
    
    
    
    return 0;
}