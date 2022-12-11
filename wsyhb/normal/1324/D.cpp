#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=2e5+5;
int a[N],b[N],s[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	for(int i=1;i<=n;i++) s[i]=a[i]-b[i];
	sort(s+1,s+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=upper_bound(s+1,s+n+1,-s[i])-s;
		x=min(x,i);
		ans+=i-x;
	}
	printf("%lld",ans);
	return 0;
}