#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
const int N = 500005;
#define ll long long
char s[N];int n,m,Q,ans[N],p[N];
struct QaQ{int l,r,pl,pr,idx;}q[N];
bool cmp(const QaQ &a,const QaQ &b){return a.r<b.r;}
namespace Sam
{
	const int N = 100005;
	#define lson l,m,tr[rt].ls
	#define rson m+1,r,tr[rt].rs
	struct Segment{int ls,rs,mx;}tr[N*40];int rot[N],tot;
	inline void PushUp(int rt){tr[rt].mx=max(tr[tr[rt].ls].mx,tr[tr[rt].rs].mx);}
	inline void insert(int x,int l,int r,int &rt)
	{
		if(!rt)rt=++tot;if(l==r){tr[rt].mx++;return ;}int m=(l+r)>>1;
		if(x<=m)insert(x,lson);else insert(x,rson);PushUp(rt);
	}
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y)return x|y;int rt=++tot;if(l==r)return tr[rt].mx=tr[x].mx+tr[y].mx,rt;int m=(l+r)>>1;
		tr[rt].ls=merge(tr[x].ls,tr[y].ls,l,m);tr[rt].rs=merge(tr[x].rs,tr[y].rs,m+1,r);PushUp(rt);return rt;
	}
	int query(int L,int R,int l,int r,int rt)
	{
		if(L<=l&&r<=R)return tr[rt].mx;int m=(l+r)>>1,ret=0;
		if(L<=m)ret=query(L,R,lson);if(m<R)ret=max(ret,query(L,R,rson));return ret;
	}
	int get_p(int L,int R,int v,int l,int r,int rt)
	{
		if(l==r)return v==tr[rt].mx?l:0;int m=(l+r)>>1,ret=0;
		if(L<=m&&tr[tr[rt].ls].mx>=v)ret=get_p(L,R,v,lson);
		if(!ret&&m<R&&tr[tr[rt].rs].mx>=v)ret=get_p(L,R,v,rson);return ret;
	}
	int trs[N][26],fa[N],len[N],cnt,lst;
	void init(){cnt=lst=1;}
	void insert(int x,int id)
	{
		int np,p=lst,q,nq;
		if(q=trs[p][x])
			if(len[q]==len[p]+1)lst=q;
			else 
			{
				len[nq=++cnt]=len[p]+1;fa[nq]=fa[q];lst=fa[q]=nq;
				memcpy(trs[nq],trs[q],sizeof(trs[q]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
		else
		{
			len[np=++cnt]=len[p]+1;lst=np;
			for(;p&&!trs[p][x];p=fa[p])trs[p][x]=np;
			if(!p)fa[np]=1;else if(len[q=trs[p][x]]==len[p]+1)fa[np]=q;
			else
			{
				len[nq=++cnt]=len[p]+1;fa[nq]=fa[q];fa[np]=fa[q]=nq;
				memcpy(trs[nq],trs[q],sizeof(trs[q]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
		}
		insert(id,1,m,rot[lst]);
	}
	struct edge{int to,next;}e[N];int head[N],edge_cnt,dep[N],f[17][N];
	inline void add(int x,int y){e[edge_cnt]=(edge){y,head[x]};head[x]=edge_cnt++;}
	void dfs(int x){f[0][x]=fa[x];for(int i=head[x];i!=-1;i=e[i].next)dep[e[i].to]=dep[x]+1,dfs(e[i].to),rot[x]=merge(rot[x],rot[e[i].to],1,m);}
	void build()
	{
		memset(head,-1,sizeof(head));for(int i=2;i<=cnt;i++)add(fa[i],i);dfs(1);
		for(int i=1;i<17;i++)for(int j=1;j<=cnt;j++)f[i][j]=f[i-1][f[i-1][j]];
	}
	inline int get_K(int x,int y){for(int i=16;~i;i--)if(len[f[i][x]]>=y)x=f[i][x];return x;}
	void match()
	{
		int rt=1,l=0;
		for(int i=1,x,j=1;i<=n;i++)
		{
			x=s[i]-'a';
			while(rt&&!trs[rt][x])rt=fa[rt],l=len[rt];
			if(!rt)rt=1,l=0;else rt=trs[rt][x],l++;
			while(q[j].r==i&&j<=Q)
			{
				if(l<i-q[j].l+1){ans[q[j].idx]=0,p[q[j].idx]=q[j].pl,j++;continue;}
				int tmp=get_K(rt,i-q[j].l+1);
				ans[q[j].idx]=query(q[j].pl,q[j].pr,1,m,rot[tmp]);
				if(!ans[q[j].idx])p[q[j].idx]=q[j].pl;
				else p[q[j].idx]=get_p(q[j].pl,q[j].pr,ans[q[j].idx],1,m,rot[tmp]);
				j++;
			}
		}
	}
}
char t[N];
int main()
{
	scanf("%s%d",s+1,&m);n=strlen(s+1);Sam::init();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",t+1);Sam::lst=1;
		for(int j=1;t[j]!='\0';j++)Sam::insert(t[j]-'a',i);
	}scanf("%d",&Q);Sam::build();
	for(int i=1;i<=Q;i++)scanf("%d%d%d%d",&q[i].pl,&q[i].pr,&q[i].l,&q[i].r),q[i].idx=i;
	sort(q+1,q+Q+1,cmp);Sam::match();
	for(int i=1;i<=Q;i++)printf("%d %d\n",p[i],ans[i]);
}