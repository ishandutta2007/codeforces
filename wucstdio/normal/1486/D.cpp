#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,a[200005],b[200005],c[400005];
void add(int p,int v)
{
	while(p<=400002)
	{
		c[p]+=v;
		p+=p^(p&(p-1));
	}
}
int sum(int p)
{
	int ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
bool check(int v)
{
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
	{
		if(a[i]<v)b[i]=-1;
		else b[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
		if(i>=k)add(b[i-k]+200001,1);
		if(sum(b[i]+200001-1))return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}