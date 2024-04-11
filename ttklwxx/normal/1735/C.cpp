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
char s[100005];
int p[26];
bool vis[26];
int sl;
int fa[26];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
bool check(int x,int y)
{
	if(vis[y])return false;
	if(x==y)return false;
	if(findf(x)==findf(y)&&sl!=25)return false;
	vis[y]=true;
	sl++;
	p[x]=y;
	fa[findf(x)]=findf(y);
	return true;
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=0;i<=25;i++)p[i]=-1,vis[i]=false,fa[i]=i;
		sl=0;
		for(int i=1;i<=n;i++)
		{
			if(p[s[i]-'a']!=-1)continue;
			for(int j=0;j<=25;j++)
			{
				if(check(s[i]-'a',j)==true)
				{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%c",'a'+p[s[i]-'a']);
		printf("\n");
	}
	return 0;
}