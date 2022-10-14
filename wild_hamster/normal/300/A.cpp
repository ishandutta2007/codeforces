#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
int m,n,i,j,k,k1,k2,k3,a[100010],b[300],c[300],d[300];
cin>>n;
k1=0;k2=0;k3=0;
for (i=0;i<n;i++) 
{
cin>>a[i];
if (a[i]<0) {b[k1]=a[i];k1++;} else
if (a[i]==0) {c[k2]=a[i];k2++;} else {d[k3]=a[i];k3++;}
}
cout<<1<<" "<<b[0]<<endl;
if (k3==0) 
{
cout<<2<<" "<<b[1]<<" "<<b[2]<<endl; 
cout<<n-3<<" ";
for (i=3;i<k1;i++) cout<<b[i]<<" ";
for (i=0;i<k2;i++) cout<<c[i]<<" ";
}
else
{
cout<<1<<" "<<d[0]<<endl;
cout<<n-2<<" ";
for (i=1;i<k1;i++) cout<<b[i]<<" ";
for (i=0;i<k2;i++) cout<<c[i]<<" ";
for (i=1;i<k3;i++) cout<<d[i]<<" ";
}
//system("pause");
return 0;
}