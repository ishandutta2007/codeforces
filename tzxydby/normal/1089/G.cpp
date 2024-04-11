#include<bits/stdc++.h>
using namespace std;
int a[7];
long long solve(int d,int k)
{
	int sum=0;
	for(int i=0;i<7;i++)
		sum+=a[i];
	long long ans=(k-1)/sum*7;
	int rest=(k-1)%sum+1;
	while(rest)
	{
		ans++;
		if(a[d])
			rest--;
		d=(d+1)%7;
	}
	return ans;
}
int main()
{
	int t,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		for(int i=0;i<7;i++)
			scanf("%d",&a[i]);
		long long ans=LLONG_MAX;
		for(int i=0;i<7;i++)
			ans=min(ans,solve(i,k));
		printf("%d\n",ans);
	}
	return 0;
}