#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=500050*2;
int nxt[N];
vector<int> E[N];
int in[N];
void Add(int u, int v){ E[u].pb(v);in[v]++;}
int ls[N],rs[N],tsz,root,ans[N],id[N];
void Build(int &c, int ss, int se)
{
	if(ss!=se) c=++tsz;
	else{ c=ss;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	Add(ls[c],c);
	Add(rs[c],c);
}
void AddEdge(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ Add(c,x);return;}
	int mid=ss+se>>1;
	AddEdge(ls[c],ss,mid,qs,qe,x);
	AddEdge(rs[c],mid+1,se,qs,qe,x);
}
void Run()
{
    int n,i;
    scanf("%i",&n);
    tsz=n;
    Build(root,1,n);
    for(i=1;i<=n;i++)
	{
		scanf("%i",&nxt[i]);
		if(nxt[i]!=-1)
		{
            AddEdge(root,1,n,i+1,nxt[i]-1,i);
			if(nxt[i]!=n+1) Add(i,nxt[i]);
		}
	}
	queue<int> q;
	for(i=1;i<=tsz;i++) if(in[i]==0) q.push(i);
	int tme=0;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		ans[x]=++tme;
		for(int y:E[x])
		{
			in[y]--;
			if(!in[y]) q.push(y);
		}
	}
	if(tme==tsz)
	{
		for(i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+1+n,[&](int x, int y){ return ans[x]<ans[y];});
		for(i=1;i<=n;i++) ans[id[i]]=i;
		for(i=1;i<=n;i++) printf("%i ",ans[i]);printf("\n");
	}
	else printf("-1\n");
	for(i=1;i<=tsz;i++)
	{
		E[i].clear();
		in[i]=ls[i]=rs[i]=0;
	}
	root=0;
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--) Run();
	return 0;
}