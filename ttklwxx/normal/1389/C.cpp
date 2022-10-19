#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[300001];
int nex[300001][10];
int sl[10];
int main()
{
	int t,n,ans=0,x,tans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int j=0;j<=9;j++)sl[j]=0;
		for(int i=0;i<=n+1;i++)for(int j=0;j<=9;j++)nex[i][j]=n+1;
		for(int i=1;i<=n;i++)sl[s[i]-'0']++;
		ans=0;
		for(int i=0;i<=9;i++)ans=max(ans,sl[i]);
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<=9;j++)nex[i][j]=nex[i+1][j];
			nex[i][s[i+1]-'0']=i+1;
		}
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				if(i==j)continue;
				x=0;
				tans=0;
				while(1)
				{
					x=nex[nex[x][i]][j];
					if(x==n+1)break;
					tans++;
				}
				ans=max(ans,2*tans);
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}