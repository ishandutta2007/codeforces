#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
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
int u[200005],s[200005],sl[200005],tans[200005];
vector<int>v[200005];
bool bi(int x,int y)
{
	return x>y;
}
signed main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			u[i]=read();
			sl[u[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			s[i]=read();
			v[u[i]].push_back(s[i]);
		}
		for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end(),bi);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<sl[i];j++)v[i][j]+=v[i][j-1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=sl[i];j++)
			{
				tans[j]+=v[i][sl[i]/j*j-1];
			}
		}
		for(int i=1;i<=n;i++)printf("%lld ",tans[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			tans[i]=0;
			sl[i]=0;
			v[i].clear();
		}
	}
	return 0;
}