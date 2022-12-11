#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int T,n;
int a[maxn],cnt[15],num;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%1d",&a[i]);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			memset(cnt,0,sizeof(cnt));
			num=0;
			for(int j=i;j<=min(n,i+100);++j)
			{
				++cnt[a[j]];
				if(cnt[a[j]]==1)++num;
				int ok=1;
				for(int k=0;k<=9;++k)if(cnt[k]>num)ok=0;
				if(ok)++ans;
			}
		}
		printf("%d\n",ans);
	}
}