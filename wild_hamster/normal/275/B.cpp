#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll i1,j1,a[105][105],b[105][105],c[105][105],k[3][3],m,d,k1,k2,k3,i,n,j;
int main()
{
char c1;
cin>>m>>n;
for (i=0;i<m;i++)
for (j=0;j<n;j++)
{
cin>>c1;
if (c1=='W') a[i][j]=0; else a[i][j]=1;
c[i][j]=b[i][j]=a[i][j];
}
for (i=0;i<m;i++)
for (j=0;j<n;j++)
if (a[i][j]==1)
{
b[i][j]=2;
k1=i+1;
while (b[k1][j]>0) {
b[k1][j]=2;k2=j+1;
while (b[k1][k2]>0) {b[k1][k2]=2;k2++;}
k2=j-1;
while (b[k1][k2]>0) {b[k1][k2]=2;k2--;}
k1++;
}
k1=i-1;
while (b[k1][j]>0) {
b[k1][j]=2;
k2=j+1;
while (b[k1][k2]>0) {b[k1][k2]=2;k2++;}
k2=j-1;
while (b[k1][k2]>0) {b[k1][k2]=2;k2--;}
k1--;
}

k1=j+1;
while (b[i][k1]>0) {
b[i][k1]=2;k2=i+1;
while (b[k2][k1]>0) {b[k2][k1]=2;k2++;}
k2=i-1;
while (b[k2][k1]>0) {b[k2][k1]=2;k2--;}
k1++;
}
k1=j-1;
while (b[i][k1]>0) {
b[i][k1]=2;
k2=i+1;
while (b[k2][k1]>0) {b[k2][k1]=2;k2++;}
k2=i-1;
while (b[k2][k1]>0) {b[k2][k1]=2;k2--;}
k1--;
}
//cout<<endl;
for (i1=0;i1<m;i1++)
{
//cout<<endl;
for (j1=0;j1<n;j1++)
{
   // cout<<b[i1][j1];
if (b[i1][j1]==1) {cout<<"NO";return 0;}
if (b[i1][j1]==2) b[i1][j1]=1; 
}
}
}
cout<<"YES";
return 0;
}