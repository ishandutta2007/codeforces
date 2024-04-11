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
int jc[500001],mod;
signed main()
{
    int n,ans=0;
    n=read();
    mod=read();
    jc[0]=1;
    for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
	for(int x=1;x<=n;x++)ans=(ans+(n-x+1)*(n-x+1)%mod*jc[x]%mod*jc[n-x]%mod)%mod;
	printf("%lld\n",ans); 
    return 0;
}