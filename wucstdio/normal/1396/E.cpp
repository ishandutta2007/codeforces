#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
struct LCT
{
	#define lc tree[x].child[0]
	#define rc tree[x].child[1]
	struct Node
	{
		int parent;
		int child[2];
		int sum;
		int sze;
		bool flag;
		int v;
		bool rev;
	}tree[100005];
	int st[100005],top;
	bool nroot(int x)
	{
		return tree[tree[x].parent].child[0]==x||tree[tree[x].parent].child[1]==x;
	}
	void pushup(int x)
	{
		tree[x].sze=tree[lc].sze+tree[rc].sze+1;
		tree[x].sum=tree[lc].sum+tree[rc].sum+tree[x].v;
	}
	void pushr(int x)
	{
		swap(lc,rc);
		tree[x].rev^=1;
	}
	void pushdown(int x)
	{
		if(tree[x].rev)
		{
			if(lc)pushr(lc);
			if(rc)pushr(rc);
			tree[x].rev=0;
		}
		if(tree[x].flag)
		{
			if(lc)
			{
				tree[lc].flag^=1;
				tree[lc].sum=tree[lc].sze-tree[lc].sum;
				tree[lc].v^=1;
			}
			if(rc)
			{
				tree[rc].flag^=1;
				tree[rc].sum=tree[rc].sze-tree[rc].sum;
				tree[rc].v^=1;
			}
			tree[x].flag=0;
		}
	}
	bool identify(int x)
	{
		return tree[tree[x].parent].child[1]==x;
	}
	void connect(int x,int pa,bool flag)
	{
		tree[x].parent=pa;
		tree[pa].child[flag]=x;
	}
	void rotate(int x)
	{
		int y=tree[x].parent;
		int r=tree[y].parent;
		bool flag_y=identify(y);
		bool flag_x=identify(x);
		int b=tree[x].child[!flag_x];
		if(nroot(y))tree[r].child[flag_y]=x;
		tree[x].parent=r;
		connect(b,y,flag_x);
		connect(y,x,!flag_x);
		pushup(y);
		pushup(x);
	}
	void splay(int at)
	{
		top=0;
		int pa=at;
		st[++top]=pa;
		while(nroot(pa))
		{
			pa=tree[pa].parent;
			st[++top]=pa;
		}
		while(top)pushdown(st[top--]);
		while(nroot(at))
		{
			pa=tree[at].parent;
			if(!nroot(pa))rotate(at);
			else if(identify(at)==identify(pa))
			{
				rotate(pa);
				rotate(at);
			}
			else
			{
				rotate(at);
				rotate(at);
			}
		}
	}
	void access(int x)
	{
		int last=0;
		while(x)
		{
			splay(x);
			rc=last;
			pushup(x);
			last=x;
			x=tree[x].parent;
		}
	}
	void makeroot(int x)
	{
		access(x);
		splay(x);
		pushr(x);
	}
	int findroot(int x)
	{
		access(x);
		splay(x);
		while(lc)
		{
			pushdown(x);
			x=lc;
		}
		return x;
	}
	void split(int x,int y)
	{
		makeroot(x);
		access(y);
		splay(y);
	}
	void link(int x,int y)
	{
		makeroot(x);
		if(findroot(y)!=x)
		  tree[x].parent=y;
		pushup(y);
	}
	void cut(int x,int y)
	{
		makeroot(x);
		if(findroot(y)==x&&tree[x].parent==y&&!rc)
		{
			tree[x].parent=0;
			tree[y].child[0]=0;
			pushup(y);
		}
	}
}L;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,edgenum,head[100005],sze[100005],maxs[100005],dep[100005],root,pa[100005],ans;
ll k,maxv;
int match[100005];
bool flag[100005];
priority_queue<pair<int,int> >q;
vector<int>s[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		sze[node]+=sze[to];
		maxs[node]=max(maxs[node],sze[to]);
	}
	maxs[node]=max(maxs[node],n-sze[node]);
	if(maxs[node]<maxs[root])root=node;
	maxv+=min(sze[node],n-sze[node]);
}
void dfs2(int node,int r)
{
	sze[node]=1;
	dep[node]=dep[pa[node]]+1;
	s[r].push_back(node);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs2(to,r);
		sze[node]+=sze[to];
	}
}
void dfs3(int node)
{
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||flag[to])continue;
		pa[to]=node;
		dfs3(to);
		sze[node]+=sze[to];
		if(!match[to])
		{
			if(match[node])
			{
				int v=match[node];
				match[v]=to,match[to]=v;
				match[node]=0;
			}
			else match[node]=to,match[to]=node;
		}
	}
}
bool cmp(int a,int b)
{
	return dep[a]<dep[b];
}
int main()
{
	maxs[0]=2147483647;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	if(k>maxv||((maxv-k)&1))
	{
		printf("NO\n");
		return 0;
	}
	memset(pa,0,sizeof(pa));
	sze[root]=0;
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		pa[to]=root;
		dfs2(to,to);
		sort(s[to].begin(),s[to].end(),cmp);
		q.push(make_pair(sze[to],to));
	}
	s[root].push_back(root);
	q.push(make_pair(1,root));
	for(int i=1;i<=n;i++)
	{
		if(sze[i]&1)L.tree[i].v=L.tree[i].sum=1,ans++;
		L.tree[i].sze=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==root)continue;
		L.tree[i].parent=pa[i];
	}
	if(k<ans)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	while(k>=ans)
	{
		int u=q.top().second;
		q.pop();
		int v=q.top().second;
		q.pop();
		int x=s[u].back();
		int y=s[v].back();
		L.split(x,y);
		if(k-(L.tree[y].sze-1)>ans-L.tree[y].sum+(L.tree[y].sze-1-L.tree[y].sum))
		{
			k-=L.tree[y].sze-1;
			ans=ans-L.tree[y].sum+(L.tree[y].sze-1-L.tree[y].sum);
			L.tree[y].sum=L.tree[y].sze-L.tree[y].sum;
			L.tree[y].flag^=1;
			L.tree[y].v^=1;
			L.splay(root);
			L.tree[root].v=0;
			L.pushup(x);
			L.cut(x,pa[x]);
			L.cut(y,pa[y]);
			s[u].pop_back();
			s[v].pop_back();
			sze[u]--;
			sze[v]--;
			flag[x]=flag[y]=1;
			if(sze[u])q.push(make_pair(sze[u],u));
			if(sze[v])q.push(make_pair(sze[v],v));
			printf("%d %d\n",x,y);
		}
		else break;
	}
	dfs3(root);
	k-=ans;
	for(int i=1;i<=n;i++)
	{
		if(!k)break;
		if(flag[i])continue;
		if(i!=root&&sze[i]%2==0)
		{
			int j=pa[i];
			int ii=match[i];
			int jj=match[j];
			match[i]=jj,match[jj]=i;
			match[ii]=j,match[j]=ii;
			k-=2;
		}
	}
	for(int i=1;i<=n;i++)
	  if(match[i]>i)printf("%d %d\n",i,match[i]);
	return 0;
}