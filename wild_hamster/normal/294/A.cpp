#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
int m,n,k,i,j,a[1000],b[1000][2];
cin>>n;
for (i=0;i<n;i++)
cin>>a[i];
cin>>m;
for (i=0;i<m;i++)
{
cin>>b[i][0]>>b[i][1];
b[i][0]--;
}
for (i=0;i<m;i++)
{
if (b[i][0]>0) a[b[i][0]-1]+=b[i][1]-1;
if (b[i][0]<n-1) a[b[i][0]+1]+=a[b[i][0]]-b[i][1];
a[b[i][0]]=0;
}
for (i=0;i<n;i++)
cout<<a[i]<<endl;
return 0;
}