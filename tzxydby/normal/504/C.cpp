#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,x,y,fl,a[N],b[N],c[N];
long long ans;
void sol()
{
	y=x;
	for(int i=1;i<=n;i++)
		c[i]=0;
	for(int i=0;i<y;i++)
		c[a[i]]++;
	while(y<=n/2)
	{
		c[a[y]]++;
		if(2*c[a[y]]>b[a[y]])
			break;
		y++;
	}
	if(n%2&&y==n/2&&b[a[y]]%2)
		y++;
	if(y>=(n+1)/2)
		while(a[y]==a[n-y-1])
			y++;
	ans+=1ll*(y+1)*(x+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),b[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(b[i]&1)
		{
			if(fl)
			{
				puts("0");
				return 0;
			}
			fl=1;
		}
	}
	while(x<=n/2&&a[x]==a[n-x-1])
		x++;
	if(x>n/2)
	{
		printf("%lld\n",1ll*n*(n+1)/2);
		return 0;
	}
	ans-=1ll*(x+1)*(x+1);
	sol();
	reverse(a,a+n);
	sol();
	printf("%lld\n",ans);
	return 0;
}