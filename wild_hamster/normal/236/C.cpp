#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll m,k1,k2,k3,t,j,n,i,i1,i2,i3,max1,a[200][200];
ll gcd(ll a, ll b)
{
if (a<b) swap(a,b);
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
cin>>n;
if (n==1) {cout<<1;return 0;}
if (n==2) {cout<<2;return 0;}
max1=0;
for (k1=n-1;k1<=n;k1++)
for (k2=n-2;k2<=n;k2++)
for (k3=n-3;k3<=n;k3++)
{
i1=k1;i2=k2;i3=k3;
i1/=gcd(i1,i2);
i1/=gcd(i1,i3);
i2/=gcd(i2,i3);
if (i1*i2*i3>max1) max1=i1*i2*i3;
}
cout<<max1<<endl;
return 0;
}