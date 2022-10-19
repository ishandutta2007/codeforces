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
bool vis[200005];
int main()
{
	int t,x,y,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		if(x>y)swap(x,y);
		for(int i=0;i<=x+y;i++)vis[i]=false;
		for(int i=0;i<=x;i++)vis[x+(x+y)/2-2*i]=true,vis[x+(x+y+1)/2-2*i]=true;
		ans=0;
		for(int i=0;i<=x+y;i++)if(vis[i]==true)ans++;
		printf("%d\n",ans);
		for(int i=0;i<=x+y;i++)if(vis[i]==true)printf("%d ",i);
		printf("\n");
	}
	return 0;
}