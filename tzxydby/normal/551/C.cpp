#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,m,a[N],b[N];
int check(long long t)
{
	long long now=1;
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	for(int i=1;i<=m&&now<=n;i++)
	{
		long long s=t-now;
		while(s>0&&now<=n)
		{
			if(s>=b[now])
			{
				s-=b[now];
				b[now]=0;
				now++;
				s--;
			}
			else
			{
				b[now]-=s;
				s=0;
			}
		}
	}
	if(now>=n+1)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	while(a[n]==0&&n>=1)
		n--;
	long long l=n,r=1e16;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	printf("%I64d\n",r+1);
	return 0;
}