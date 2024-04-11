#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
const int M=4*N;
vector<int> E[M],R[N];
int ls[M],rs[M],cnt,root;
void Build(int &c, int ss, int se)
{
	if(!c) c=++cnt;
	if(ss==se){ c=ss;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	E[c].push_back(ls[c]);
	E[c].push_back(rs[c]);
}
void Set(int c, int ss, int se, int qs, int qe, int nod)
{
	if(qs>qe) return;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		E[nod].push_back(c);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,nod);
	Set(rs[c],mid+1,se,qs,qe,nod);
}
bool vis[M];
int num;
void DFS(int u, int n)
{
	if(vis[u]) return;
	if(u<=n) num++;
	vis[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v,n);
	}
}
int main()
{
	int n,m,i,j,u,v;
	scanf("%i %i",&n,&m);
	cnt=n;
	Build(root,1,n);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		R[u].push_back(v);
		R[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		R[i].push_back(0);
		R[i].push_back(n+1);
		sort(R[i].begin(),R[i].end());
		for(j=1;j<R[i].size();j++) Set(root,1,n,R[i][j-1]+1,R[i][j]-1,i);
	}
	vector<int> sol;
	for(i=1;i<=n;i++) if(!vis[i]) num=0,DFS(i,n),sol.push_back(num);
	sort(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}