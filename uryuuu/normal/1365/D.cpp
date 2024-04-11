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
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int a[60][60];
int b[60][60];
int vis[60][60];
string s;

int fl=0;
int f=0;


void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+d[i][0];
        int ny=y+d[i][1];
        if(vis[nx][ny])
            continue;
        if(nx<1||nx>n||ny<1||ny>m)
            continue;
        vis[nx][ny]=1;
        if(a[nx][ny]!=1)
        {
            b[nx][ny]=1;
            dfs(nx,ny);
        }
    }
}


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ss=0;
        mm(a);
        mm(b);
        mm(vis);
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='.')
                    a[i][j+1]=0;
                else if(s[j]=='#')
                    a[i][j+1]=1;
                else if(s[j]=='B')
                    a[i][j+1]=2;
                else
                {
                    a[i][j+1]=3;
                    ss++;
                }
            }
        }
        if(ss==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        fl=0;
        int x,y;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==2)
                {
                    for(int k=0;k<4;k++)
                    {
                        x=i+d[k][0];
                        y=j+d[k][1];
                        if(a[x][y]==3)
                            fl=1;
                        if(x==n&&y==m)
                            fl=1;
                        if(a[x][y]==0)
                            a[x][y]=1;
                    }
                }
            }
        }
        
        b[n][m]=1;
        vis[n][m]=1;
        dfs(n,m);
        
//        for(int i=1;i<=n;i++)
//        {
//            rep(j,1,m)
//                cout<<a[i][j];
//            cout<<endl;
//        }
//        
//        cout<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            rep(j,1,m)
//                cout<<b[i][j];
//            cout<<endl;
//        }
//        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==3)
                {
                    if(b[i][j]==0)
                        fl=1;
                }
            }
        }
        if(fl)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        
        
    }
    return 0;
}