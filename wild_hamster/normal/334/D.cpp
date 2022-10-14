#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef double db;
map <ll,ll> f5;
ll a[3001],b[3000],c[300000],n,m,k,i,j,x1,x2,k1,k2,k3,k4;
struct A
{
ll a,b;
};
bool f(A x, A y)
{
if (x.a<y.a) return true;
else if (x.a==y.a&&x.b<y.b) return true; else return false;
}
int main()
{
cin>>n>>m;
for (i=0;i<2000;i++) {a[i]=1;b[i]=1;}
while (m--)
{
cin>>x1>>x2;
a[x1]=0;b[x2]=0;
}
ll s=0;
for (i=2;i<=n/2;i++)
s+=a[i]+b[i]+a[n-i+1]+b[n-i+1];
if (n%2&&(a[(n+1)/2]!=0||b[(n+1)/2]!=0)) s++;
cout<<s<<endl;
return 0;
}