#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[1000005];
int cd[1000005],gg[1000005];
signed main()
{
	int t,n,r,sl;
	int ans=0,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		sl=0;
		cd[n+1]=0;
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='*')cd[i]=cd[i+1]+1,sl++;
			else cd[i]=0;
		}
		if(sl==0)
		{
			printf("0\n");
			continue;
		}
		int qans=0,qsl=0,qr=0,hsl=0,hans=0,hl=0;
		s[0]='.';
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='*'&&s[i-1]=='.')
			{
				r=i+cd[i]-1;
				hans+=hsl*(hl-r-1);
				hsl+=r-i+1;
				hl=i;
				gg[i]=hans;
			}
		}
		ans=1000000000000LL;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='*'&&s[i-1]=='.')
			{
				r=i+cd[i]-1;
				qans+=qsl*(i-qr-1);
				qsl+=r-i+1;
				qr=r;
				ans=min(ans,qans+gg[i]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}