#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
struct AC
{
	int child[26];
	int fail;
}tree[100005];
struct Query
{
	int r,k;
	int id,c;
}qq[200005];
bool cmp(Query a,Query b)
{
	return a.r<b.r;
}
int n,m,B,tot,occur[355][100005],en[100005],pa[100005];
ll num[355],c[100005],sum[355],ans[100005];
char s[100005];
queue<int>q;
struct Tree
{
	struct Edge
	{
		int to;
		int nxt;
	}e[100005];
	int edgenum,head[100005],pa[100005],dfn[100005],pos[100005],ind,size[100005];
	void add(int u,int v)
	{
		e[++edgenum].to=v;
		e[edgenum].nxt=head[u];
		head[u]=edgenum;
	}
	void dfs(int node)
	{
		dfn[node]=++ind;
		pos[ind]=node;
		size[node]=1;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(to==pa[node])continue;
			pa[to]=node;
			dfs(to);
			size[node]+=size[to];
		}
	}
}T1,T2;
void add2(int p,ll val)
{
//	printf("add2 %d %lld [%d,%d]\n",p,val,T1.dfn[p],T1.dfn[p]+T1.size[p]-1);
	c[T1.dfn[p]]+=val,c[T1.dfn[p]+T1.size[p]]-=val;
	sum[(T1.dfn[p]-1)/B+1]+=val,sum[(T1.dfn[p]+T1.size[p]-1)/B+1]-=val;
}
void add(int p,ll val)
{
//	printf("add %d %lld\n",p,val);
	for(int i=1;i*B<=p;i++)num[i]+=val;
	for(int i=p/B*B+1;i<=p;i++)add2(T2.pos[i],val);
}
ll query2(int p)
{
//	printf("query2(%d)",p);
	ll ans=0;
	for(int i=1;i*B<=p;i++)ans+=sum[i];
	for(int i=p/B*B+1;i<=p;i++)ans+=c[i];
//	printf("%lld\n",ans);
	return ans;
}
ll query(int node)
{
//	printf("query(%d)\n",node);
	ll ans=0;
	for(int i=1;i*B<=n;i++)
	{
//		printf("%lld*%lld ",num[i],occur[i][node]);
		ans+=num[i]*occur[i][node];
	}
//	printf("\n");
	ans+=query2(T1.dfn[en[node]]);
	return ans;
}
int ins(char*s,int len)
{
	int x=1;
	for(int i=1;i<=len;i++)
	{
		if(!tree[x].child[s[i]-'a'])tree[x].child[s[i]-'a']=++tot;
		x=tree[x].child[s[i]-'a'];
	}
	return x;
}
void build()
{
	q.push(1);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(!tree[node].child[i])
			{
				if(node==1)tree[node].child[i]=1;
				else tree[node].child[i]=tree[tree[node].fail].child[i];
			}
			else
			{
				pa[tree[node].child[i]]=node;
				if(node==1)tree[tree[node].child[i]].fail=1;
				else tree[tree[node].child[i]].fail=tree[tree[node].fail].child[i];
				q.push(tree[node].child[i]);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	B=350;
	tot=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int len=(int)strlen(s+1);
		en[i]=ins(s,len);
	}
	for(int i=1;i<=tot;i++)
	  for(int j=0;j<26;j++)
		if(tree[i].child[j])
		  T1.add(i,tree[i].child[j]);
	build();
	for(int i=2;i<=tot;i++)
	  T2.add(tree[i].fail,i);
	T1.dfs(1);
	T2.dfs(1);
	for(int i=1;i<=n;i++)
	{
		int node=en[i];
		while(node)
		{
			occur[(T2.dfn[node]-1)/B+1][i]++;
			node=pa[node];
		}
	}
	n=tot;
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		qq[2*i-1].c=-1,qq[2*i-1].id=i,qq[2*i-1].k=k,qq[2*i-1].r=l-1;
		qq[2*i].c=1,qq[2*i].id=i,qq[2*i].k=k,qq[2*i].r=r;
	}
	sort(qq+1,qq+2*m+1,cmp);
	int now=1;
	for(int i=1;i<=2*m;i++)
	{
		while(now<=qq[i].r)
		{
			int l=T2.dfn[en[now]];
			int r=T2.dfn[en[now]]+T2.size[en[now]]-1;
//			printf("[%d,%d]\n",l,r);
			add(r,1);
			add(l-1,-1);
			now++;
		}
//		printf("query(%d)=%lld\n",qq[i].k,query(qq[i].k));
		ans[qq[i].id]+=qq[i].c*query(qq[i].k);
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}