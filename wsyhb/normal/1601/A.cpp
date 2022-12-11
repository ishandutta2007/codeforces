#include<bits/stdc++.h>
using namespace std;
int cnt[35];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<30;++i)
			cnt[i]=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			for(int j=0;j<30;++j)
			{
				if((a>>j)&1)
					++cnt[j];
			}
		}
		int ans=0;
		for(int i=0;i<30;++i)
		{
			if(ans)
				ans=gcd(ans,cnt[i]);
			else
				ans=cnt[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(ans%i==0)
				printf("%d ",i);
		}
		putchar('\n');
	}
	return 0;
}