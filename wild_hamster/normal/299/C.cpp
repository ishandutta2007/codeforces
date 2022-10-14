#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;
long long min2(long long a,long long b)
{
if (a<b) return a; else return b;
}
int main()
{
string c1,c2;
long long z,a[100010],b[100010],min1,m,n,k,i,j,k1,k2,k3,s,rez;
cin>>n;
cin>>c1;
cin>>c2;
k1=0;k2=0;k3=0;
for (i=0;i<2*n;i++)
if (c1[i]=='1'&&c2[i]=='1') k1++;
else if (c1[i]=='1'&&c2[i]=='0') k2++;
else if (c1[i]=='0'&&c2[i]=='1') k3++;
z=0;
s=min2(k2,k3);
k2-=s;k3-=s;
k1=k1%2;
if (k2>k3||(k2==k3&&k1==1)) cout<<"First"; else
if ((k2==k3&&k1==0)||(k2==k3-1)||(k1==1&&k2==k3-2)) cout<<"Draw";
else cout<<"Second";
//system("pause");
return 0;
}