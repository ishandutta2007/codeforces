#include <stdio.h>
const int N=100050;
int w[N],sol=1e9+1e9+1e5,ans=0;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int l,r,Ql,Qr,n,i;
	scanf("%i %i %i %i %i",&n,&l,&r,&Ql,&Qr);
	for(i=1;i<=n;i++) scanf("%i",&w[i]),w[i]+=w[i-1];
	for(i=0;i<=n;i++)
	{
		ans=l*w[i]+r*(w[n]-w[i]);
		int dif=n-2*i;
		if(dif<0)
		{
			dif=-dif;
			dif--;
			ans+=dif*Ql;
		}
		else if(dif>0)
		{
			dif--;
			ans+=dif*Qr;
		}
		sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}