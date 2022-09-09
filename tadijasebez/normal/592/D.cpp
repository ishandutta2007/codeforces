#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
const int inf=1e9+7;
vector<int> E[N];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int sz[N],sz2[N],dp[N],sol=inf,cnt;
bool mark[N],has[N];
void PreCalc(int u, int p)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		PreCalc(v,u);
		if(has[v])
		{
			dp[u]+=dp[v]+2;
			sz[u]=max(sz[u],sz[v]+1);
			has[u]=1;
		}
	}
	if(!has[u] && mark[u]) has[u]=1;
}
void Solve(int u, int p, int d, int b, bool up)
{
	int best=0,i;
	vector<int> tmp;
	if(up)
	{
		b++;
		d+=2;
		best=b;
		tmp.push_back(b);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p || !has[v]) continue;
		tmp.push_back(sz[v]+1);
		best=max(best,sz[v]+1);
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	if(up)
	{
		int ans=d+dp[u]-best;
		//printf("%i %i\n",u,ans);
		if(sol>ans) sol=ans,cnt=u;
		if(ans==sol) cnt=min(u,cnt);
	}
	else
	{
		int ans=dp[u]-best;
		//printf("%i %i\n",u,ans);
		if(sol>ans) sol=ans,cnt=u;
		if(sol==ans) cnt=min(u,cnt);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		if(has[v])
		{
			if(up)
			{
				int temp;
				if(tmp[0]==sz[v]+1) temp=tmp[1];
				else temp=tmp[0];
				Solve(v,u,d+dp[u]-dp[v]-2,temp,true);
			}
			else
			{
				if(tmp.size()==1)
				{
					if(mark[u]) Solve(v,u,0,0,true);
					else Solve(v,u,0,0,false);
				}
				else
				{
					int temp;
					if(tmp[0]==sz[v]+1) temp=tmp[1];
					else temp=tmp[0];
					Solve(v,u,dp[u]-dp[v]-2,temp,true);
				}
			}
		}
		else
		{
			Solve(v,u,d+dp[u],best,true);
		}
	}
}
int main()
{
	int n,k,u,v,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	while(k--) scanf("%i",&u),mark[u]=1;
	PreCalc(1,0);
	//for(i=1;i<=n;i++) printf("%i ",sz[i]);printf("\n");
	//for(i=1;i<=n;i++) printf("%i ",dp[i]);printf("\n");
	Solve(1,0,0,0,0);
	printf("%i\n",cnt);
	printf("%i\n",sol);
	return 0;
}