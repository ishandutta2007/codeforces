#include<bits/stdc++.h>
#define mod 998244353LL
using namespace std;
const int N=300005;
vector<int>e[N];
int num[N],vis[N];
long long t[2];
void dfs(int v,int f)
{
	vis[v]=1;
	num[v]=1-num[f];
	t[num[v]]++;
	for(int i=0;i<e[v].size();i++)
		if(!vis[e[v][i]])
			dfs(e[v][i],v);
}
long long poww(int a,int b) 
{
    long long ans=1,base=a;
    while(b!=0) 
	{
        if(b&1!=0)
            ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			num[i]=-1;
			vis[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				t[0]=t[1]=0;
				dfs(i,N-1);
				ans=(ans*(poww(2,t[0])+poww(2,t[1]))%mod)%mod;
			}
		}
		int flag=1; 
		for(int i=1;i<=n&&flag;i++)
		{
			for(int j=0;j<e[i].size();j++)
			{
				if(num[i]+num[e[i][j]]!=1)
				{
					flag=0;
					break;
				}
			}
		}
		printf("%I64d\n",flag?ans:0);
	}
	return 0;
}