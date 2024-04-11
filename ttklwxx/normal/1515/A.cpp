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
int w[200005],pos[200005];
int tans[200005],cnt;
bool cx[200005];
bool bi(int x,int y)
{
	return w[x]<w[y];
}
int main()
{
	int t,n,x,he=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		he=0;
		for(int i=1;i<=n;i++)w[i]=read(),pos[i]=i,cx[i]=false,he+=w[i];
		if(x==he)
		{
			printf("NO\n");
			continue;
		}
		sort(pos+1,pos+n+1,bi);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(w[pos[i]]<x)
			{
				x-=w[pos[i]];
				tans[++cnt]=w[pos[i]];
				cx[pos[i]]=true;
			}
			else if(w[pos[i]]>x)
			{
				x-=w[pos[i]];
				tans[++cnt]=w[pos[i]];
				cx[pos[i]]=true;
				break;
			}
		}
		for(int i=1;i<=n;i++)if(!cx[i])tans[++cnt]=w[i];
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%d ",tans[i]); 
		printf("\n");
	} 
	return 0;
}