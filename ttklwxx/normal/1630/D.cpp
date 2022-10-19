#include<iostream>
#include<cstdio>
#include<cstdlib>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int gcd(int m,int n)
{
	if(m==0||n==0)return m+n;
	while(m^=n^=m^=n%=m);
	return n;
}
int a[1000005],b[1000005];
int sl[1000005],minn[1000005];
signed main()
{
	int t,n,k,gc,ans1,ans2,het=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		gc=0;
		for(int i=1;i<=k;i++)
		{
			b[i]=read();
			gc=gcd(gc,b[i]);
		}
		//printf("%lld\n",gc);
		for(int i=0;i<=n;i++)minn[i]=1121131433448687LL,sl[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<0)
			{
				sl[i%gc]++;
				a[i]=-a[i];
			}
			minn[i%gc]=min(minn[i%gc],a[i]); 
		}
		for(int i=0;i<gc;i++)sl[i]%=2;
		ans1=0;
		ans2=0;
		het=0;
		for(int i=1;i<=n;i++)het+=a[i];
		for(int i=0;i<gc;i++)
		{
			if(sl[i]%2==1)ans1+=2*minn[i];
			else ans2+=2*minn[i];
			//printf("%lld\n",minn[i]);
		}
		//printf("%lld %lld\n",ans1,ans2);
		for(int i=0;i<=n;i++)sl[i]=0;
		printf("%lld\n",het-min(ans1,ans2));
	}
}