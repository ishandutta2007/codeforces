#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500050;
int n,a,m,r,h[N];
ll Calc(int x)
{
if(a+m<=r)
{
ll ret=0;
for(int i=0;i<n;i++)
{
if(h[i]<x)ret+=(x-h[i])*1ll*a;
else ret+=(h[i]-x)*1ll*m;
}
return ret;
}
else
{
ll rm=0,ad=0;
for(int i=0;i<n;i++)
{
if(h[i]>x)rm+=h[i]-x;
else ad+=x-h[i];
}
ll ret=min(rm,ad)*r;
ll mn=min(rm,ad);
rm-=mn;ad-=mn;
ret+=rm*m;
ret+=ad*a;
return ret;
}
}
int main()
{
scanf("%i%i%i%i",&n,&a,&m,&r);
for(int i=0;i<n;i++)scanf("%i",&h[i]);
int low=0,high=1e9,ans=0;
while(low<=high)
{
int mid=low+high>>1;
if(Calc(mid)<Calc(mid+1))ans=mid,high=mid-1;
else low=mid+1;
}
printf("%lld",Calc(ans));
return 0;
}