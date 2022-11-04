#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
char s[105][105];
int vis[105][105];
int dr[8][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d,f;
int n,m;
//int flag;
//void dfs(int x,int y,int id,int sum,int g)
//{
//    if(sum>=g)
//    return;
//    if(flag==1)
//        return;
//    if(vis[x][y]==0)
//    {
//        vis[x][y]=id;
//        if(s[x][y]=='R')
//            sum++;
//        if(sum>=g)
//        {
//            flag=1;
//            return;
//        }
//        for(int i=0;i<4;i++)
//        {
//            int xx=x+dr[i][0];
//            int yy=y+dr[i][1];
//            if(xx>n||yy>m||xx<1||yy<1)
//                continue;
//            dfs(xx,yy,id,sum,g);
//            if(flag==1)
//            return;
//        }
//    }
//    return;
//}
//
//int dfs2(int x,int y)
//{
//
//    if(vis[x][y]!=0)
//        return vis[x][y];
//    int e=0;
//    for(int i=0;i<4;i++)
//    {
//        int xx=x+dr[i][0];
//        int yy=y+dr[i][1];
//        if(xx>n||yy>m||xx<1||yy<1)
//            continue;
//        e=dfs2(xx,yy);
//        break;
//    }
//    return vis[x][y]=e;
//}


int main()
{
    sync;
    int t,r;
    cin>>t;
    while(t--)
    {
        mm(vis);
        cin>>n>>m>>r;
        int w=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='R')
                    w++;
            }
        }
        if(w%r==0)
        {
            d=w/r;
            f=r;
        }
        else
        {
            d=w/r+1;
            f=w%r;
        }
//        cout<<d<<' '<<f<<' '<<r<<endl;
        int fl=1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                for(int j=1;j<=m;j++)
                {
                    vis[i][j]=fl;
                    if(s[i][j]=='R')
                    {
                        sum++;
                        if(sum==d&&fl<r)
                        {
                            fl++;
                            sum=0;
                            if(fl==f+1)
                                d--;
                        }
                    }
                }
            }
            else
            {
                for(int j=m;j>=1;j--)
                {
                    vis[i][j]=fl;
                    if(s[i][j]=='R')
                    {
                        sum++;
                        if(sum==d&&fl<r)
                        {
                            fl++;
                            sum=0;
                            if(fl==f+1)
                                d--;
                        }
                    }
                }
            }
        }
        
        int q;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                q=vis[i][j];
                if(1<=q&&q<=10)
                    cout<<q-1;
                else if(q<=36)
                    cout<<char('a'+(q-11));
                else
                    cout<<char('A'+(q-37));
            }
            cout<<endl;
        }
    }
    
    return 0;
}