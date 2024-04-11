#include <bits/stdc++.h>
using namespace std;
long long ans,a[200005],n,num;
int sta,ed;
int main()
{
	scanf("%lld%lld",&n,&num);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(a[n/2+1]==num){printf("0");return 0;} 
	if(n==1){printf("%d\n",abs(num-a[1]));return 0;}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=num&&!sta) sta=i;
		if(sta&&a[i]!=num&&!ed) ed=i;
	}
	if(!sta) ed=sta=n+1;
	if(!ed) ed=n+1;
	if(sta<=n/2+1)
	{
		for(int i=ed;i<=n/2+1;i++)
			ans+=a[i]-num;
		printf("%lld",ans);
	}
	else
	{
		for(int i=sta-1;i>=n/2+1;i--)
			ans+=-a[i]+num;
		printf("%lld",ans);
	}
	return 0;
}