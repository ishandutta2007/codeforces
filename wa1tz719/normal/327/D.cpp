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
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[505][505];
int n,m;
void dfs1(int x,int y)
{
    if (x<0) return ;
    if (x>=n) return ;
    if (y<0) return ;
    if (y>=m) return ;
    if (a[x][y]!='.') return ;
    a[x][y]='!';
    dfs1(x,y+1);
    dfs1(x,y-1);
    dfs1(x+1,y);
    dfs1(x-1,y);
}
void dfs2(int x,int y)
{
    static int orz=0;
    if (x<0) return ;
    if (x>=n) return ;
    if (y<0) return ;
    if (y>=m) return ;
    if (a[x][y]!='!') return ;
    orz++;
    a[x][y]='?';
    dfs2(x,y+1);
    dfs2(x,y-1);
    dfs2(x+1,y);
    dfs2(x-1,y);
    if (orz!=1) printf("D %d %d\n",x+1,y+1);
    if (orz!=1) printf("R %d %d\n",x+1,y+1);
    orz--;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    int i,j;
    int sum=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            char x;
            for (;;)
            {
                scanf("%c",&x);
                if (x=='.')
                {
                    sum++;
                    break;
                }
                if (x=='#') break;
            }
            a[i][j]=x;
        }
    }
    sum*=3;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]!='.') continue;
            dfs1(i,j);
            sum-=2;
        }
    }
    printf("%d\n",sum);
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]!='#') printf("B %d %d\n",i+1,j+1);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]!='!') continue;
            dfs2(i,j);
        }
    }
    return 0;
}