#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int p,x,k,i,j,s,z;
cin>>p;
k=0;
for (i=1;i<p;i++)
{
s=1;
z=0;
for (j=1;j<p-1;j++)
{
s=(s*i)%p;
if ((s-1)%p==0) z=1;
}
s=(s*i)%p;
if ((s-1)%p==0&&z==0) k++;
}
cout<<k;
return 0;
}