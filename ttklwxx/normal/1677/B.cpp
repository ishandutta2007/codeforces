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
char s[1000005];
int ll[1000005];
int hans[1000005];
int qzh[1000005];
signed main()
{
	int t,n,m,lans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		scanf("%s",s+1);
		qzh[0]=0;
		for(int i=1;i<=n*m;i++)
		{
			if(s[i]=='1')qzh[i]=qzh[i-1]+1;
			else qzh[i]=qzh[i-1];
			hans[i]=0;
		}
		for(int i=0;i<m;i++)ll[i]=0;
		lans=0;
		for(int i=1;i<=n*m;i++)
		{
			if(ll[i%m]==0&&s[i]=='1')
			{
				ll[i%m]=1;
				lans++;
			}
			if(i<=m)
			{
				if(qzh[i]>0)hans[i]=1;
				else hans[i]=0;
			}
			else
			{
				if(qzh[i]-qzh[i-m]>0)hans[i]=hans[i-m]+1;
				else hans[i]=hans[i-m];
			}
			printf("%lld ",hans[i]+lans);
		}
		printf("\n");
	}
	return 0;
}