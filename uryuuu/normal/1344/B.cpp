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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

string s[maxn];
int a[1005][1005];
int v[1005][1005];
int n,m;

void dfs(int x,int y)
{
    v[x][y]=1;
    int xx,yy;
    for(int i=0;i<4;i++)
    {
        xx=x+d[i][0];
        yy=y+d[i][1];
        if(xx<1||xx>n||yy<1||yy>m)
            continue;
        if(a[xx][yy]==0)
            continue;
        if(v[xx][yy])
            continue;
        dfs(xx,yy);
    }
}

int main()
{
    sync;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1][j-1]=='#')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    
    
    int ff=0;
    int cf=0,rf=0;
    
    for(int i=1;i<=n;i++)
    {
        ff=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                ff=1;
                break;
            }
        }
        if(ff==0)
        {
            rf=1;
            break;
        }
    }
    
    
    
    for(int i=1;i<=m;i++)
    {
        ff=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][i]==1)
            {
                ff=1;
                break;
            }
        }
        if(ff==0)
        {
            cf=1;
            break;
        }
    }
    
    
    
    
    
    
    for(int i=1;i<=n;i++)
    {
        ff=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                if(ff&&a[i][j-1]==0)
                {
                    f=1;
                    break;
                }
                else
                    ff=1;
            }
        }
        if(ff==0)
        {
            if(cf==0)
            {
                f=1;
            }
        }
        if(f)
            break;
    }
    
    for(int i=1;i<=m;i++)
    {
        ff=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][i]==1)
            {
                if(ff&&a[j-1][i]==0)
                {
                    f=1;
                    break;
                }
                else
                    ff=1;
            }
        }
        if(ff==0)
        {
            if(rf==0)
            {
                f=1;
            }
        }
        if(f)
            break;
    }
    
//    cout<<cf<<' '<<rf<<endl;
    
    
    if(f)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==0&&a[i][j]==1)
            {
                dfs(i,j);
                sum++;
            }
        }
    }
    
    cout<<sum<<endl;
    
    return 0;
}