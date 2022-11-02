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
char a[105][105];
char c[1005];
int loc[35];
int n,m,k;
inline int code(int x,int y)
{
    return x*m+y;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&k);
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
            if (a[i][j]>='a')
            {
                loc[a[i][j]-'a']=code(i,j); 
            }
        }
    }
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    i=0;
    scanf("%s",c);
    int t=strlen(c);
    c[t]='z'+1;
    int xx,yy;
    scanf("%d%d",&xx,&yy);
    xx--;
    yy--;
    loc[26]=code(xx,yy);
    for (;i<=t;)
    {
        if (a[x][y]=='#')
        {
            puts("Error!");
            return 0;
        }
        if (a[x][y]>='a')
        {
            k--;
        }
        else
        {
            k-=a[x][y]-'0';
        }
        if (k<0)
        {
            printf("%d %d\n",x+1,y+1);
            return 0;
        }
        int tx=loc[c[i]-'a']/m;
        int ty=loc[c[i]-'a']%m;
        if (x==tx)
        {
            if (y<ty)
            {
                y++;
            }
            else
            {
                y--;
            }
        }
        else if (y==ty)
        {
            if (x<tx)
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        else
        {
            puts("Error...");
            return 0;
        }
        if ((tx==x)&&(ty==y))
        {
            i++;
        }
    }
    printf("%d %d\n",x+1,y+1);
    return 0;
}