#include<bits/stdc++.h>
using namespace std;
inline bool check(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
			return true;
	}
	return false;
}
const int max_n=100+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int sum=0,cnt_odd=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			sum+=a[i];
			cnt_odd+=a[i]&1;
		}
		if(cnt_odd&1)
		{
			if(check(sum))
			{
				printf("%d\n",n);
				for(int i=1;i<=n;++i)
					printf("%d%c",i,i<n?' ':'\n');
			}
			else
			{
				printf("%d\n",n-1);
				bool flag=true;
				for(int i=1;i<=n;++i)
				{
					if(a[i]%2==1&&flag)
						flag=false;
					else
						printf("%d ",i);
				}
				puts("");
			}
		}
		else
		{
			printf("%d\n",n);
			for(int i=1;i<=n;++i)
				printf("%d%c",i,i<n?' ':'\n');
		}
	}
	return 0;
}