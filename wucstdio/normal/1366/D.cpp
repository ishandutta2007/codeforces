#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int prime[10005],num,aa[500005],bb[500005];
bool flag[10005];
void pre(int n)
{
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])prime[++num]=i;
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	pre(10000);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int x;
		scanf("%d",&x);
		int a=1,b=1;
		for(int i=1;i<=num&&prime[i]*prime[i]<=x;i++)
		{
			if(x%prime[i])continue;
			if(a==1)
			{
				while(x%prime[i]==0)
				{
					x/=prime[i];
					a*=prime[i];
				}
			}
			else
			{
				while(x%prime[i]==0)
				{
					x/=prime[i];
					b*=prime[i];
				}
			}
		}
		if(x)
		{
			if(a==1)a*=x;
			else b*=x;
		}
		if(a==1||b==1)aa[i]=bb[i]=-1;
		else aa[i]=a,bb[i]=b;
	}
	for(int i=1;i<=t;i++)printf("%d ",aa[i]);
	printf("\n");
	for(int i=1;i<=t;i++)printf("%d ",bb[i]);
	printf("\n");
	return 0;
}