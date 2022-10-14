#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll rez,sum,k,m,k1,k2,k3,i,n,j;
ll a[10][10];
vector <vector <ll> > f(100005);
int main()
{
for (i=0;i<3;i++)
for (j=0;j<3;j++)
cin>>a[i][j];
for (a[0][0]=1;a[0][0]<=100000;a[0][0]++)
{
a[1][1]=a[0][0]+a[0][2]-a[2][1];
a[2][2]=a[0][1]+a[0][2]-a[1][1];
if (a[0][0]>0&&a[1][1]>0&&a[2][2]>0&&a[0][0]+a[1][1]==a[0][2]+a[1][2])
{
for (i=0;i<3;i++)
{
for (j=0;j<3;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}
return 0;
}
}
return 0;
}