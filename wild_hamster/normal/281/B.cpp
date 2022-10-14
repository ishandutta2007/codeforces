#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int i,a,b,x,y,n;
double t,t1;
cin>>x>>y>>n;
t1=((double)x)/y;
t=1+(double)x/y;
for (i=1;i<=n;i++)
{
if (abs((double)(int)(t1*i)/i-t1)<t) 
 {
t=abs((double)(int)(t1*i)/i-t1);
a=(int)((((double)x)/y)*i);
b=i;
 }
if (abs((double)(int)(t1*i+1)/i-t1)<t)  
 {
t=abs((double)(int)(t1*i+1)/i-t1);
a=(int)((((double)x)/y)*i)+1;
b=i;
 }
}
cout<<a<<"/"<<b;
return 0;
}