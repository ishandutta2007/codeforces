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
int minn[300001],cx[300001],fl[300001];
signed main()
{
	int n,ans=1,x,sl;
	n=read();
	for(int i=1;i<=200000;i++)minn[i]=1000000000,cx[i]=0;
	for(int i=1;i<=n;i++)
	{
		x=read();
	    for(int j=2;j*j<=x;j++)
	    {
	    	if(x%j!=0)continue;
	    	sl=0;
	    	while(x%j==0)x/=j,sl++;
	    	fl[j]++;
	    	if(sl<minn[j])cx[j]=minn[j],minn[j]=sl;
	    	else if(sl<cx[j])cx[j]=sl;
		}
		if(x>1)
		{
			fl[x]++;
			if(1<minn[x])cx[x]=minn[x],minn[x]=1;
	    	else if(1<cx[x])cx[x]=1;
		}
	}
	for(int i=2;i<=200000;i++)
	{
		//if(cx[i]==0||cx[i]==1000000000)continue;
		if(fl[i]<=n-2)continue;
		if(fl[i]==n-1)for(int j=1;j<=minn[i];j++)ans*=i;
		else for(int j=1;j<=cx[i];j++)ans*=i;
	}
	printf("%lld\n",ans);
	return 0;
}