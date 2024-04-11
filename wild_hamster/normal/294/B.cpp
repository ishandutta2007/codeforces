#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int min1,s,i,j,n,x1,x2,k1,k2,b[1000],c[1000];
cin>>n;
x1=-1;x2=-1;s=0;
for (i=0;i<n;i++)
{
cin>>k1>>k2;
s+=k1;
if (k1==1) {x1++;b[x1+1]=k2;} else {x2++;c[x2+1]=k2;}
}
sort(b+1,b+x1+2);
sort(c+1,c+x2+2);
b[0]=0;c[0]=0;
for (i=1;i<=x1+1;i++)
b[i]+=b[i-1];
for (i=1;i<=x2+1;i++)
c[i]+=c[i-1];
min1=s+1;
for (i=0;i<=x1+1;i++)
for (j=0;j<=x2+1;j++)
if (s-(i)-(2*j)>=b[i]+c[j])
if (s-(i)-(2*j)<min1) min1=s-i-2*j;
cout<<min1<<endl;
return 0;
}