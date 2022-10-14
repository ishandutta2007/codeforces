#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
int i,j,n,m,a[5][5],z;
string c;
for (i=0;i<4;i++)
{
cin>>c;
for (j=0;j<4;j++)
if (c[j]=='#') a[i][j]=1; else a[i][j]=0;
}
m=0;z=0;
for (i=0;i<3;i++)
for (j=0;j<3;j++)
if (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]!=2) z=1;
if (z==1) cout<<"YES"; else cout<<"NO";
return 0;
}