//Chapter IV: The Spear And The Serpent
#include<iostream>
#include<cstdio>
#define mod 1000000007
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
int a[400005],cf[400005];
int sl[50];
signed main()
{
	int n,ans=1;
	n=read();
	cf[0]=1;
	for(int i=1;i<=n;i++)a[i]=read(),cf[i]=2LL*cf[i-1]%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(a[i]%(1LL<<j)==0)
			{
				sl[j]++;
				break;
			}
		}
	}
	int bk=0,cj=1;
	for(int i=30;i>=1;i--)
	{
		//if(sl[i]>=1)
		{
			bk=(bk+1LL*cj*cf[sl[i]-1]%mod)%mod;
			cj=1LL*cj*(cf[sl[i]])%mod;
			//printf("%lld %lld %lld\n",sl[i],cj,bk);
		}
	}
	printf("%lld\n",(cf[n]+mod-bk-1)%mod);
	return 0;
}