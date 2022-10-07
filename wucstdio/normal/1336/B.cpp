#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n1,n2,n3;
ll a[200005],b[200005],c[200005],ans;
ll calc(int i,int j,int k)
{
//	printf("%d %d %d\n",i,j,k);
	ll res=(a[i]-b[j])*(a[i]-b[j])+(b[j]-c[k])*(b[j]-c[k])+(c[k]-a[i])*(c[k]-a[i]);
	ans=min(ans,res);
	return res;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n1,&n2,&n3);
		for(int i=1;i<=n1;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n2;i++)scanf("%lld",&b[i]);
		for(int i=1;i<=n3;i++)scanf("%lld",&c[i]);
		sort(a+1,a+n1+1);
		sort(b+1,b+n2+1);
		sort(c+1,c+n3+1);
		ans=9e18;
		int x=1,y=1;
		for(int i=1;i<=n1;i++)
		{
			while(x<n2&&b[x+1]<=a[i])x++;
			while(y<n3&&c[y]<a[i])y++;
			ans=min(ans,calc(i,x,y));
		}
		x=1,y=1;
		for(int i=1;i<=n2;i++)
		{
			while(x<n1&&a[x+1]<=b[i])x++;
			while(y<n3&&c[y]<b[i])y++;
			ans=min(ans,calc(x,i,y));
		}
		x=1,y=1;
		for(int i=1;i<=n3;i++)
		{
			while(x<n1&&a[x+1]<=c[i])x++;
			while(y<n2&&b[y]<c[i])y++;
			ans=min(ans,calc(x,y,i));
		}
		
		x=1,y=1;
		for(int i=1;i<=n1;i++)
		{
			while(x<n3&&c[x+1]<=a[i])x++;
			while(y<n2&&b[y]<a[i])y++;
			ans=min(ans,calc(i,y,x));
		}
		x=1,y=1;
		for(int i=1;i<=n2;i++)
		{
			while(x<n3&&c[x+1]<=b[i])x++;
			while(y<n1&&a[y]<b[i])y++;
			ans=min(ans,calc(y,i,x));
		}
		x=1,y=1;
		for(int i=1;i<=n3;i++)
		{
			while(x<n2&&b[x+1]<=c[i])x++;
			while(y<n1&&a[y]<c[i])y++;
			ans=min(ans,calc(y,x,i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}