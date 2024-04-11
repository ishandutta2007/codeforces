#include<bits/stdc++.h>
using namespace std;
const int max_m=4e5+5;
char str[max_m];
const int max_tot=4e5+5;
int End[max_tot<<2],Last[max_tot],Next[max_tot<<2],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
}
int dfn[max_tot],low[max_tot],Time,st[max_tot],tp;
bool mark_in[max_tot];
int col[max_tot],cnt_scc;
vector<int> scc[max_tot];
void tarjan(int x)
{
	dfn[x]=low[x]=++Time;
	st[++tp]=x;
	mark_in[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(mark_in[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		++cnt_scc;
		while(mark_in[x])
		{
			scc[cnt_scc].push_back(st[tp]);
			col[st[tp]]=cnt_scc;
			mark_in[st[tp--]]=false;
		}
	}
}
vector<int> edge[max_tot];
int deg[max_tot],id[max_tot];
bool del[max_tot];
int que[max_tot],head,tail;
int Hash[max_tot],R,l[max_tot],r[max_tot];
struct Segment
{
	int l,r;
}s[max_tot];
int cnt;
inline bool operator < (const Segment &a,const Segment &b)
{
	return a.l<b.l;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<char> > Map(n,vector<char>(m));
	vector<vector<int> > node(n,vector<int>(m));
	int tot=0;
	for(int i=0;i<n;++i)
	{
		scanf("%s",str);
		for(int j=0;j<m;++j)
		{
			Map[i][j]=str[j];
			if(str[j]=='#')
				node[i][j]=++tot;
		}
	}
	vector<vector<int> > nxt(n,vector<int>(m));
	for(int j=0;j<m;++j)
		for(int i=n-1;i>=0;--i)
		{
			if(Map[i][j]=='#')
				nxt[i][j]=node[i][j];
			else
				nxt[i][j]=i<n-1?nxt[i+1][j]:0;
		}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(Map[i][j]=='#')
			{
				int x=node[i][j];
				if(i<n-1&&nxt[i+1][j])
					add_edge(x,nxt[i+1][j]);
				if(j>0&&nxt[i][j-1])
					add_edge(x,nxt[i][j-1]);
				if(j<m-1&&nxt[i][j+1])
					add_edge(x,nxt[i][j+1]);
				if(i>0&&Map[i-1][j]=='#')
					add_edge(x,node[i-1][j]);
			}
		}
	for(int i=1;i<=tot;++i)
	{
		if(!dfn[i])
			tarjan(i);
	}
	for(int x=1;x<=tot;++x)
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(col[x]!=col[y])
			{
				edge[col[x]].push_back(col[y]);
				++deg[col[y]];
			}
		}
	for(int j=0;j<m;++j)
	{
		int a;
		scanf("%d",&a);
		if(!a)
			continue;
		for(int i=n-1;i>=0;--i)
		{
			if(Map[i][j]=='#')
			{
				if(a==1)
				{
					id[col[node[i][j]]]=j+1;
					break;
				}
				--a;
			}
		}
	}
	head=1,tail=0;
	for(int i=1;i<=cnt_scc;++i)
	{
		if(!deg[i])
			que[++tail]=i;
	}
	while(head<=tail)
	{
		int x=que[head++];
		if(!del[x]&&id[x])
			Hash[++R]=id[x];
		for(vector<int>::iterator it=edge[x].begin();it!=edge[x].end();++it)
		{
			int y=*it;
			if(del[x]||id[x])
				del[y]=true;
			if(!--deg[y])
				que[++tail]=y;
		}
	}
	assert(tail==cnt_scc);
	sort(Hash+1,Hash+R+1);
	assert(unique(Hash+1,Hash+R+1)-Hash-1==R);
	for(int i=cnt_scc;i>=1;--i)
	{
		int x=que[i];
		if(!del[x]&&id[x])
			l[x]=r[x]=lower_bound(Hash+1,Hash+R+1,id[x])-Hash;
		else
			l[x]=1e9,r[x]=0;
		for(vector<int>::iterator it=edge[x].begin();it!=edge[x].end();++it)
		{
			int y=*it;
			l[x]=min(l[x],l[y]);
			r[x]=max(r[x],r[y]);
		}
		if(l[x]<=r[x])
		{
			s[++cnt].l=l[x];
			s[cnt].r=r[x];
		}
	}
	sort(s+1,s+cnt+1);
	int id=1,now=0,ans=0;
	while(now<R)
	{
		int mx=0;
		while(id<=cnt&&s[id].l<=now+1)
			mx=max(mx,s[id++].r);
		assert(mx>now);
		now=mx;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}