#include <cstdio>

int ans=1;
int maxn=0;

int n,m;
int a[1000100];
int freq[1000100];
int divs[1000100];

int main()
{
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%i",a+i);
		if(a[i]<=m)
		{
			freq[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!freq[i]) continue;
		for(int j=i;j<=m;j+=i)
			divs[j]+=freq[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(divs[i]>maxn)
		{
			ans=i;
			maxn=divs[i];
		}
	}
	printf("%i %i\n",ans,maxn);
	bool count=false;
	for(int i=1;i<=n;i++)
	{
		if(ans%a[i]==0)
		{
			if(count)
				printf(" ");
			printf("%i",i);
			count=true;
		}
	}
	printf("\n");
		
}