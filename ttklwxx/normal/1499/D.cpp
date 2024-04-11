#include<iostream>
#include<cstdio>
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
int sl[20000005];
int pri[20000005],cnt;
bool vis[20000005];
int c,d,x,ans;
void dfs(int i)
{
	int sth;
	if((1LL*d*i+x)%c!=0)return;
	sth=(1LL*d*i+x)/c;
	if(sth%i!=0)return;
	ans+=sl[sth/i];
}
signed main()
{
	sl[1]=1;
	for(int i=2;i<=20000000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
			sl[i]=2;
		}
		for(int j=1;j<=cnt&&1LL*i*pri[j]<=20000000LL;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)
			{
				sl[i*pri[j]]=sl[i];
				break;
			}
			sl[i*pri[j]]=sl[i]*2;
		}
	}
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		c=read();
		d=read();
		x=read();
		ans=0;
		for(int i=1;i*i<=x;i++)
		{
			if(x%i!=0)continue;
			dfs(i);
			if(i==x/i)continue;
			dfs(x/i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}