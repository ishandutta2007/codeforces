#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
struct AC
{
	int child[2];
	int fail;
}tree[55];
int g,n,m,now,root=1,tot=1,a[105],b[105],c[105];
bool flag[55];
int s[55],tmp[105];
ll f[205][55][55];
queue<int>q;
void ins(int len)
{
	int cur=root;
	for(int i=1;i<=len;i++)
	{
		if(!tree[cur].child[s[i]])tree[cur].child[s[i]]=++tot;
		if(flag[cur])flag[tree[cur].child[s[i]]]=1;
		cur=tree[cur].child[s[i]];
	}
	flag[cur]=1;
}
void build_AC()
{
	q.push(root);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		if(flag[tree[node].fail])flag[node]=1;
		for(int k=0;k<2;k++)
		{
			if(!tree[node].child[k])
			{
				if(node==root)tree[node].child[k]=node;
				else tree[node].child[k]=tree[tree[node].fail].child[k];
			}
			else
			{
				if(node==root)tree[tree[node].child[k]].fail=node;
				else tree[tree[node].child[k]].fail=tree[tree[node].fail].child[k];
				q.push(tree[node].child[k]);
			}
		}
	}
}
bool merge(int x,int y,int z)
{
	bool res=0;
	for(int i=1;i<=tot;i++)
	{
		if(flag[i])continue;
		for(int j=1;j<=tot;j++)
		{
			if(flag[j]||f[x][i][j]==-1)continue;
			for(int k=1;k<=tot;k++)
			{
				if(flag[k]||f[y][j][k]==-1)continue;
				if(f[z][i][k]==-1||f[z][i][k]>f[x][i][j]+f[y][j][k])
				{
					f[z][i][k]=f[x][i][j]+f[y][j][k];
					res=1;
				}
			}
		}
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&g,&n,&m);
	now=n;
	for(int i=1;i<=n;i++)
	{
		int aa,k;
		scanf("%d%d",&aa,&k);
		for(int j=1;j<=k;j++)scanf("%d",&tmp[j]);
		while(k>2)
		{
			now++;
			a[now]=now+2,b[now]=tmp[k-1],c[now]=tmp[k];
			tmp[--k]=now+2;
		}
		a[i]=aa,b[i]=tmp[1],c[i]=k==2?tmp[2]:200;
	}
	while(m--)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)scanf("%d",&s[i]);
		ins(k);
	}
	build_AC();
	memset(f,-1,sizeof(f));
	for(int i=1;i<=tot;i++)
	{
		if(flag[i])continue;
		if(flag[tree[i].child[0]]==0)f[0][i][tree[i].child[0]]=1;
		if(flag[tree[i].child[1]]==0)f[1][i][tree[i].child[1]]=1;
	}
	for(int i=1;i<=tot;i++)
	  if(!flag[i])f[200][i][i]=0;
	bool ff=1;
	while(ff)
	{
		ff=0;
		for(int i=1;i<=now;i++)ff|=merge(b[i],c[i],a[i]);
	}
//	for(int i=0;i<g;i++)
//	{
//		printf("i=%d:\n",i);
//		for(int x=1;x<=tot;x++)
//		{
//			for(int y=1;y<=tot;y++)
//			  printf("%lld ",f[i][x][y]);
//			printf("\n");
//		}
//	}
	for(int i=2;i<g;i++)
	{
		ll ans=-1;
		for(int j=1;j<=tot;j++)
		{
			if(flag[j]||f[i][1][j]==-1)continue;
			if(ans<0)ans=f[i][1][j];
			else ans=min(ans,f[i][1][j]);
		}
		if(ans==-1)printf("YES\n");
		else printf("NO %lld\n",ans);
	}
	return 0;
}