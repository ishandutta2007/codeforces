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
int ch[2000001][3],cnt;
char str[2001][35];
char s[50],len;
void insert()
{
	int sth=0,sl=0; 
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='S')sl=0;
		else if(s[i]=='E')sl=1;
		else sl=2;
		if(ch[sth][sl]==0)ch[sth][sl]=++cnt;
		sth=ch[sth][sl];
	}
}
int query()
{
	int sth=0,sl=0; 
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='S')sl=0;
		else if(s[i]=='E')sl=1;
		else sl=2;
		if(ch[sth][sl]==0)return 0;
		sth=ch[sth][sl];
	}
	return 1;
}
int main()
{
	int n,k,ans=0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str[i]+1);
		for(int j=1;j<=k;j++)s[j]=str[i][j];
		len=k;
		insert();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int x=1;x<=k;x++)
			{
				if(str[i][x]==str[j][x])s[x]=str[i][x];
				else s[x]='S'+'E'+'T'-str[i][x]-str[j][x];
			}
			len=k;
			ans+=query();
		}
	}
	printf("%d\n",ans/6);
	return 0;
}