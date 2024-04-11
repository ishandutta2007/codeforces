#include<iostream>
#include<cstdio>
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
int ansu[1000005],ansv[1000005],answ[1000005],cnt;
signed main()
{
	int x;
	x=read();
	while(x>1)
	{
		int i=0;
		while((1LL<<i+1)<=x)
		{
			ansu[++cnt]=(x<<i);
			ansv[cnt]=(x<<i);
			answ[cnt]=0;
			i++;
		}
		long long a=(x<<i),b=(a^x);
		ansu[++cnt]=a;
		ansv[cnt]=x;
		answ[cnt]=1;
		for(int j=0;j<i;j++)
		{
			ansu[++cnt]=(x<<j);
			ansv[cnt]=a;
			answ[cnt]=0;
			ansu[++cnt]=(x<<j);
			ansv[cnt]=b;
			answ[cnt]=0;
			a+=(x<<j);
			b+=(x<<j);
		}
		ansu[++cnt]=a;
		ansv[cnt]=b;
		answ[cnt]=1;
		x=(a^b);
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		if(answ[i]==0)printf("%lld + %lld\n",ansu[i],ansv[i]);
		else printf("%lld ^ %lld\n",ansu[i],ansv[i]);
	}
}