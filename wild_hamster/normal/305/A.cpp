#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
//map <ll,ll> a,b,c;
ll i1,i2,i3,r,c,i,j,m,n,k1,k2,k3,k4,k5,k6,k7,k8,k,a[100500],b[100500];
bool ffs(ll x,ll x1)
{
if ((x/100!=0&&x1/100!=0)||(x%10!=0&&x1%10!=0)||((x/10)%10!=0&&(x1/10)%10!=0))
return 0; else return 1; 
}
int main() 
{
k=0;
//cout<<ffs(505,50);
cin>>n;
vector <ll> f;
for (i=0;i<n;i++) {cin>>a[i]; if (a[i]==0) {a[i]=1111;k++;}}
for (i1=0;i1<n;i1++)
for (i2=i1+1;i2<n;i2++)
for (i3=i2+1;i3<n;i3++)
if (ffs(a[i1],a[i2])&&ffs(a[i1],a[i3])&&ffs(a[i2],a[i3]))
{
cout<<k+3<<endl;
if (k) cout<<0<<" ";
cout<<a[i1]<<" "<<a[i2]<<" "<<a[i3];
return 0;
}
for (i1=0;i1<n;i1++)
for (i2=i1+1;i2<n;i2++)
if (ffs(a[i1],a[i2]))
{
cout<<k+2<<endl;
if (k) cout<<0<<" ";
cout<<a[i1]<<" "<<a[i2];
return 0;
}
for (i=0;i<n;i++)
if (a[i]!=1111&&k) {cout<<2<<endl;cout<<a[i]<<" "<<0;return 0;}
cout<<1<<endl<<a[0]%1111;
return 0;
}