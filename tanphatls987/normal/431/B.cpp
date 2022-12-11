#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

const int maxi=5;

int a[5][5],i,j,h[5],s[5],tmp,ans=0;
int solve(int turn,int x)
{
    int i;
    h[x]=1;s[turn]=x;
    if (turn==4)
    {
        tmp=a[s[0]][s[1]]+a[s[1]][s[0]]+2*(a[s[2]][s[3]]+a[s[3]][s[2]])+a[s[1]][s[2]]+a[s[2]][s[1]]+2*(a[s[3]][s[4]]+a[s[4]][s[3]]);
        if (tmp>ans) ans=tmp;
    }
    else for(i=0;i<5;i++) if (!h[i]) solve(turn+1,i);
    h[x]=0;
}
int main()
{
    for(i=0;i<5;i++)
        for(j=0;j<5;j++) scanf("%d",&a[i][j]);
    for(i=0;i<5;i++) solve(0,i);
    printf("%d",ans);
}