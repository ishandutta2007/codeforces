#include <bits/stdc++.h>
using namespace std;
int n,a[505],cnt[505];
long long k;
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int now=1;
	for(int i=2;i<=n;i++)
	{
		if(a[now]<a[i]) now=i;
		cnt[now]++;
		if(cnt[now]>=k){printf("%d",a[now]);return 0;}
	}
	printf("%d",a[now]);
	return 0;
}