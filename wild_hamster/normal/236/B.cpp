#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll s,m,k1,k2,k3,j,n,i,i1,i2,i3,max1,a[200][200];
ll gcd(ll a, ll b)
{
if (a<b) swap(a,b);
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
cin>>k1>>k2>>k3;
s=0;
for (i1=1;i1<=k1;i1++)
for (i2=1;i2<=k2;i2++)
for (i3=1;i3<=k3;i3++)
if (gcd(i1,i2)==gcd(i2,i3)&&gcd(i1,i3)==gcd(i2,i3)&&gcd(i1,i3)==1)
s+=(k1/i1)*(k2/i2)*(k3/i3);
cout<<s<<endl;
return 0;
}