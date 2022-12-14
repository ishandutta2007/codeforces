#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
const int N = 100005;
char s[N],ans[N];int n,Q,le,cnt,ans_l;
#define lson l,m,tr[rt].ls
#define rson m+1,r,tr[rt].rs
struct Segment{int ls,rs;}tr[N*40];
void insert(int x,int l,int r,int &rt)
{
	if(!rt)rt=++cnt;if(l==r)return ;int m=(l+r)>>1;
	if(x<=m)insert(x,lson);else insert(x,rson);
}
int merge(int x,int y){if(!x||!y)return x|y;int rt=++cnt;tr[rt].ls=merge(tr[x].ls,tr[y].ls);tr[rt].rs=merge(tr[x].rs,tr[y].rs);return rt;}
int query(int L,int R,int l,int r,int rt)
{
	if(!rt)return 0;if(L<=l&&r<=R)return 1;int m=(l+r)>>1;
	if(L<=m&&query(L,R,lson))return 1;if(m<R&&query(L,R,rson))return 1;return 0;
}
namespace Sam
{
	const int N = 200005;
	int trs[N][26],fa[N],len[N],cnt,lst,rot[N];
	void init(){lst=cnt=1;}
	void insert(int x,int id)
	{
		int np=++cnt,p=lst,q,nq;len[lst=np]=len[p]+1;
		for(;p&&!trs[p][x];p=fa[p])trs[p][x]=np;
		if(!p)fa[np]=1;else if(len[q=trs[p][x]]==len[p]+1)fa[np]=q;
		else
		{
			len[nq=++cnt]=len[p]+1;fa[nq]=fa[q];fa[q]=fa[np]=nq;
			memcpy(trs[nq],trs[q],sizeof(trs[q]));
			for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
		}::insert(id,1,n,rot[np]);
	}
	struct node{int to,next;}e[N];int head[N],edge_cnt;
	void add(int x,int y){e[edge_cnt]=(node){y,head[x]};head[x]=edge_cnt++;}
	void dfs(int x){for(int i=head[x];i!=-1;i=e[i].next)dfs(e[i].to),rot[x]=merge(rot[x],rot[e[i].to]);}
	void build(){memset(head,-1,sizeof(head));for(int i=2;i<=cnt;i++)add(fa[i],i);dfs(1);}
	inline bool check(int rt,int L,int R){return query(L,R,1,n,rot[rt]);}
	bool solve(int rt,int p,int L,int R)
	{
		bool ret=0;
		if(p==le+1)
		{
			for(int i=0;i<26;i++)if(check(trs[rt][i],L,R)){ret=1;ans_l=p;ans[p]='a'+i;break;}
			return ret;
		}int x=s[p]-'a';
		if(check(trs[rt][x],L,R))ret=solve(trs[rt][x],p+1,L+1,R);if(ret){ans[p]=x+'a';return 1;}
		for(int i=x+1;i<26;i++)if(check(trs[rt][i],L,R)){ret=1;ans_l=p;ans[p]='a'+i;break;}
		return ret;
	}
}
int main()
{
	scanf("%s%d",s+1,&Q);n=strlen(s+1);Sam::init();
	for(int i=1;i<=n;i++)Sam::insert(s[i]-'a',i);Sam::build();
	while(Q--)
	{
		int x,y;
		scanf("%d%d%s",&x,&y,s+1);le=strlen(s+1);
		if(!Sam::solve(1,1,x,y))puts("-1");
		else 
		{
			for(int i=1;i<=ans_l;i++)putchar(ans[i]);putchar('\n');
		}
	}
}