#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 400005
int n;char s[N];
struct Segment{int ls,rs;}tr[N*40];
int cnt,ans=1;
#define lson l,m,tr[rt].ls
#define rson m+1,r,tr[rt].rs
void Update(int x,int l,int r,int &rt)
{
	if(!rt)rt=++cnt;if(l==r)return ;int m=(l+r)>>1;
	if(x<=m)Update(x,lson);else Update(x,rson);
}
void merge(int x,int y,int &rt)
{
	if(!x||!y)return void(rt=x+y);rt=++cnt;
	merge(tr[x].ls,tr[y].ls,tr[rt].ls);
	merge(tr[x].rs,tr[y].rs,tr[rt].rs);
}
int query(int L,int R,int l,int r,int rt)
{
	if(!rt)return 0;if(L<=l&&r<=R)return 1;int m=(l+r)>>1;
	if(L<=m&&query(L,R,lson))return 1;return (m<R)&&query(L,R,rson);
}
#undef N
namespace SAM
{
	const int N = 400005;
	int trs[N][26],fa[N],len[N],cnt,lst,rot[N],f[N],top[N],pos[N];
	void init(){lst=cnt=1;}
	void insert(int x,int id)
	{
		int p=lst,np=++cnt,q,nq;len[lst=np]=len[p]+1;Update(id,1,n,rot[np]);pos[np]=id;
		for(;p&&!trs[p][x];p=fa[p])trs[p][x]=np;
		if(!p)fa[np]=1;
		else
		{
			q=trs[p][x];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				len[nq=++cnt]=len[p]+1;fa[nq]=fa[q];fa[np]=fa[q]=nq;pos[nq]=pos[q];
				memcpy(trs[nq],trs[q],sizeof(trs[nq]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
		}
	}
	struct node{int to,next;}e[N];int head[N],edge_cnt;
	void add(int x,int y){e[edge_cnt]=(node){y,head[x]};head[x]=edge_cnt++;}
	void dfs(int x){for(int i=head[x];i!=-1;i=e[i].next)dfs(e[i].to),merge(rot[x],rot[e[i].to],rot[x]);}
	void build(){memset(head,-1,sizeof(head));for(int i=2;i<=cnt;i++)add(fa[i],i);dfs(1);}
	void bfs()
	{
		queue<int >q;q.push(1);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i!=-1;i=e[i].next)
			{
				int to1=e[i].to;
				q.push(to1);
				if(x==1){f[to1]=1,top[to1]=to1;continue;}
				if(query(pos[to1]-len[to1]+len[top[x]],pos[to1]-1,1,n,rot[top[x]]))
					f[to1]=f[x]+1,top[to1]=to1;
				else f[to1]=f[x],top[to1]=top[x];
				ans=max(ans,f[to1]);
			}
		}
	}
}
int main()
{
	scanf("%d%s",&n,s+1);SAM::init();
	for(int i=1;i<=n;i++)SAM::insert(s[i]-'a',i);SAM::build();SAM::bfs();
	printf("%d\n",ans);
}