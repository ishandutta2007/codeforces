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
int a[4]={0,1,2,3};
int d[4][2]={
{0,-1},
{0,1},
{-1,0},
{1,0}};
char b[105][105];
char c[105];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",b[i]);
    }
    scanf("%s",c);
    int nowx,nowy;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            if (b[i][j]=='S')
            {
                nowx=i;
                nowy=j;
            }
        }
    }
    int ans=0;
    for (;;)
    {
        int i;
        int x=nowx;
        int y=nowy;
        for (i=0;c[i]!='\0';i++)
        {
            x+=d[a[c[i]-'0']][0];
            y+=d[a[c[i]-'0']][1];
            if ((x<0)||(y<0)||(x>=n)||(y>=m)) break;
            if (b[x][y]=='#') break;
            if (b[x][y]=='E')
            {
                ans++;
                break;
            }
        }
        if (!next_permutation(a,a+4)) break;
    }
    printf("%d\n",ans);
    return 0;
}