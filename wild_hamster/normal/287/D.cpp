#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int i,j,n,k,z,a[3000000];
cin>>n;
for (i=1;i<=n;i++)
a[i]=i;k=1;
for (i=2;i<=n;i++)
{
z=a[k+(n/i)*i];
for (j=n/i-1;j>=0;j--)
a[k+i*j+i]=a[k+i*j];
k++;
if (n%i!=0) a[k+n-1]=z;
}
for (i=k;i<=k+n-1;i++)
printf("%d ",a[i]);
//system("pause");
return 0;
}