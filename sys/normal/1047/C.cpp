#include <bits/stdc++.h>
using namespace std;
int cnt,ct,n,a[300005],A[300005],GCD,CNT,prime[1000005],now,ans=0x3f3f3f3f,fac[3000005],CC;
bool not_prim[15000005];
set <int> Se;
int gcd(int x,int y){return x==0?y:gcd(y%x,x);}
void prim(void)
{
	for(int i=2;i<=15000000;i++)
	{
		if(!not_prim[i]) prime[++cnt]=i;
		for(int j=1;prime[j]*i<=15000000;j++){not_prim[prime[j]*i]=true;if(i%prime[j]==0) break;}
	}
}
int main()
{
	scanf("%d",&n);
	prim();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		GCD=gcd(GCD,a[i]);
	}
	for(int i=1;i<=n;i++)
		a[i]/=GCD;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) A[i]=a[i];
	for(int i=1;i<=n;i++)
	{
		int SQRT=ceil(sqrt(A[i]));
		for(int j=1;prime[j]<=SQRT;j++)
		{
			if(A[i]%prime[j]==0) fac[++CNT]=prime[j]; 
			while(A[i]%prime[j]==0) A[i]/=prime[j];
			if(!not_prim[A[i]]||A[i]==1) break;
		}
		if(A[i]!=1)
			fac[++CNT]=A[i];
	}
	now=1;
	sort(fac+1,fac+1+CNT);
	int res=1;
	for(int i=2;i<=CNT;i++)
		if(fac[i]!=fac[i-1]){ans=min(ans,n-res);res=1;}
		else res++;
	ans=min(ans,n-res);
	if(!CNT) ans=-1;
	printf("%d",ans);
	return 0;
}