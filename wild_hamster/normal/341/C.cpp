#include <iostream>
using namespace std;
typedef long long ll;
#define tr 1000000007
ll rez,z,x,y1,y2,m,n,i,j,k1,k,a[100500],b[100500],c[100500],d[20005],rev[20005];
ll binpow(ll x, ll k)
{
if (k==0) return 1; 
if (k%2==1) return (binpow(x,k-1)*x)%tr; 
ll t=binpow(x,k/2);
return (t*t)%tr;
}
ll C(ll n,ll k)
{
if (n<k) return 0;
return (((a[n]*rev[k])%tr)*rev[n-k])%tr;
}
int main()
{
a[0]=1;rev[0]=1;
a[1]=1;
for (i=2;i<2004;i++)
a[i]=(a[i-1]*i)%tr;
for (i=1;i<2004;i++)
rev[i]=binpow(a[i],tr-2)%tr;
cin>>n;
for (i=1;i<=n;i++) d[i]=1;
k=0;
for (i=1;i<=n;i++)
{
cin>>b[i];
if (b[i]==-1) {k++;c[i]=1;} else d[b[i]]=0;
}
m=0;
for (i=1;i<=n;i++)
if (c[i]&&d[i]) m++;
i=0;
rez=a[k];z=-1;
while (i<=m)
{
i++;
rez+=z*((C(m,i)*a[k-i])%tr);
z*=-1;
}
rez=(rez+(100500*(ll)tr))%tr;
cout<<rez<<endl;
return 0;
}