#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
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
int fa[200005];
bool vis[200005];
int w[200005];
int ans[200005];
int p[200005];
signed main()
{
	int t,n,pre;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			fa[i]=read();
			if(fa[i]==i)fa[i]=0;
		}
		for(int i=1;i<=n;i++)p[i]=read();
		vis[0]=true;
		for(int i=1;i<=n;i++)vis[i]=false;
		flag=true;
		pre=-1;
		w[0]=-1;
		for(int i=1;i<=n;i++)
		{
			if(vis[fa[p[i]]]==false)
			{
				flag=false;
				break;
			}
			pre=max(pre+1,w[fa[p[i]]]+1);
			w[p[i]]=pre;
			vis[p[i]]=true;
			ans[p[i]]=w[p[i]]-w[fa[p[i]]];
			if(fa[p[i]]==0)ans[p[i]]=0;
		}
		if(flag==false)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}