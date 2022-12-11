#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n];
const int max_a=1e5+5;
int cnt[max_a][2];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			++cnt[a[i]][i&1];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			--cnt[a[i]][i&1];
		bool ans=true;
		for(int i=1;i<=1e5;++i)
		{
			if(cnt[i][0]||cnt[i][1])
			{
				ans=false;
				break;
			}
		}
		puts(ans?"YES":"NO");
		for(int i=1;i<=1e5;++i)
			cnt[i][0]=cnt[i][1]=0;
	}
	return 0;
}