#include<bits/stdc++.h>
using namespace std;
const int max_n=5e4+5;
int a[max_n],b[max_n],cnt[max_n],val[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long long delta=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			delta+=a[i];
		}
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;++i)
		{
			scanf("%d",b+i);
			delta-=b[i];
		}
		if(delta)
		{
			puts("No");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			int v=a[i];
			while(v%m==0)
				v/=m;
			val[i]=v,cnt[i]=a[i]/v;
		}
		bool ans=true;
		for(int i=1,j=1;i<=k;++i)
		{
			if(b[i]==val[j])
			{
				--cnt[j];
				if(!cnt[j])
					++j;
				continue;
			}
			if(b[i]%val[j]!=0)
			{
				ans=false;
				break;
			}
			int need=b[i]/val[j];
			int t=need;
			while(t%m==0)
				t/=m;
			if(t>1)
			{
				ans=false;
				break;
			}
			int sum=0,now=j;
			while(now<=n&&val[now]==val[j]&&sum<need)
				sum+=cnt[now++];
			if(sum<need)
			{
				ans=false;
				break;
			}
			if(sum==need)
				j=now;
			else
			{
				j=now-1;
				cnt[j]=sum-need;
			}
		}
		puts(ans?"Yes":"No");
	}
	return 0;
}