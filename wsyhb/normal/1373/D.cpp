#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N],b[N];
ll f[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",a+i);
		long long sum=0;
		for(int i=0;i<n;i++)
			if(i%2==0) sum+=a[i];
		int m=n>>1;
		long long ans=0;
		for(int i=0;i<m;i++)
		{
			b[i+1]=a[i<<1|1]-a[i<<1];
			f[i+1]=max(b[i+1],b[i+1]+f[i]);
			ans=max(ans,f[i+1]);
		}
		for(int i=1;i<=m;i++)
		{
			if(i*2>=n) break;
			b[i]=a[(i<<1)-1]-a[i<<1];
			f[i]=max(b[i],b[i]+f[i-1]);
			ans=max(ans,f[i]);
		}
		printf("%lld\n",sum+ans);
	}
	return 0;
}