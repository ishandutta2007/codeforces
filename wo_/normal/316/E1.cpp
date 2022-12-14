#include<cstdio>

using namespace std;

const long long mod=1000000000;

long long F[200200];
int a[200200];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	F[0]=1;F[1]=1;
	for(int i=2;i<200200;i++)
	{
		F[i]=F[i-1]+F[i-2];
		F[i]%=mod;
	}
	for(int i=0;i<M;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int x,v;
			scanf("%d%d",&x,&v);
			x--;
			a[x]=v;
		}
		else
		{
			long long ans=0;
			int l,r;
			scanf("%d%d",&l,&r);
			l--;r--;
			for(int i=l;i<=r;i++)
			{
				ans+=F[i-l]*a[i];
				ans%=mod;
			}
			ans+=mod;
			ans%=mod;
			printf("%d\n",(int)ans);
		}
	}
	return 0;
}