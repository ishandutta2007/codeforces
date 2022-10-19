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
char s[505];
int b[505][505],a[505][505];
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='W')b[i][j]=0;
			else b[i][j]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=(b[i][j]^b[i][j+1]^b[i+1][j]^b[i+1][j+1]);
			//printf("%d %d %d\n",i,j,a[i][j]);
			if(a[i][j]==1)ans++;
		}
	}
	bool flag=true;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(a[n][m]==1&&a[i][j]==1&&a[i][m]==1&&a[n][j]==1)
			{
				ans--;
				flag=false;
				break; 
			}
		}
		if(flag==false)break;
	}
	printf("%d\n",ans);
	return 0;
}