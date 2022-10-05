#include <bits/stdc++.h>
using namespace std;
int ans,n,a[300005],b[300005],m,cnt1,cnt2;
long long sum1,sum2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum1+=a[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		sum2+=b[i];
	}
	if(sum1!=sum2){printf("-1\n");return 0;}
	cnt1=cnt2=1;
	sum1=0,sum2=0;
	ans=-1;
	while(cnt1!=n+1||cnt2!=m+1)
	{
		if(sum1==sum2)
		{
			ans++;
			if(cnt1!=n) sum1+=a[cnt1++];
			else sum2+=b[cnt2++];
			continue;
		}
		if(sum1<sum2)
		{
			sum1+=a[cnt1++];
		}
		else if(sum2<sum1)
		{
			sum2+=b[cnt2++];
		}
	}
	printf("%d",ans+1);
	return 0;
}