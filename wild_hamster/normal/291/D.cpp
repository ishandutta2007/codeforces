#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;
int max2(int a, int b)
{
if (a>b) return a; else return b;
}
int main()
{
long long s,k,k1,k2,n,i,j,a[100000];
string c;
cin>>n>>k;
s=1;
for (i=0;i<k;i++)
{
for (j=max2(n-s,1);j<=n;j++) a[j]=n;
for (j=max2(n-2*s,1);j<=max2(n-s,1)-1;j++) a[j]=j+s;
for (j=1;j<max2(n-2*s,1);j++) a[j]=n-s;
for (j=1;j<=n;j++) cout<<a[j]<<" ";
cout<<endl;
s*=2;
}
return 0;
}