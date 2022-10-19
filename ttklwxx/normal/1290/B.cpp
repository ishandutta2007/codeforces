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
int yl[200005][26];
char str[400005];
int main()
{
	scanf("%s",str+1);
	int n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(str[i]=='a'+j-1)yl[i][j]=yl[i-1][j]+1;
			else yl[i][j]=yl[i-1][j];
		}
	}
	int m,l,r,sl;
	m=read();
	for(int i=1;i<=m;i++)
	{
		l=read();
		r=read();
		if(l==r)
		{
			printf("Yes\n");
			continue;
		}
		if(str[l]!=str[r])
		{
			printf("Yes\n");
			continue;
		}
		sl=0;
		for(int j=1;j<=26;j++)if(yl[r][j]!=yl[l-1][j])sl++;
		if(sl>=3)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}