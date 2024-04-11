#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[300005],b[300005],st[300005],top;
long long ans,tot;
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	top=0;
	int i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(b[i]<=b[j])st[++top]=b[i++],tot+=j-mid-1;
		else st[++top]=b[j++];
	}
	while(i<=mid)st[++top]=b[i++],tot+=j-mid-1;
	while(j<=r)st[++top]=b[j++];
	for(int i=1;i<=top;i++)b[i+l-1]=st[i];
}
long long solve()
{
	tot=0;
	solve(1,n);
	return tot;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	ans=solve();
	int val=0;
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=n;j++)b[j]=a[j]^(1<<i);
		long long v=solve();
		if(v<ans)
		{
			ans=v;
			val^=1<<i;
			for(int j=1;j<=n;j++)a[j]^=1<<i;
		}
	}
	printf("%lld %d\n",ans,val);
	return 0;
}