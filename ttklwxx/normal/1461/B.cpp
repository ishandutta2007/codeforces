#include<iostream>
#include<cstdio>
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
char s[1005][1005];
int sl[1005][1005];
int main()
{
	int t,n,m,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
		{
			sl[i][0]=0;
			for(int j=1;j<=m;j++)
			{
				sl[i][j]=sl[i][j-1];
				if(s[i][j]=='*')sl[i][j]++;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=n-i+1;k++)
				{
					if(j<k||j+k-1>m)break;
					if(sl[i+k-1][j+k-1]-sl[i+k-1][j-k]!=2*k-1)break;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}