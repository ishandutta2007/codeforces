#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],c0,c1,v[N],f[N],b,ans,p[N];
char s[N];
void sol()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	c0=c1=ans=0;
	for(int i=1;i<=n;i++)
		p[i]=0;
	for(int i=1;i<=n;i++)
		(a[i]?c1:c0)++;
	if(c0>c1)
	{
		reverse(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			a[i]^=1;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+(a[i]==1);
		if(!a[i])
			a[i]=-1;
		v[i]=v[i-1]+a[i];
	}
	for(int i=n;i>=0;i--)
		if(v[i]>=0)
			p[v[i]]=i;
	int x=n;
	while(x&&f[x]-f[x-1])
		x--;
	int z=x;
	b=v[x];
	while(x)
	{
		if(b<=0)
		{
			ans+=(f[x]>0);
			break;
		}
		int y=p[b];
		ans++;
		int d=f[z]-f[y];
		b-=d;
		x-=d;
		z=y;
	}
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}