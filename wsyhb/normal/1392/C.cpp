#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		long long ans=0;
		for(int i=1;i<n;i++)
			if(a[i]>a[i+1]) ans+=a[i]-a[i+1];
		printf("%lld\n",ans);
	}
	return 0;
}