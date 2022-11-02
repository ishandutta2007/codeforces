#include<bits/stdc++.h>
using namespace std;
long long n,cnt[2];
long long a[200009];
int main()
{
	scanf("%lld",&n);
	int u;
	a[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&u);
		a[i]=a[i-1]+(u<0?1:0);
	}
	cnt[0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=cnt[a[i]&1];
		++cnt[a[i]&1];
	}
	printf("%lld %lld\n",n*(n+1)/2-ans,ans);
	return 0;
}