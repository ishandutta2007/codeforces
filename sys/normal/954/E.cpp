#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
struct wat
{
	long long a,t;
	bool operator < (const wat &tmp) const
	{
		return t<tmp.t;
	}
}W[Maxn];
int n;
long long T,val,sum;
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
		scanf("%lld",&W[i].a);
	for(int i=1;i<=n;i++)
		scanf("%lld",&W[i].t),val+=W[i].a*W[i].t,sum+=W[i].a;
	if(val/(double)sum==T){printf("%lld",sum);return 0;}
	sort(W+1,W+1+n);
	if(val/(double)sum<T)
	{
		long long V=0,S=0;
		int pnt=n+1;
		for(int i=1;i<=n;i++)
			if(W[i].t>=T){pnt=i-1;break;}
		for(int i=n;i>pnt;i--) V+=W[i].a*W[i].t,S+=W[i].a; 
		for(int i=pnt;i>=1;i--)
		{
			if((V+W[i].a*W[i].t)/(double)(S+W[i].a)<T)
			{
				printf("%.10lf",(W[i].t*S-V)/(double)(W[i].t-T));
				return 0;
			}
			V+=W[i].a*W[i].t;
			S+=W[i].a;
		}
	}
	else
	{
		long long V=0,S=0;
		int pnt=n+1;
		for(int i=n;i>=1;i--)
			if(W[i].t<=T){pnt=i+1;break;}
		for(int i=1;i<pnt;i++) V+=W[i].a*W[i].t,S+=W[i].a;
		for(int i=pnt;i<=n;i++)
		{
			if((V+W[i].a*W[i].t)/(double)(S+W[i].a)>T)
			{
				printf("%.10lf",(W[i].t*S-V)/(double)(W[i].t-T));
				return 0;
			}
			V+=W[i].a*W[i].t;
			S+=W[i].a;
		}
	}
	printf("0");
	return 0;
}