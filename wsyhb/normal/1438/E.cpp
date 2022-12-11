#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int ans=0;
	for(int l=1;l<=n;++l)
	{
		int k=0,t=a[l];
		while(t>1)
			++k,t>>=1;
		int sum=0;
		for(int r=l+2;r<=n;++r)
		{
			sum+=a[r-1];
			if(sum>=(1<<(k+1)))
				break;
			ans+=(a[l]>=a[r]&&sum==(a[l]^a[r]));
		}
	}
	reverse(a+1,a+n+1);
	for(int l=1;l<=n;++l)
	{
		int k=0,t=a[l];
		while(t>1)
			++k,t>>=1;
		int sum=0;
		for(int r=l+2;r<=n;++r)
		{
			sum+=a[r-1];
			if(sum>=(1<<(k+1)))
				break;
			ans+=(a[l]>a[r]&&sum==(a[l]^a[r]));
		}
	}
	printf("%d\n",ans);
	return 0;
}