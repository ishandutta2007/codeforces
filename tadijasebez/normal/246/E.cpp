#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
map<string,int> id;
const int N=100050;
const int M=50*N;
int x[M],ls[M],rs[M],clock;
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]+val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> E[N];
vector<int> D[N],I[N];
vector<int> root[N];
int b[N],e[N],time,dep[N],par[N],a[N],cnt,p[N];
void DFS(int u)
{
	dep[u]=dep[par[u]]+1;
	D[dep[u]].push_back(u);
	b[u]=++time;
	I[dep[u]].push_back(b[u]);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);
	}
	e[u]=time;
}
string s;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		cin >> s;
		if(!id[s]) id[s]=++cnt;
		a[i]=id[s];
		scanf("%i",&par[i]);
		if(par[i]) E[par[i]].push_back(i);
	}
	for(i=1;i<=n;i++) if(!par[i]) DFS(i);
	for(i=1;i<=n;i++)
	{
		if(D[i].empty()) break;
		root[i].push_back(0);
		for(j=0;j<D[i].size();j++)
		{
			root[i].push_back(root[i].back());
			Set(root[i][j+1],root[i][j+1],1,D[i].size(),j+1,1);
			if(p[a[D[i][j]]]) Set(root[i][j+1],root[i][j+1],1,D[i].size(),p[a[D[i][j]]],-1);
			p[a[D[i][j]]]=j+1;
		}
		for(j=0;j<D[i].size();j++)
		{
			p[a[D[i][j]]]=0;
		}
	}
	int q,u,k;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&u,&k);
		int d=dep[u]+k;
		if(d>=N || D[d].empty())
		{
			printf("0\n");
			continue;
		}
		int l=lower_bound(I[d].begin(),I[d].end(),b[u])-I[d].begin()+1;
		int r=upper_bound(I[d].begin(),I[d].end(),e[u])-I[d].begin();
		if(l>r)
		{
			printf("0\n");
			continue;
		}
		printf("%i\n",Get(root[d][r],1,D[d].size(),l,r));
	}
	return 0;
}