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
int qz[1000005],a[1000005];
signed main()
{
	int t,n,c,tsl;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		flag=false;
		n=read();
		c=read();
		for(int i=1;i<=c;i++)qz[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			qz[a[i]]++;
		}
		for(int i=2;i<=c;i++)qz[i]+=qz[i-1];
		if(qz[1]==0)
		{
			printf("No\n");
			continue;
		} 
		flag=true;
		tsl=0;
		for(int i=1;i<=c;i++)
		{
			if(qz[i]-qz[i-1]==0)continue;
			for(int j=1;j<=min(c,c/i+2);j++)
			{
				if(qz[j]-qz[j-1]==0)continue;
				tsl+=(qz[min(i*j+j-1,c)]-qz[min(i*j-1,c)])*(qz[j]-qz[j-1]);
				//printf("orz%lld %lld %lld\n",i,j,(qz[min(i*j+j-1,c)]-qz[min(i*j-1,c)])*(qz[j]-qz[j-1]));
			}
			tsl-=(qz[i]-qz[i-1])*(qz[i]-qz[i-1]-1)/2;
		}
		//printf("%lld\n",tsl);
		if(tsl==n*(n+1)/2)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}