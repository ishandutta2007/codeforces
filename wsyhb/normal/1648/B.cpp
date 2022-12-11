#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
int a[max_n];
const int max_c=1e6+5;
int cnt[max_c],sum[max_c];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c;
		scanf("%d%d",&n,&c);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			++cnt[a[i]];
		}
		for(int i=1;i<=c;++i)
			sum[i]=sum[i-1]+cnt[i];
		bool ans=true;
		for(int i=1;i<=c;++i)
		{
			if(!cnt[i])
				continue;
			for(int j=1;j<=c/i;++j)
			{
				int L=j*i,R=min(L+i-1,c);
				if(sum[R]>sum[L-1]&&!cnt[j])
				{
					ans=false;
					break;
				}
			}
			if(!ans)
				break;
		}
		puts(ans?"Yes":"No");
		for(int i=1;i<=c;++i)
			cnt[i]=sum[i]=0;
	}
	return 0;
}