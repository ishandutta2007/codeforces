#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace std;
int main()
{
int i,x,n,rizn,k1,k2,s1,s2;
string c;
cin>>n;
s1=0;s2=0;
for (i=0;i<n;i++)
{
scanf("%d%d",&k1,&k2);
if (abs(s1+k1-s2)<=500)
{c.append("A");s1+=k1;}
else 
{c.append("G");s2+=k2;}
}
if (abs(s1-s2)>500) cout<<"-1"; else 
cout<<c<<endl;
return 0;
}