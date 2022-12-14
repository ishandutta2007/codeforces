#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005 , M = 1200005;

int n,Q;

int s[M],sa[M],rnk[M],has[M],tr[M],ht[M],mn[22][M],lg[M],len,maxn = 27;
inline bool cmp(int x,int y,int k){return rnk[x]==rnk[y]&&rnk[x+k]==rnk[y+k];}
void get_sa(int n,int m)
{
	int i,cnt;
	for(i=1;i<=n;i++)has[s[i]]++;
	for(i=1,cnt=0;i<=m;i++)if(has[i])tr[i]=++cnt;
	for(i=1;i<=m;i++)has[i]+=has[i-1];
	for(i=1;i<=n;i++)rnk[i]=tr[s[i]],sa[has[s[i]]--]=i;
	for(int k=1;cnt!=n;k<<=1)
	{
		memset(has,0,sizeof(has));
		for(i=1;i<=n;i++)has[rnk[i]]++;
		for(i=1;i<=n;i++)has[i]+=has[i-1];
		for(i=n;i;i--)if(sa[i]>k)tr[sa[i]-k]=has[rnk[sa[i]-k]]--;
		for(i=n-k+1;i<=n;i++)tr[i]=has[rnk[i]]--;
		for(i=1;i<=n;i++)sa[tr[i]]=i;
		for(i=1,cnt=0;i<=n;i++)tr[sa[i]]=cmp(sa[i],sa[i-1],k)?cnt:++cnt;
		memcpy(rnk,tr,sizeof(tr));
	}
	int j;
	for(i=1;i<=n;i++)
	{
		if(rnk[i]==1)continue;
		for(j=max(1,ht[rnk[i-1]]-1);s[i+j-1]==s[sa[rnk[i]-1]+j-1];j++)ht[rnk[i]]=j;
	}
	for(lg[0]=-1,i=1;i<=n;i++)lg[i]=lg[i>>1]+1,mn[0][i]=ht[i];
	for(i=1;i<22;i++)
		for(j=1;j+(1<<i)-1<=n;j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
}
inline int get_mn(int l,int r){int tmp=lg[r-l+1];return min(mn[tmp][l],mn[tmp][r-(1<<tmp)+1]);}
inline int get_lcp(int x,int y){if(x==y)return len-x+1;x=rnk[x],y=rnk[y];if(x>y)swap(x,y);return get_mn(x+1,y);}

struct node{int to,next;}e[N<<1];
char a[N];int fa[N],cnt,head[N],son[N],siz[N],anc[N],dep[N],pos[N],bac[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs1(int x,int from)
{
	siz[x] = 1 , dep[x] = dep[from] + 1 , fa[x] = from;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs1(to1,x),siz[x]+=siz[to1],siz[son[x]]<siz[to1]?son[x]=to1:0;
	}
}
void dfs2(int x,int top)
{
	anc[x] = top , pos[x] = ++len , s[len] = a[x]-'a'+1;
	if(son[x])dfs2(son[x],top);else s[++len] = ++maxn;
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=fa[x]&&e[i].to!=son[x])
		dfs2(e[i].to,e[i].to);
}
void dfs3(int x,int top)
{
	if(son[x])dfs3(son[x],top);
	else
	{
		for(int t = x;t!=fa[top];t=fa[t])bac[t] = ++len , s[len] = a[t]-'a'+1;
		s[++len] = ++maxn;
	}
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=fa[x]&&e[i].to!=son[x])
		dfs3(e[i].to,e[i].to);
}

int q1[50],l1[50],d1[50],s1,q2[50],l2[50],d2[50],s2;
int get_sum(int x,int y)
{
	int ret=0;
	while(anc[x]!=anc[y])
	{
		if(dep[anc[x]]<dep[anc[y]])swap(x,y);
		x=fa[anc[x]];ret++;
	}
	return ret+1;
}
void get_lca(int *q,int *l,int *d,int x,int y,int all)
{
	int h = 0 , t = all;
	while(anc[x]!=anc[y])
	{
		if(dep[anc[x]]>dep[anc[y]])
			q[++h] = bac[x] , d[h] = 0 , l[h] = dep[x] - dep[anc[x]] + 1 , x = fa[anc[x]];
		else q[t] = pos[anc[y]] , d[t] = 1 , l[t--] = dep[y] - dep[anc[y]] + 1 , y = fa[anc[y]];
	}
	if(dep[x]>dep[y])q[++h] = bac[x] , d[h] = 0 , l[h] = dep[x] - dep[y] + 1;
	else q[++h] = pos[x] , d[h] = 1 , l[h] = dep[y] - dep[x] + 1;
}
int get_ans(int x,int y,int a,int b)
{
	s1 = get_sum(x,y) , s2 = get_sum(a,b);
	get_lca(q1,l1,d1,x,y,s1) , get_lca(q2,l2,d2,a,b,s2);
	int sum = 0;
	for(int i=1,j=1,p1=q1[1],p2=q2[1];i<=s1&&j<=s2;)
	{
		int l = min(l1[i] , l2[j]) , tmp = get_lcp(p1,p2);
		// printf("aaa%d %d %d %d %d %d\n",p1,p2,l,tmp,l1[i],l2[j]);
		if(l<=tmp)
		{
			l1[i] -= l , l2[j] -= l , sum += l;
			p1 += l , p2 += l;
			// printf("%d %d\n",p1,p2);
			if(!l1[i])p1 = q1[++i];
			if(!l2[j])p2 = q2[++j];
		}else return sum + tmp;
	}
	return sum;
}
int main()
{
	scanf("%d%s",&n,a+1);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs1(1,0),dfs2(1,1),dfs3(1,1),get_sa(len,maxn);scanf("%d",&Q);
	for(int a,b,c,d;Q--;printf("%d\n",get_ans(a,b,c,d)))scanf("%d%d%d%d",&a,&b,&c,&d);
}

/*
6
bbbabb
2 1
3 2
4 3
5 2
6 5
1
2 5 3 1
1 5 2 3
5 6 5 6
6 3 4 1
6 2 3 4
2 2 4 5
 */