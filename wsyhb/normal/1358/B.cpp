#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int cnt[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		sort(a+1,a+n+1);
		int ans=n+1;
		for(int i=n;i>=1;i--,ans--)
			if(a[i]<=i) break;
		printf("%d\n",ans);
	}
	return 0;
}