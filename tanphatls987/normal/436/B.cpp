#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=2010;

int a[4][maxi][maxi]={0},n,m,k,i,j,st,ans[maxi]={0};
char s[maxi];
int convert(int x)
{
    if (x=='L') return 1;
    if (x=='R') return 2;
    if (x=='U') return 3;
    return 0;
}
int readfile()
{
    //freopen("436b.txt","r",stdin);
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        cin>>s;
        for(j=0;j<m;j++) a[convert(s[j])][i][j+1]=1;
    }
}
int solve()
{
    for(st=1;st<=m;st++)
    {
        for(i=0;i<n;i++)
        {
            j=st+i;
            //printf("%d ",j);
            if (j<=m) ans[st]+=a[1][i][j];
            j=st-i;
            //printf("%d ",j);
            if (j>0) ans[st]+=a[2][i][j];
            //printf("%d ",st);
            if (2*i<n) ans[st]+=a[3][2*i][st];
            //check();
        }
    }
    for(i=1;i<=m;i++) printf("%d ",ans[i]);
}
int main()
{
    readfile();
    solve();
}