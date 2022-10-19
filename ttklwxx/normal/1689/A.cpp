#include<iostream>
#include<cstdio>
#include<algorithm>
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
char s[1005],t[1005];
int main()
{
	int ttt,n,m,k,x,y,prex,prey;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		m=read();
		k=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		sort(s+1,s+n+1);
		sort(t+1,t+m+1);
		prex=1;
		prey=1;
		x=1;
		y=1;
		for(int i=1;i<=n+m;i++)
		{
			if(x==n+1||y==m+1)break;
			if(x-prex<k&&((x<=n&&s[x]<t[y])||y-prey==k))
			{
				printf("%c",s[x]);
				x++;
				prey=y;
			}
			else
			{
				printf("%c",t[y]);
				y++;
				prex=x;
			}
		} 
		printf("\n");
	}
	return 0;
}