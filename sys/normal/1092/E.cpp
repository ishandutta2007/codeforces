#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005;
int n,m,head[Maxn],cnt,ct,sta[Maxn],dep[Maxn],all,pnt;
bool done;
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
void dfs(int u,int fa)
{ 
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[pnt]) pnt=u,ct=0,done=false;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
			dfs(to,u);
	}
}
void get_sta(int u,int fa,int goal)
{
	if(goal==u) sta[++ct]=u;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			get_sta(to,u,goal);
			if(ct)
			{
				sta[++ct]=u;
				return ;
			}
		}
	}
}
struct Tree
{
	int dis,mid,x,y;
	bool operator < (const Tree &tmp) const
	{
		return dis<tmp.dis;
	}
}tree[Maxn];
priority_queue <Tree> Pr;
struct Print
{
	int x,y;
}print[Maxn];
void merge(Tree a,Tree b)
{
	print[++all]=(Print){a.mid,b.mid}; 
	add(a.mid,b.mid);
	add(b.mid,a.mid); 
	Tree tmp;
	ct=0;
	pnt=0;
	dfs(a.y,0);
	tmp.x=pnt;
	ct=0;
	done=false;
	dfs(pnt,0);
	get_sta(pnt,0,tmp.x);
	tmp.y=pnt;
	tmp.dis=dep[pnt]-1;
	tmp.mid=sta[ct/2+1];
	Pr.push(tmp);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!dep[i])
		{
			Tree tmp;
			ct=0;
			pnt=0;
			dfs(i,0);
			tmp.x=pnt;
			ct=0;
			done=false;
			dfs(pnt,0);
			get_sta(pnt,0,tmp.x);
			tmp.y=pnt;
			tmp.dis=dep[pnt]-1;
			tmp.mid=sta[ct/2+1];
			Pr.push(tmp);
		}
	while(Pr.size()!=1)
	{
		Tree tmp1=Pr.top();
		Pr.pop();
		Tree tmp2=Pr.top();
		Pr.pop();
		merge(tmp1,tmp2);
	}
	printf("%d\n",Pr.top().dis);
	for(int i=1;i<=all;i++)
		printf("%d %d\n",print[i].x,print[i].y);
	return 0;
}