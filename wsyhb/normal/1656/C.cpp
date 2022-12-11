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
		int cnt1=0,cnt0=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			cnt1+=a[i]==1;
			cnt0+=a[i]==0;
			cnt2+=a[i]==2;
		}
		if(!cnt1)
		{
			puts("YES");
			continue;
		}
		if(cnt0||cnt2)
		{
			puts("NO");
			continue;
		}
		sort(a+1,a+n+1);
		bool ans=true;
		for(int i=1;i<=n-1;++i)
		{
			if(a[i]+1==a[i+1])
			{
				ans=false;
				break;
			}
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}