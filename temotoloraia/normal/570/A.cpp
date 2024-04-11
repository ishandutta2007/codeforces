#include <algorithm>
#include <iostream>
using namespace std;
long long int k[10009],max3,k1,a,b,c,max1=-1,max2,p,p1;
int main ()
{
cin>>a>>b;
for (int i=0;i<b;i++)
{
for (int i1=0;i1<a;i1++)
{
cin>>c;
if (c>max1) {max1=c;p=i1;}
}
max1=-1;
k[p]++;
}
for (int i2=0;i2<a;i2++)
if (max3<k[i2]) {max3=k[i2];k1=i2;}
cout<<k1+1<<endl;
return 0;
}