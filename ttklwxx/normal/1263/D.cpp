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
char a[300001];
int len;
int fa[300001];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
bool vis[300001],cx[300001];
int main()
{
	int n,x,y;
	n=read();
	for(int i=1;i<=26;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		len=strlen(a+1);
		cx[a[1]-'a'+1]=true;
		for(int j=2;j<=len;j++)
		{
			cx[a[j]-'a'+1]=true; 
			if(a[j]!=a[1])
			{
				x=findf(a[1]-'a'+1);
				y=findf(a[j]-'a'+1);
				if(x!=y)fa[x]=y;
			}
		} 
	}
	int ans=0;
	for(int i=1;i<=26;i++)
	{
		if(!cx[i])continue;
		x=findf(i);
		if(!vis[x])
		{
			vis[x]=true;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0; 
}