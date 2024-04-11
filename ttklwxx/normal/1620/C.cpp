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
char s[200005];
int ans[200005];
int dx[200005],cnt;
int cj[200005];
signed main()
{
	int t,n,x,k,sl,sth,gre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		x=read()-1;
		scanf("%s",s+1);
		sl=0;
		cnt=0; 
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='*')sl++;
			else
			{
				if(sl!=0)dx[++cnt]=sl;
				sl=0;
			}
		}
		if(sl!=0)dx[++cnt]=sl;
		cj[cnt+1]=1;
		for(int i=1;i<=cnt;i++)cj[i]=0;
		sth=1;
		for(int i=cnt;i>=1;i--)
		{
			if(cj[i+1]>x/(dx[i]*k+1))
			{
				sth=i+1;
				break;
			}
			cj[i]=1LL*cj[i+1]*(dx[i]*k+1);
		}
		gre=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='a')printf("a");
			else
			{
				gre++;
				if(cj[gre+1]>0)
				{
					//printf("%d %d\n",x,cj[gre+1]);
					for(int j=1;j<=x/cj[gre+1];j++)printf("b");
					x%=cj[gre+1];
				}
				while(i<n&&s[i+1]=='*')i++;
			}
		}
		printf("\n");
	}
	return 0;
}