#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=200050;
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
vector<int> E[N];
vector<int> ans;
int disc[N],cnt,time,par[N];
int done,k;
void DFS(int u, int p)
{
	par[u]=p;
	disc[u]=++time;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		if(!disc[v]) DFS(v,u);
		else if(disc[v]<disc[u])
		{
			done++;
			int tmp=u;
			while(tmp!=v) cnt++,tmp=par[tmp];
			cnt++;
			ans.push_back(cnt);
			cnt=0;
		}
	}
}
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		E[i].push_back(x);
		E[x].push_back(i);
	}
	for(i=1;i<=n;i++) if(!disc[i]) DFS(i,0),k++;
	for(;done<k;done++) ans.push_back(2);
	int sol=pow(2,n);
	int mass=0,tmp=1;
	for(i=0;i<ans.size();i++)
	{
		mass+=ans[i];
		sol-=(ll)pow(2,n-mass+1)*tmp%mod;
		if(sol<0) sol+=mod;
		int temp=pow(2,ans[i])-2;
		if(temp<0) temp+=mod;
		tmp=(ll)tmp*temp%mod;
	}
	printf("%i\n",sol);
	return 0;
}