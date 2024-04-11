#include<cstdio>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

const long long MA=1ll<<55;

long long all_sum=0;

long long gcd(long long a,long long b)
{
	if(a==0&&b==0) return 1;
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
	if(b==0) return a;
	if(a==0) return b;
	long long x=gcd(a,b);
	if((double)a*b>(double)MA*x)
	{
		cout<<all_sum<<"\n";
		exit(0);
	}
	return a/x*b;
}

vector<int> G[100100];
int par[100100];
long long mi[100100];
long long xx[100100];

long long a[100100];

void dfs(int v,int p)
{
	par[v]=p;
	for(int i=0;i<G[v].size();i++) if(G[v][i]!=p) dfs(G[v][i],v);
}

void rec(int v)
{
	if(mi[v]!=-1) return;
	if(a[v]!=-1)
	{
		mi[v]=1;
		return;
	}
	long long x=1;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==par[v]) continue;
		rec(G[v][i]);
		x=lcm(x,mi[G[v][i]]);
	}
	mi[v]=x;
	if(v==0) mi[v]*=G[v].size();
	else mi[v]*=(G[v].size()-1);
}

void rec2(int v)
{
	int deg=G[v].size();
	if(v!=0) deg--;
	if(deg==0) return;
	long long tmp=xx[v]/deg;
	for(int i=0;i<G[v].size();i++) if(G[v][i]!=par[v]) xx[G[v][i]]=tmp;
	for(int i=0;i<G[v].size();i++) if(G[v][i]!=par[v]) rec2(G[v][i]);
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
		all_sum+=a[i];
	}
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	a[0]=-1;
	for(int i=1;i<N;i++)
	{
		if(G[i].size()!=1) a[i]=-1;
	}
	for(int i=0;i<N;i++) mi[i]=-1;
	rec(0);
	xx[0]=mi[0];
	rec2(0);
	long long coe=1ll<<55;
	for(int i=1;i<N;i++)
	{
		if(G[i].size()==1)
		{
			coe=min(coe,a[i]/xx[i]);
		}
	}
	long long ans=0;
	for(int i=1;i<N;i++)
	{
		if(G[i].size()==1)
		{
			ans+=(a[i]-coe*xx[i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}