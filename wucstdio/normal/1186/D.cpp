#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[100005],b[100005],sa,sb;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double v;
		scanf("%lf",&v);
		if(v>0)a[i]=v*100000+0.5;
		else a[i]=v*100000-0.5;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]/100000*100000;
		sa+=a[i];
		sb+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]%100000==0)continue;
		if(sa<sb&&a[i]<0)
		{
			b[i]-=100000;
			sb-=100000;
		}
		if(sa>sb&&a[i]>0)
		{
			b[i]+=100000;
			sb+=100000;
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",(int)(b[i]/100000));
	return 0;
}