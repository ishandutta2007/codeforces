#include<iostream>
#include<cstdio>
#include<vector>
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
int sl[100001],pp[100001];
bool vis[100001];
vector<int>v[100001];
signed main()
{
	int t,n,k,x,maxn,mpos;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			sl[i]=read();
			for(int j=0;j<sl[i];j++)
			{
				x=read();
				v[i].push_back(x);
			}
		}
		maxn=0;
		mpos=0;
		for(int i=1;i<=n;i++)
		{
			pp[i]=1000000000;
			for(int j=0;j<sl[i];j++)
			{
				if(!vis[v[i][j]])
				{
					pp[i]=v[i][j];
					vis[v[i][j]]=true;
					break;
				}
			}
			if(pp[i]>maxn)
			{
				maxn=pp[i];
				mpos=i;
			}
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			if(i<maxn)
			{
				printf("IMPROVE\n%lld %lld\n",mpos,i);
				flag=true;
				break;
			}
		}
		if(flag==false)printf("OPTIMAL\n");
		for(int i=1;i<=n;i++)v[i].clear(),sl[i]=0,vis[i]=0;
	}
	return 0;
}