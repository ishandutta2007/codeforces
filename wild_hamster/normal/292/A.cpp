#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
int max2(int x, int y)
{
if (x>y) return x; else return y;
}
int main()
{
int m,n,k,t,k1,i,j,max1,mst,a[10000][2];
cin>>n;
for (i=0;i<n;i++)
cin>>a[i][0]>>a[i][1];
mst=a[0][1];t=a[0][0];max1=mst;
for (i=1;i<n;i++)
{
t+=a[i][0]-a[i-1][0];
mst=max2(0,mst+a[i-1][0]-a[i][0])+a[i][1];
if (mst>max1) max1=mst;
}
cout<<t+mst<<" "<<max1;
return 0;
}