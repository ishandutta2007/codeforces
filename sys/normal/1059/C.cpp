#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000005;
bool not_prim[Maxn];
int QAQ,PP,ans[Maxn],CNT[Maxn],CNTTT,n,maxi,pnt,facs[Maxn],ct,prime[Maxn],cnt,fac[Maxn];
void init(void)
{
	for(int i=2;i<=n;i++)
	{
		if(!not_prim[i])
		{
			fac[i]=2;
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&prime[j]*i<=n;j++)
		{
			fac[i*prime[j]]=fac[i]+1;
			not_prim[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	 scanf("%d",&n);
	 init();
	 for(int i=1;i<=n;i++)
	 	if(fac[i]>=maxi)
	 	{
	 		maxi=fac[i];
	 		pnt=i;
	 	}
	int sum=1,lt=pnt,now=ceil(sqrt(pnt));
	prime[0]=1;	
	for(int i=1;i<=n;i++)
		ans[i]=1;
	for(int i=1;i<=cnt;i++)
	{
		while(pnt%prime[i]==0)
		{
			sum*=prime[i];
			if(sum>n)
			{
				PP=i;
				break;
			}
			for(int j=1;j<=floor(n/(double)sum);j++)
				ans[j]*=prime[i];
			pnt/=prime[i];
		}
	}
	reverse(ans+1,ans+1+n);
	for(int i=1;i<=n;i++) 
		printf("%d ",ans[i]);
	return 0;
}