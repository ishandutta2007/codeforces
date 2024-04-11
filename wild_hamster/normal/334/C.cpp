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
ll a[300001],b[300000],c[300000],n,m,k,i,j,x1,x2,k1,k2,k3,k4;
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
cin>>n;
a[0]=1;
for (i=1;i<36;i++)
a[i]=a[i-1]*3;
for (i=0;i<36;i++)
f5[a[i]]=1;
for (i=0;i<36;i++)
if (a[i]==n) {cout<<1<<endl;return 0;}
for (i=0;i<36;i++)
if (n%a[i]!=0) {k=(n/a[i]+1);n=(n/a[i]+1)*a[i];break;}
//cout<<n<<endl;
/*k=0;
while (!f5[n])
{
cout<<n<<endl;
n-=a[upper_bound(a,a+36,n)-a-1];
k++;
}*/
cout<<k<<endl;
return 0;
}