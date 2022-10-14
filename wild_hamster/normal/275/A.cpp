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
ll a[5][5],b[5][5],k[3][3],d,k1,k2,k3,i,n,j;
int main()
{
for (i=1;i<=3;i++)
for (j=1;j<=3;j++)
b[i][j]=1;
for (i=1;i<=3;i++)
for (j=1;j<=3;j++)
{
cin>>a[i][j];
b[i][j]+=a[i][j];
b[i-1][j]+=a[i][j];
b[i+1][j]+=a[i][j];
b[i][j-1]+=a[i][j];
b[i][j+1]+=a[i][j];
}
for (i=1;i<=3;i++)
{
for (j=1;j<=3;j++)
cout<<(b[i][j])%2;
cout<<endl;
}
return 0;
}