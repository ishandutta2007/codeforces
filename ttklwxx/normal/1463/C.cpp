#include<iostream>
#include<cstdio>
#include<cmath>
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
int t[200005],x[200005];
signed main()
{
	int ttt,n,zx,ans,pos;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		t[n+1]=1121131433448687LL;
		x[n+1]=0;
		zx=0;
		ans=0;
		pos=0;
		for(int i=1;i<=n;i++)t[i]=read(),x[i]=read();
		t[0]=t[1];
		for(int i=1;i<=n+1;i++)
		{
			if(pos>x[zx])
			{
				if(pos-x[zx]<=t[i]-t[i-1])
				{
					if(x[i-1]<=pos&&x[i-1]>=x[zx])ans++;
					pos=x[zx];
					zx=i;
				}
				else
				{
					if(x[i-1]<=pos&&x[i-1]>=pos-t[i]+t[i-1])ans++;
					pos=pos-t[i]+t[i-1];
				}
			}
			else
			{
				if(x[zx]-pos<=t[i]-t[i-1])
				{
					if(x[i-1]<=x[zx]&&x[i-1]>=pos)ans++;
					pos=x[zx];
					zx=i;
				}
				else
				{
					if(x[i-1]>=pos&&x[i-1]<=pos+t[i]-t[i-1])ans++;
					pos=pos+t[i]-t[i-1];
				}
			}
		}
		printf("%lld\n",ans-1);
	}
	return 0;
}