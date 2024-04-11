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
signed main()
{
	int t,x,y,r,ans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		x=read();
		y=read();
		ans=0;
		for(int l=2;l<=min(x,y+1);l=r+1)
		{
			r=min(x/(x/l),y+1);
			if(x/l>=r-2)ans=ans+(l+r-4)*(r-l+1)/2;
			else if(x/l<=l-2)ans=ans+(x/l)*(r-l+1);
			else
			{
				ans=ans+(l-2+x/l)*(x/l-l+3)/2+(x/l)*(r-x/l-1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}