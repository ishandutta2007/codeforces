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
bool attack[105][105];
char a[105][105];
bool visit[105][105];
bool ok_data=true;
int n;
void get_test(int x,int y)
{
    int i,j;
    int ans=-1;
    for (i=0;i<n;i++)
    {
        if (i+x<0) continue;
        if (i+x>=n) continue;
        for (j=0;j<n;j++)
        {
            if (j+y<0) continue;
            if (j+y>=n) continue;
            if (a[i][j]!='o') continue;
            if (a[i+x][j+y]=='.')
            {
                ans=0;
            }
        }
    }
    if (ans==-1)
    {
        attack[x+n][y+n]=1;
        int sum=0;
        for (i=0;i<n;i++)
        {
            if (i+x<0) continue;
            if (i+x>=n) continue;
            for (j=0;j<n;j++)
            {
                if (j+y<0) continue;
                if (j+y>=n) continue;
                if (a[i][j]!='o') continue;
                sum++;
                visit[i+x][j+y]=true;
            }
        }
        if (sum==0)
        {
            attack[x+n][y+n]=rand()%2;
        }
    }
    else
    {
        attack[x+n][y+n]=ans;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    int j;
    for (i=-n+1;i<=n-1;i++)
    {
        for (j=-n+1;j<=n-1;j++)
        {
            get_test(i,j);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if ((a[i][j]=='x')&&(!visit[i][j]))
            {
                ok_data=false;
            }
        }
    }
    if (ok_data)
    {
        printf("YES\n");
        for (i=-n+1;i<n;i++)
        {
            for (j=-n+1;j<n;j++)
            {
                if ((i==0)&&(j==0))
                {
                    printf("o");
                }
                else if (attack[i+n][j+n])
                {
                    printf("x");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}