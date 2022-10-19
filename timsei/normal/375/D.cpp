using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 200001
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define r(x) scanf("%d",&x)
int L[N],R[N];
int K[N],S[N],num[N];
int color[N];
struct query{
	int l,r;
	int lp,rp;
	int K;
	int no;
}Q[N];
int pos[N];
int knum,sz;
int n,m;
int cnt,ne[N*2],to[N*2],fir[N];
int fa[N];
int x,y,z;
int dfn;
int no[N];
int col[N];
int ans[N];
bool cmp(query x,query y)
{
	return x.l==y.l?x.r<y.r:x.l<y.l;
}
void add(int x,int y)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;
}
void dfs(int x,int f)
{
	fa[x]=f;
	L[x]=++dfn;
	no[x]=dfn;
	forw(i,x)
	{
		if(to[i]!=f)
		dfs(to[i],x);
	}
	R[x]=dfn;
}
int maxc=0;
int main()
{
	r(n);r(m);
	for(int i=1;i<=n;i++) r(color[i]);
	for(int i=1;i<=n-1;i++)
	{
		r(x);r(y);
		add(x,y);add(y,x);
	}
	sz=(int)sqrt(n);
	knum=n/sz;
	int l=0;
	for(int i=1;i<=knum-1;i++)
	{
		for(int j=1;j<=sz;j++)
		{
			l++;pos[l]=i;
		}
	}
	l++;
	for(;l<=n;l++)pos[l]=knum;
	dfs(1,0);
	for(int i=1;i<=n;i++) col[no[i]]=color[i];
	for(int i=1;i<=n;i++) maxc=max(maxc,col[i]);
	for(int i=1;i<=m;i++)
	{
		r(x);Q[i].l=L[x];Q[i].r=R[x];Q[i].lp=pos[L[x]];Q[i].rp=pos[R[x]];r(Q[i].K);Q[i].no=i;
	}
	sort(Q+1,Q+m+1,cmp);
	l=1;int r=0;
	for(int i=1;i<=m;i++)
	{
		while(l>Q[i].l){l--;num[col[l]]++;S[num[col[l]]]++;}
		while(r<Q[i].r){r++;num[col[r]]++;S[num[col[r]]]++;}
		while(l<Q[i].l){S[num[col[l]]]--;num[col[l]]--;l++;}
		while(r>Q[i].r){S[num[col[r]]]--;num[col[r]]--;r--;}
		ans[Q[i].no]=S[Q[i].K];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}