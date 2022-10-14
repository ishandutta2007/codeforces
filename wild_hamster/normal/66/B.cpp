#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
ll s,y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[10000];
vector <ll> f;
int main()
{
cin>>n;
for (i=0;i<n+5;i++) a[i]=(ll)1e+15;
for (i=1;i<=n;i++) cin>>a[i];
ll max1=-1;
for (i=1;i<=n;i++)
{
j=i;k=1;
while (a[j+1]<=a[j]) {j++;k++;}
j=i;
while (a[j-1]<=a[j]) {j--;k++;}
max1=max(k,max1);
}
cout<<max1<<endl;
return 0;
}