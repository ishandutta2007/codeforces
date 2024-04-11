using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define N 1000001
#define Mm 4000001
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D(i,a,b) for(int i=a;i>=b;i--)
#define bs(v) v.size()
#define r(x) scanf("%d",&x)
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
vector<int>e[N];
int H[N];
int n,m;
int dfn[N],low[N];
bool die[N],god[N];
int l,r;
struct node
{
	int from,to,w,no;
}xx[Mm];
int x,y,w;
bool vis[N];
bool cmp(node x,node y){return x.w<y.w;}
int fa[N],fir[N],ne[Mm],to[Mm];
int getf(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=getf(fa[x]);
}
void newnode(int x)
{
	fir[x]=0;
	vis[x]=0;
	dfn[x]=0;
	low[x]=0;
}
int cnt=1;
void add(int xx,int yy)
{
	ne[++cnt]=fir[xx];fir[xx]=cnt;to[cnt]=yy;
}
void dfs(int no,int fae,int dis)
{
	dfn[no]=dis;
	vis[no]=1;
	low[no]=dis;
	forw(i,no)
	{
		if(!vis[to[i]])
		{
			dfs(to[i],i,dis+1);
			low[no]=min(low[no],low[to[i]]);
			if(dfn[no]<low[to[i]])
			{
				god[H[i]]=1;
			}
		}
		else
		{
			if(i!=(fae^1))
			{
				low[no]=min(low[no],dfn[to[i]]);
			}
		}
	}
	return;
}
int tot;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int z;
		r(x);r(y);r(z);
		xx[i].from=x;
		xx[i].to=y;
		xx[i].w=z;
		xx[i].no=i;
	}
	sort(xx+1,xx+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	l=1,r=1;
	while(l<=m)
	{
		if(tot==n-1)
		{
			for(int i=l;i<=m;i++) die[xx[i].no]=1;break;
		}
		while(xx[l].w==xx[r].w&&r<=m) r++;
		r--;
		cnt=1;
		F(i,l,r)
		{
			int lf=xx[i].from,lt=xx[i].to;
			lf=getf(lf);lt=getf(lt);
			if(lf==lt){die[xx[i].no]=1;continue;}
			newnode(lf);newnode(lt);	
		}
		F(i,l,r)
		{
			int lf=xx[i].from,lt=xx[i].to;
			lf=getf(lf);lt=getf(lt);
			if(lf==lt)continue;
			add(lf,lt);
			H[cnt]=xx[i].no;
			add(lt,lf);
			H[cnt]=xx[i].no;
		}
		F(i,l,r)
		{
			int lf=xx[i].from,lt=xx[i].to;
			lf=getf(lf);lt=getf(lt);
			if(lf!=lt&&!vis[lf]&&!vis[lt])
			{
				dfs(lf,-1,1);
			}
		}
		F(i,l,r)
		{
			int lf=xx[i].from,lt=xx[i].to;
			lf=getf(lf);lt=getf(lt);
			if(lf!=lt) 
			{
				tot++;
				fa[getf(lf)]=getf(lt);
			}
		}
		l=r+1;r=l;
	}
	F(i,1,m)
	{
		if(die[i]) puts("none");
		else if(god[i]) puts("any");
		else puts("at least one");
	}
}