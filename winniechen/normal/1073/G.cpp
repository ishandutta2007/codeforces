#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
const int N = 200005;
char s[N];int n,Q,pos[N];ll ans;
namespace Sam
{
	const int N = 400005;
	int trs[N][26],len[N],fa[N],cnt,lst;
	void init(){cnt=lst=1;}
	void insert(int x,int id)
	{
		int np=++cnt,p=lst,q,nq;len[lst=np]=len[p]+1;pos[id]=np;
		for(;p&&!trs[p][x];p=fa[p])trs[p][x]=np;
		if(!p)fa[np]=1;else if(len[q=trs[p][x]]==len[p]+1)fa[np]=q;
		else
		{
			len[nq=++cnt]=len[p]+1;fa[nq]=fa[q];fa[q]=fa[np]=nq;
			memcpy(trs[nq],trs[q],sizeof(trs[q]));
			for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
		}
	}
	struct node{int to,next;}e[N];int head[N],edge_cnt,son[N],siz[N],anc[N],dep[N],idx[N],tims;
	void add(int x,int y){e[edge_cnt]=(node){y,head[x]};head[x]=edge_cnt++;}
	void dfs1(int x)
	{
		siz[x]=1;idx[x]=++tims;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;dep[to1]=dep[x]+1;
			dfs1(to1);siz[x]+=siz[to1],siz[son[x]]<siz[to1]?son[x]=to1:0;
		}
	}
	void dfs2(int x,int top){anc[x]=top;if(son[x])dfs2(son[x],top);for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=son[x])dfs2(e[i].to,e[i].to);}
	int get_lca(int x,int y){while(anc[x]!=anc[y])if(dep[anc[x]]>dep[anc[y]])x=fa[anc[x]];else y=fa[anc[y]];return dep[x]>dep[y]?y:x;}
	void build(){memset(head,-1,sizeof(head));for(int i=2;i<=cnt;i++)add(fa[i],i);dfs1(1);dfs2(1,1);}
	int used[N][2],q[N],f[N][2],size,sta[N],top;vector<int >v[N];
	bool cmp(int x,int y){return idx[x]<idx[y];}
	void dfs(int x)
	{
		f[x][0]=0,f[x][1]=0;
		for(int i=0,to1;i<v[x].size();i++)to1=v[x][i],dfs(to1),ans+=len[x]*((ll)f[x][0]*f[to1][1]+(ll)f[x][1]*f[to1][0]),f[x][0]+=f[to1][0],f[x][1]+=f[to1][1];
		if(used[x][0])ans+=(ll)len[x]*f[x][1],f[x][0]++;if(used[x][1])ans+=(ll)len[x]*f[x][0],f[x][1]++;v[x].clear();
	}
	void solve(int sn,int sm)
	{
		for(int i=1,x;i<=sn;i++)scanf("%d",&x),q[i]=pos[x],used[pos[x]][0]=1;
		for(int i=1,x;i<=sm;i++)scanf("%d",&x),q[i+sn]=pos[x],used[pos[x]][1]=1;
		sort(q+1,q+sn+sm+1);size=unique(q+1,q+sn+sm+1)-q-1;
		sort(q+1,q+size+1,cmp);top=0;sta[++top]=1;
		for(int i=1;i<=size;i++)
		{
			int x=q[i],lca=get_lca(x,sta[top]);
			while(top>1&&dep[lca]<=dep[sta[top-1]])v[sta[top-1]].push_back(sta[top]),top--;
			if(sta[top]!=lca)v[lca].push_back(sta[top]),sta[top]=lca;if(sta[top]!=x)sta[++top]=x;
		}while(top>1)v[sta[top-1]].push_back(sta[top]),top--;ans=0;dfs(1);printf("%lld\n",ans);
		for(int i=1;i<=size;i++)used[q[i]][0]=used[q[i]][1]=0;
	}
}
int main()
{
	Sam::init();
	scanf("%d%d%s",&n,&Q,s+1);
	for(int i=n;i;i--)Sam::insert(s[i]-'a',i);Sam::build();
	for(int x,y;Q--;Sam::solve(x,y))scanf("%d%d",&x,&y);
}