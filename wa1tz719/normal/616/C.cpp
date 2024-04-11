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
char a[1005][1005];
int belong[1005][1005];
int size[1000005];
int val=0;
int n,m;
bool check(int x,int y)
{
    if ((x<0)||(y<0)||(x>=n)||(y>=m)) return false;
    if (a[x][y]=='*') return false;
    return true;
}
void dfs(int x,int y,int z)
{
    size[z]++;
    belong[x][y]=z;
    if ((check(x-1,y))&&(belong[x-1][y]==-1))
    {
        dfs(x-1,y,z);
    }
    if ((check(x+1,y))&&(belong[x+1][y]==-1))
    {
        dfs(x+1,y,z);
    }
    if ((check(x,y-1))&&(belong[x][y-1]==-1))
    {
        dfs(x,y-1,z);
    }
    if ((check(x,y+1))&&(belong[x][y+1]==-1))
    {
        dfs(x,y+1,z);
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
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            belong[i][j]=-1;
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            if (a[i][j]=='*') continue;
            if (belong[i][j]==-1)
            {
                dfs(i,j,val);
                val++;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            if (a[i][j]=='*')
            {
                int ans=1;
                int x1=-1,x2=-2,x3=-3,x4=-4;
                if (check(i-1,j))
                {
                    x1=belong[i-1][j];
                    ans+=size[x1];
                }
                if (check(i+1,j))
                {
                    x2=belong[i+1][j];
                    if (x1!=x2) ans+=size[x2];
                }
                if (check(i,j-1))
                {
                    x3=belong[i][j-1];
                    if ((x1!=x3)&&(x2!=x3)) ans+=size[x3];
                }
                if (check(i,j+1))
                {
                    x4=belong[i][j+1];
                    if ((x1!=x4)&&(x2!=x4)&&(x3!=x4)) ans+=size[x4];
                }
                putchar(ans%10+'0');
            }
            else
            {
                putchar('.');
            }
        }
        putchar('\n');
    }
    return 0;
}