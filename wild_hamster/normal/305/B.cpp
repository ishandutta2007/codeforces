#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
//map <ll,ll> a,b,c;
ll p,q,i1,i2,i3,r,c,i,j,m,n,k1,k2,k3,k4,k5,k6,k7,k8,k,a[100500],b[100500];
ll gcd(ll a, ll b)
{
if (a<b) a=b;
if (b==0) return a;
else return gcd(b,a%b);
}
int main() 
{
k=0;
//cout<<ffs(505,50);
cin>>p>>q;
cin>>n;
for (i=1;i<=n;i++) cin>>a[i];
for (i=1;i<=n;i++)
{
k=gcd(p,q);
if (p<q) {cout<<"NO";return 0;}
if (p%q==0)
{
if ((i==n&&p/q==a[n])||(i==n-1&&a[i]==p/q-1&&a[i+1]==1)) {cout<<"YES";return 0;}
else {cout<<"NO";return 0;}
}
p/=k;q/=k;
if (p/q!=a[i]) {cout<<"NO";return 0;}
else {p=p%q;swap(p,q);}
}
cout<<"NO";
return 0;
}