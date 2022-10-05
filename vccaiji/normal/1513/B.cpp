#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int minn=a[1];
		for(int i=1;i<=n;i++)
		 if(minn>a[i]) minn=a[i];
		long long num=0;
		bool r=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==minn) num++;
			if((a[i]&minn)!=minn)
			{
				r=false;
				break;
			}
		}
		if(!r) printf("0");
		else
		{
			long long ans=num*(num-1);
			ans=ans%1000000007;
			for(int i=1;i<=n-2;i++)
			{
				ans*=i;
				ans=ans%(1000000007);
			}
			printf("%d",ans);
		}
		if(i<t) printf("\n");
	}
	return 0;
}