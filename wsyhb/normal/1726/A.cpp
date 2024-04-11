#include<bits/stdc++.h>
using namespace std;
const int max_n=2e3+5;
int a[max_n<<1]; 
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
			a[i+n]=a[i];
		}
		int ans=a[n]-a[1];
		for(int i=n;i<=2*n;++i)
			ans=max(ans,a[i]-a[i-n+1]);
		for(int i=2;i<=n;++i)
			ans=max(ans,a[i]-a[1]);
		for(int i=1;i<=n-1;++i)
			ans=max(ans,a[n]-a[i]);
		printf("%d\n",ans);
	}
	return 0;
}