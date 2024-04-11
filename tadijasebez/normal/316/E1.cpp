#include <stdio.h>
#define ll long long
const int N=105;
const int mod=1e9;
int a[N],f[N];
int main()
{
	int n,m,t,l,r,p,x,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	f[1]=1;
	for(i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod;
	while(m--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i",&p,&x),a[p]=x;
		if(t==2)
		{
			scanf("%i %i",&l,&r);
			int sol=0;
			for(i=l;i<=r;i++)
			{
				sol+=(ll)a[i]*f[i-l+1]%mod;
				sol%=mod;
			}
			printf("%i\n",sol);
		}
	}
}