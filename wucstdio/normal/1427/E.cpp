#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int tot;
ll x,a[100005],b[100005],t[100005];
int calc(ll x)
{
	int ans=1;
	while((1<<ans)<=x)ans++;
	return ans-1;
}
void make(int k,ll x)
{
	ll now=0;
	for(int i=0;i<30;i++)
	{
		if((1<<i)&k)
		{
			if(now==0)now=(1<<i)*x;
			else
			{
				a[++tot]=now;
				b[tot]=(1<<i)*x;
				t[tot]=0;
				now+=(1<<i)*x;
			}
		}
	}
}
int main()
{
	scanf("%lld",&x);
	while(x!=1)
	{
		if(!(x&(x+1)))
		{
			a[++tot]=x;
			b[tot]=x;
			t[tot]=0;
			a[++tot]=2*x;
			b[tot]=x;
			t[tot]=1;
			x=2*x^x;
			continue;
		}
		ll v=x;
		for(int i=1;i<=20;i++)
		{
			a[++tot]=v;
			b[tot]=v;
			t[tot]=0;
			v*=2;
		}
		for(int k=2;k<=x+2;k++)
		{
			if((k*x^(k-1)*x^x)<x&&(k*x^(k-1)*x^x)!=0)
			{
				make(k,x);
				make(k-1,x);
				a[++tot]=k*x;
				b[tot]=(k-1)*x;
				t[tot]=1;
				a[++tot]=k*x^(k-1)*x;
				b[tot]=x;
				t[tot]=1;
				v=(k*x^(k-1)*x^x);
				break;
			}
		}
		while(calc(v)!=calc(x))
		{
			a[++tot]=v;
			b[tot]=v;
			t[tot]=0;
			v*=2;
		}
		a[++tot]=x;
		b[tot]=v;
		t[tot]=1;
		x^=v;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		if(t[i]==0)printf("%lld + %lld\n",a[i],b[i]);
		else printf("%lld ^ %lld\n",a[i],b[i]);
	}
	return 0;
}