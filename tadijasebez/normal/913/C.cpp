#include <stdio.h>
#define ll long long
const ll inf=9e18;
const int L=30;
ll min(ll a, ll b, ll c)
{
	if(inf/b<c) return a;
	b*=c;
	return a>b?b:a;
}
ll min(ll a, ll b){ return a>b?b:a;}
ll a[35];
bool good[35];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=0;i<=L;i++) a[i]=inf;
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	for(i=0;i<=L;i++)
	{
		for(j=i+1;j<=L;j++)
		{
			a[j]=min(a[j],a[i],(1<<(j-i)));
		}
	}
	ll Min=inf;
	for(i=30;~i;i--)
	{
		if(a[i]<Min)
		{
			good[i]=1;
			Min=a[i];
		}
	}
	ll sum=0;
	int taj=0;
	bool was=0;
	for(i=0;i<=L;i++)
	{
		sum=min(sum,a[i]);
		if((m>>i)&1) sum+=a[i];
		/*if(was && (m>>i)&1)
		{
			//was=1;
			//sum+=a[i],taj=i;
			//if(good[i])
			//{
				sum+=a[i];
			//	was=0;
			//}
		}
		else if(!was && (m>>i)&1)
		{

		}
		else
		{
			//if(was && good[i])
			//{
				sum=min(sum,a[i]);
			//}
			//else if(!was && good[i])
			//{
			//	sum=min(sum,a[i]);
			//}
		}*/
	}
	//for(i=taj+1;i<L;i++) sum=min(sum,a[i]);
	printf("%lld\n",sum);
	return 0;
}