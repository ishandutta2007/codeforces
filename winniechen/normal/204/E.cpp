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
#define ll long long
char s[N];int n,K;
#define lson l,m,tr[rt].ls
#define rson m+1,r,tr[rt].rs
struct Segment{int ls,rs,siz;}tr[N*40];int cnt;
void insert(int v,int l,int r,int &rt)
{
	if(!rt)rt=++cnt;tr[rt].siz++;if(l==r)return ;int m=(l+r)>>1;
	if(v<=m)insert(v,lson);else insert(v,rson);
}
int merge(int l,int r,int x,int y)
{
	if(!x||!y)return x|y;if(l==r)return x;int m=(l+r)>>1,rt=++cnt;
	tr[rt].ls=merge(l,m,tr[x].ls,tr[y].ls),tr[rt].rs=merge(m+1,r,tr[x].rs,tr[y].rs);
	return tr[rt].siz=tr[tr[rt].ls].siz+tr[tr[rt].rs].siz,rt;
}
namespace Sam
{
	const int N = 200005;
	int trs[N][26],len[N],fa[N],cnt,lst,rot[N],f[18][N];
	void init(){lst=cnt=1;}
	void insert(int x,int id)
	{
		int np,p=lst,q,nq;
		if(q=trs[p][x])
		{
			if(len[q]==len[p]+1)lst=q;
			else 
			{
				len[nq=++cnt]=len[p]+1,fa[nq]=fa[q],fa[q]=lst=nq;
				memcpy(trs[nq],trs[q],sizeof(trs[q]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
		}else
		{
			len[np=++cnt]=len[p]+1,lst=np;
			for(;p&&!trs[p][x];p=fa[p])trs[p][x]=np;
			if(!p)fa[np]=1;else if(len[q=trs[p][x]]==len[p]+1)fa[np]=q;
			else
			{
				len[nq=++cnt]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
				memcpy(trs[nq],trs[q],sizeof(trs[q]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
		}::insert(id,1,n,rot[lst]);
	}
	struct node{int to,next;}e[N];int head[N],edge_cnt;
	void add(int x,int y){e[edge_cnt]=(node){y,head[x]};head[x]=edge_cnt++;}
	void dfs(int x){for(int i=head[x];i!=-1;i=e[i].next)dfs(e[i].to),rot[x]=merge(1,n,rot[x],rot[e[i].to]);}
	void build()
	{
		memset(head,-1,sizeof(head));for(int i=2;i<=cnt;i++)add(fa[i],i),f[0][i]=fa[i];dfs(1);
		for(int i=1;i<18;i++)for(int j=1;j<=cnt;j++)f[i][j]=f[i-1][f[i-1][j]];
	}
	int query(int rt)
	{
		for(int i=17;~i;i--)if(f[i][rt]&&tr[rot[f[i][rt]]].siz<K)rt=f[i][rt];
		if(tr[rot[rt]].siz<K)rt=f[0][rt];
		return len[rt];
	}
	ll match(char *s)
	{
		int l=strlen(s+1),rt=1;ll ret=0;
		for(int i=1;i<=l;i++)rt=trs[rt][s[i]-'a'],ret+=query(rt);return ret;
	}
}
vector<char >v[N];
int main()
{
	scanf("%d%d",&n,&K);Sam::init();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);int l=strlen(s+1);Sam::lst=1;
		for(int j=1;j<=l;j++)Sam::insert(s[j]-'a',i),v[i].push_back(s[j]);
	}Sam::build();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)s[j+1]=v[i][j];s[v[i].size()+1]='\0';
		printf("%lld ",Sam::match(s));
	}
}