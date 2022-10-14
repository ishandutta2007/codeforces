#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
string c;
int n,p,x,k,i,j,s,z,x1,x2,x3;
cin>>n;
cin>>c;
x1=0;x2=0;x3=0;
for (i=0;i<c.size();i++)
if (c[i]=='A') x1++; else
if (c[i]=='F') x2++; else
if (c[i]=='I') x3++;
if (x3==1) {cout<<1; return 0;}
else if (x3>1) {cout<<0; return 0;}
else cout<<x1;
return 0;
}