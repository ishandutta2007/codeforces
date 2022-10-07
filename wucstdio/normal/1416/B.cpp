#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,x[100005],y[100005],v[100005],tot,sa[10005];
ll a[10005],sum;
bool flag[10005];
bool cmp(int x,int y)
{
	return flag[x]<flag[y]||(flag[x]==flag[y]&&x-a[x]<y-a[y]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			flag[i]=0;
		}
		if(sum%n)
		{
			printf("-1\n");
			continue;
		}
		ll ave=sum/n;
		tot=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]>=i)
			{
				tot++;
				x[tot]=i;
				y[tot]=i+1;
				v[tot]=a[i]/i;
				a[i+1]+=a[i]/i*i;
				a[i]%=i;
			}
		}
		if(a[n]>=n)
		{
			tot++;
			x[tot]=n;
			y[tot]=1;
			v[tot]=a[n]/n;
			a[1]+=a[n]/n*n;
			a[n]%=n;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]>ave)
			{
				tot++;
				x[tot]=1;
				y[tot]=i;
				v[tot]=ave+i-a[i];
				a[1]-=v[tot];
				a[i]+=v[tot];
				tot++;
				x[tot]=i;
				y[tot]=1;
				v[tot]=1;
				a[1]+=i;
				a[i]-=i;
			}
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]<ave)
			{
				tot++;
				x[tot]=1;
				y[tot]=i;
				v[tot]=ave-a[i];
				a[1]-=v[tot];
				a[i]+=v[tot];
			}
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++)printf("%d %d %d\n",x[i],y[i],v[i]);
	}
	return 0;
}