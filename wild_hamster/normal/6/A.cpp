#include <iostream>
using namespace std;
int main()
{
int i,j,a[5],k;
for (i=0;i<4;i++)
cin>>a[i];
for (i=0;i<4;i++)
for (j=i+1;j<4;j++)
if (a[i]>a[j]) swap(a[i],a[j]);
if (a[0]+a[1]<a[2]&&a[0]+a[2]<a[3]&&a[1]+a[2]<a[3])
cout<<"IMPOSSIBLE"; else
if (a[0]+a[1]>a[2]||a[0]+a[2]>a[3]||a[1]+a[2]>a[3])
cout<<"TRIANGLE"; else 
cout<<"SEGMENT";
return 0;
}