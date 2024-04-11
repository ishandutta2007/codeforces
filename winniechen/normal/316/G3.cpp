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

bool is_last=1;int L[11],R[11],now;
namespace sam
{
	const int N = 500005;
	struct node{int to,next;}e[N<<1];int head[N],edge_cnt;
	inline void add(int x,int y){e[edge_cnt]=(node){y,head[x]};head[x]=edge_cnt++;}
	int trs[N][26],len[N],fa[N],lst,cnt,siz[N][11];bool bel[N],flg[N];
	void init(){memset(flg,1,sizeof(flg));memset(head,-1,sizeof(head));lst=cnt=1;}
	inline void insert(int x)
	{
		int p=lst,np,q,nq;
		if(trs[p][x])
		{
			q=trs[p][x];
			if(len[q]==len[p]+1)lst=q;
			else
			{
				fa[nq=++cnt]=fa[q];len[nq]=len[p]+1;lst=fa[q]=nq;bel[nq]=bel[q];
				memcpy(trs[nq],trs[q],sizeof(trs[nq]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
			if(now)siz[lst][now]=1;
			return ;
		}
		lst=np=++cnt;len[np]=len[p]+1;bel[np]=is_last;
		for(;p&&!trs[p][x];p=fa[p])trs[p][x]=np;
		if(!p)fa[np]=1;
		else
		{
			q=trs[p][x];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				fa[nq=++cnt]=fa[q];len[nq]=len[p]+1;fa[np]=fa[q]=nq;bel[nq]=bel[q];
				memcpy(trs[nq],trs[q],sizeof(trs[nq]));
				for(;p&&trs[p][x]==q;p=fa[p])trs[p][x]=nq;
			}
		}
		if(now)siz[lst][now]=1;
	}
	void dfs(int x)
	{
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			dfs(to1);
			for(int j=1;j<=10;j++)siz[x][j]+=siz[to1][j];
		}
	}
	void build()
	{
		for(int i=2;i<=cnt;i++)add(fa[i],i);dfs(1);
		for(int cas=1;cas<=now;cas++)
			for(int i=1;i<=cnt;i++)flg[i]&=(siz[i][cas]>=L[cas]&&siz[i][cas]<=R[cas]);
	}
	inline ll calc()
	{
		ll ans=0;
		for(int i=2;i<=cnt;i++)if(bel[i]&&flg[i])
			ans+=len[i]-len[fa[i]];
		return ans;
	}
	inline void print(char *s)
	{
		int n=strlen(s+1)-6;
		for(int i=n,rt=1;i;i--)rt=trs[rt][s[i]-'a'];
	}
}
#define N 50005
char s[N],t[N];int n,m,len;
int main()
{
	scanf("%s",t+1);n=strlen(t+1);sam::init();
	for(int i=n;i;i--)sam::insert(t[i]-'a');
	scanf("%d",&m);is_last=0;
	for(int i=1;i<=m;i++)
	{
		now++;scanf("%s%d%d",s+1,&L[now],&R[now]);len=strlen(s+1);sam::lst=1;
		for(int i=len;i;i--)sam::insert(s[i]-'a');
	}sam::build();sam::print(t);
	printf("%lld\n",sam::calc());
}
//ddddddddddddddddddddddddddddddddddddddddddddddddddddddddd