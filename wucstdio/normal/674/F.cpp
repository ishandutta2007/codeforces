#include<cstdio>
#include<algorithm>
#define int unsigned
using namespace std;
int n,p,q,c[135],tmp[135],ans;
signed main()
{
	scanf("%u%u%u",&n,&p,&q);
	p=min(p,n-1);
	for(int i=1;i<=p;i++)
	{
		tmp[i]=n-i+1;
		int v=i;
		c[i]=1;
		for(int j=1;j<=i;j++)
		{
			int d=__gcd(v,tmp[j]);
			v/=d,tmp[j]/=d;
			c[i]*=tmp[j];
		}
	}
	for(int d=1;d<=q;d++)
	{
		int f=1,pw=1;
		for(int i=1;i<=p;i++)
		{
			pw*=d;
			f+=pw*c[i];
		}
		ans^=d*f;
	}
	printf("%u\n",ans);
	return 0;
}