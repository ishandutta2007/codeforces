#include <stdio.h>
const int mod=1e9+7;
int deg[200050];
long long pow(long long x, int k)
{
long long ans=1;
for(;k;k>>=1,x=x*x%mod)
if(k&1) ans=ans*x%mod;
return ans;
}
int main()
{
int n,u,v,i,l=0;
scanf("%i",&n);
for(i=1;i<n;i++)
{
scanf("%i %i",&u,&v);
deg[u]++;
deg[v]++;
}
for(i=1;i<=n;i++) if(deg[i]==1) l++;
long long ans1=1ll*(n-l)*pow(2,n-l)%mod;
long long ans2=1ll*l*pow(2,n-l+1)%mod;
printf("%i\n",(ans1+ans2)%mod);
return 0;
}