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
char s[201][201];
int a[201][201];
int sc[100001][6];
int main()
{
	int t,n,m,sl=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		sl=0;
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=s[i][j]-'0';
		for(int i=1;i<=n-1;i++)for(int j=1;j<=m-1;j++){if((a[i][j]+a[i][j+1]+a[i+1][j])%2==1)
		{
			sc[++sl][0]=i;
			sc[sl][1]=j;
			sc[sl][2]=i;
			sc[sl][3]=j+1;
			sc[sl][4]=i+1;
			sc[sl][5]=j;
			a[i][j]=1-a[i][j];
			a[i][j+1]=1-a[i][j+1];
			a[i+1][j]=1-a[i+1][j];
		}
		if((a[i][j]+a[i+1][j+1]+a[i+1][j])%2==1)
		{
			sc[++sl][0]=i;
			sc[sl][1]=j;
			sc[sl][2]=i+1;
			sc[sl][3]=j+1;
			sc[sl][4]=i+1;
			sc[sl][5]=j;
			a[i][j]=1-a[i][j];
			a[i+1][j]=1-a[i+1][j];
			a[i+1][j+1]=1-a[i+1][j+1];
		}
		if((a[i][j]+a[i][j+1]+a[i+1][j+1])%2==1)
		{
			sc[++sl][0]=i;
			sc[sl][1]=j;
			sc[sl][2]=i;
			sc[sl][3]=j+1;
			sc[sl][4]=i+1;
			sc[sl][5]=j+1;
			a[i][j]=1-a[i][j];
			a[i][j+1]=1-a[i][j+1];
			a[i+1][j+1]=1-a[i+1][j+1];
		}
		if((a[i+1][j+1]+a[i][j+1]+a[i+1][j])%2==1)
		{
			sc[++sl][0]=i+1;
			sc[sl][1]=j+1;
			sc[sl][2]=i;
			sc[sl][3]=j+1;
			sc[sl][4]=i+1;
			sc[sl][5]=j;
			a[i+1][j+1]=1-a[i+1][j+1];
			a[i][j+1]=1-a[i][j+1];
			a[i+1][j]=1-a[i+1][j];
		}}
		printf("%d\n",sl);
		for(int i=1;i<=sl;i++)printf("%d %d %d %d %d %d\n",sc[i][0],sc[i][1],sc[i][2],sc[i][3],sc[i][4],sc[i][5]);
	}
	return 0;
}