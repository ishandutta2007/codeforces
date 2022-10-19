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
int n,x;
int a[100001],b[100001],c[100001];
signed main()
{
    n=read();
    int jiaa=0,ans=1121131433448687LL,mod;
    mod=read();
    for(int i=1;i<=n;i++)
    {
    	x=read();
    	a[i]=x;
    }
    for(int i=1;i<=n;i++)
    {
    	x=read();
    	b[i]=x;
    }
    sort(b+1,b+n+1);
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
    	jiaa=(b[i]-a[1]+mod)%mod;
    	for(int j=1;j<=n;j++)
    	{
    		c[j]=(a[j]+jiaa)%mod;
    	}
    	sort(c+1,c+n+1);
    	flag=false;
    	for(int j=1;j<=n;j++)if(b[j]!=c[j])
    	{
    		flag=true;
    		break;
    	}
    	if(flag==false)ans=min(ans,jiaa);
    }
    printf("%lld\n",ans);
    return 0;
}