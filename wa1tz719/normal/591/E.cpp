#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[1005][1005];
int dist[5][1005][1005];
int n,m;
int d[4][2]={
{1,0},
{0,1},
{-1,0},
{0,-1}};
inline bool ok(int x,int y)
{
    if (x<0) return false;
    if (y<0) return false;
    if (x>=n) return false;
    if (y>=m) return false;
    if (a[x][y]=='#') return false;
    return true;
}
void bfs(int num)
{
    int i,j;
    static int quex[1000005];
    static int quey[1000005];
    int front=0,rail=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]==num+'0')
            {
                quex[rail]=i;
                quey[rail]=j;
                dist[num][i][j]=0;
                rail++;
            }
        }
    }
    static int temp_quex[10000005];
    static int temp_quey[10000005];
    int t_front=0,t_rail=0;
    for (;front<rail;front++)
    {
        int nowx=quex[front];
        int nowy=quey[front];
        int i;
        for (i=0;i<4;i++)
        {
            int tx=nowx+d[i][0];
            int ty=nowy+d[i][1];
            if (ok(tx,ty))
            {
                if (dist[num][tx][ty]==-1)
                {
                    if (a[tx][ty]!='.')
                    {
                        dist[num][tx][ty]=dist[num][nowx][nowy];
                        temp_quex[t_rail]=tx;
                        temp_quey[t_rail]=ty;
                        t_rail++;
                    }
                    else
                    {
                        dist[num][tx][ty]=dist[num][nowx][nowy]+1;
                        quex[rail]=tx;
                        quey[rail]=ty;
                        rail++;
                    }
                }
            }
        }
        if (t_rail!=t_front)
        {
            quex[front]=temp_quex[t_front];
            quey[front]=temp_quey[t_front];
            t_front++;
            front--;
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    memset(dist,-1,sizeof(dist));
    bfs(1);
    bfs(2);
    bfs(3);
    int min_ans=999999999;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            if (dist[1][i][j]==-1) continue;
            if (dist[2][i][j]==-1) continue;
            if (dist[3][i][j]==-1) continue;
            int t=0;
            if (a[i][j]=='.')
            {
                t=-2;
            }
            else
            {
                t=0;
            }
            min_ans=min(min_ans,dist[1][i][j]+dist[2][i][j]+dist[3][i][j]+t);
        }
    }
    if (min_ans==999999999)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n",min_ans);
    return 0;
}