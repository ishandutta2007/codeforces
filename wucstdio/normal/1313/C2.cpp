#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[500005];
int st[500005],num[500005],top;
ll s[500005],pre[500005],suf[500005];
ll ans,pos;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		ll now=1;
		while(top&&a[i]<=st[top])
		{
			now+=num[top];
			top--;
		}
		st[++top]=a[i];
		num[top]=now;
		s[top]=s[top-1]+now*a[i];
		pre[i]=s[top];
	}
	top=0;
	for(int i=n;i>=1;i--)
	{
		ll now=1;
		while(top&&a[i]<=st[top])
		{
			now+=num[top];
			top--;
		}
		st[++top]=a[i];
		num[top]=now;
		s[top]=s[top-1]+now*a[i];
		suf[i]=s[top];
	}
	for(int i=1;i<=n;i++)
	{
		if(ans<pre[i]+suf[i]-a[i])
		{
			ans=pre[i]+suf[i]-a[i];
			pos=i;
		}
	}
	for(int i=pos-1;i>=1;i--)a[i]=min(a[i],a[i+1]);
	for(int i=pos+1;i<=n;i++)a[i]=min(a[i],a[i-1]);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}