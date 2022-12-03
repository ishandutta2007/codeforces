#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define move moasudoasjsap
int a[4][55];
struct move
{
    int id;
    int x;
    int y;
    move (int iid=0,int xx=0,int yy=0)
    {
        id=iid;
        x=xx+1;
        y=yy+1;
    }
    void output()
    {
        printf("%d %d %d\n",id,x,y);
    }
};
vector<move> ans;
bool vis[105];
int n;
int newx,newy;
void find_next(int sx,int sy)
{
    newx=sx;
    newy=sy;
    if (sx==1)
    {
        if (sy==0)
        {
            newx++;
        }
        else
        {
            newy--;
        }
    }
    else
    {
        if (sy==n-1)
        {
            newx--;
        }
        else
        {
            newy++;
        }
    }
}
void find_way(int sx,int sy,int tx,int ty,int id)
{
    if ((sx==tx)&&(sy==ty)) return;
    find_next(sx,sy);
    int ttx=newx;
    int tty=newy;
    if (a[newx][newy]!=0)
    {
        if (a[ttx^1][tty]==a[ttx][tty])
        {
            ans.push_back(move(a[ttx][tty],ttx^1,tty));
            vis[a[ttx][tty]]=true;
            a[ttx][tty]=0;
        }
        else
        {
            find_next(ttx,tty);
            find_way(ttx,tty,newx,newy,a[ttx][tty]);
        }
    }
    ans.push_back(move(id,ttx,tty));
    a[ttx][tty]=id;
    a[sx][sy]=0;
    find_way(ttx,tty,tx,ty,id);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<4;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if (k==n+n)
    {
        for (i=1;i<=2;i++)
        {
            int j;
            for (j=0;j<n;j++)
            {
                if (a[i][j]==a[i^1][j])
                {
                    ans.push_back(move(a[i][j],i^1,j));
                    vis[a[i][j]]=true;
                    a[i][j]=0;
                    break;
                }
            }
            if (j!=n) break;
        }
        if (i==3)
        {
            puts("-1");
            return 0;
        }
    }
    for (i=1;i<=k;i++)
    {
        if (vis[i]) continue;
        int j;
        int final_x,final_y;
        int start_x,start_y;
        for (j=0;j<n;j++)
        {
            if (a[0][j]==i)
            {
                final_x=1;
                final_y=j;
            }
            if (a[3][j]==i)
            {
                final_x=2;
                final_y=j;
            }
            if (a[1][j]==i)
            {
                start_x=1;
                start_y=j;
            }
            if (a[2][j]==i)
            {
                start_x=2;
                start_y=j;
            }
        }
        find_way(start_x,start_y,final_x,final_y,i);
        ans.push_back(move(i,final_x^1,final_y));
        a[final_x][final_y]=0;
        vis[i]=true;
    }
    printf("%d\n",ans.size());
    for (i=0;i<ans.size();i++)
    {
        ans[i].output();
    }
    return 0;
}