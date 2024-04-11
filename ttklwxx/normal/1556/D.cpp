#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[100005],yu[100005],hu[100005];
signed main()
{
	int n,k;
	n=read();
	k=read();
	for(int i=2;i<=n;i++)
	{
		printf("or %lld %lld\n",1LL,i);
		fflush(stdout);
		hu[i]=read();
		printf("and %lld %lld\n",1LL,i);
		fflush(stdout);
		yu[i]=read();
		a[i]=hu[i]-yu[i];
	}
	int hyu,hhu;
	printf("or %lld %lld\n",2LL,3LL);
	fflush(stdout);
	hhu=read();
	printf("and %lld %lld\n",2LL,3LL);
	fflush(stdout);
	hyu=read();
	bool flag;
	for(int i=0;i<=30;i++)
	{
		flag=false;
		for(int j=2;j<=n;j++)
		{
			if((hu[j]&(1<<i))==0)
			{
				flag=true;
				break;
			}
			if((yu[j]&(1<<i))!=0)
			{
				a[1]|=(1<<i);
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			if((hhu&(1<<i))==0)a[1]|=(1<<i);
		}
	}
	for(int i=2;i<=n;i++)a[i]^=a[1];
	sort(a+1,a+n+1);
	printf("finish %lld\n",a[k]);
	fflush(stdout);
	return 0;
}