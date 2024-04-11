// Bonus of Official Editorial (modified from Solution 2)
#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int p[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int x=1;x<=n-1;++x)
	{
		printf("? ");
		for(int i=1;i<=n-1;++i)
			printf("%d ",x+1);
		puts("1");
		fflush(stdout);
		int k;
		scanf("%d",&k);
		if(k)
		{
			++cnt;
			p[k]=-x;
		}
		else
			break;
	}
	for(int x=1;x<=n-1-cnt;++x)
	{
		printf("? ");
		for(int i=1;i<=n-1;++i)
			printf("1 ");
		printf("%d\n",x+1);
		fflush(stdout);
		int k;
		scanf("%d",&k);
		assert(k);
		p[k]=x;
	}
	printf("! ");
	for(int i=1;i<=n;++i)
	{
		p[i]+=cnt+1;
		printf("%d%c",p[i],i<n?' ':'\n');
	}
	fflush(stdout);
	return 0;
}