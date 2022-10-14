#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace std;
int main()
{
int i,x,n,k1,k2,s1,s2;
string c,c1;//c[1000000],c1[1000000];
cin>>c;
cin>>c1;
if (c.length()!=c1.length())
{
cout<<"NO";
return 0;
}
s1=0;
for (i=0;i<c.length();i++)
if (c[i]=='1') s1=1;
s2=0;
for (i=0;i<c1.length();i++)
if (c1[i]=='1') s2=1;
if (s1+s2==1) cout<<"NO"; else cout<<"YES"; 
return 0;
}