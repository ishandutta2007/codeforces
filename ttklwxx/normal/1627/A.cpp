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
char s[105][105];
int main()
{
	int t,n,m,r,c,sl=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		r=read();
		c=read();
		flag=false;
		sl=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='B')sl++;
				if(s[i][j]=='B'&&(i==r||j==c))flag=true;
			}
		}
		if(sl==0)printf("-1\n");
		else if(s[r][c]=='B')printf("0\n");
		else if(flag==true)printf("1\n");
		else printf("2\n");
	}
	return 0;
}