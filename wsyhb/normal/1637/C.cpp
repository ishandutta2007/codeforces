#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		if(n==3)
			printf("%d\n",a[2]%2?-1:a[2]/2);
		else
		{
			int cnt_odd=0;
			long long sum=0;
			for(int i=2;i<=n-1;++i)
			{
				cnt_odd+=a[i]&1;
				sum+=a[i];
			}
			if(!cnt_odd)
				printf("%lld\n",sum/2);
			else 
			{
				bool flag=false;
				for(int i=2;i<=n-1;++i)
					flag|=a[i]>=2;
				if(!flag)
					puts("-1");
				else if(cnt_odd>1)
					printf("%lld\n",(sum+cnt_odd)/2);
				else
				{
					int pos=-1;
					for(int i=2;i<=n-1;++i)
					{
						if(a[i]&1)
						{
							pos=i;
							break;
						}
					}
					assert(pos!=-1);
					bool flag=false;
					for(int i=2;i<=n-1;++i)
						flag|=i!=pos&&a[i]>=2;
					if(flag)
						printf("%lld\n",(sum+1)/2);
					else
						printf("%lld\n",(sum+3)/2);
				}
			}
		}
	}
	return 0;
}