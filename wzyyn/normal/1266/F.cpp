#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=500005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,mxv,rt;
int vis[N],sum[N],qq[N],deg[N];
int fa[N],sz[N],ans[N];
pii mx1[N],mx2[N],q[N*4];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	mx1[x]=mx2[x]=pii(0,x);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dfs(e[i].to);
			pii tmp(mx1[e[i].to].fi+1,e[i].to);
			if (tmp>mx1[x]) swap(mx1[x],tmp);
			if (tmp>mx2[x]) swap(mx2[x],tmp);
		}
}
void dfs2(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			pii tmp((mx1[x].se==e[i].to?mx2[x]:mx1[x]).fi+1,x);
			if (tmp>mx1[e[i].to]) swap(mx1[e[i].to],tmp);
			if (tmp>mx2[e[i].to]) swap(mx2[e[i].to],tmp);
			dfs2(e[i].to);
		}
}
int Func(int x,int y){
	return mx1[x].se==y?mx2[x].fi:mx1[x].fi;
}

void dfs(int x,int fa,int n){
	sz[x]=1;
	int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			dfs(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	mx=max(mx,n-sz[x]);
	if (mx<mxv) mxv=mx,rt=x;
}
void solve(int x,int n){
	//printf("%d %d\n",x,n);
	mxv=1<<30;
	dfs(x,0,n);
	vis[x=rt]=1;
	int top=0;
	for (int i=head[x];i;i=e[i].next){
		q[++top]=pii(Func(e[i].to,x)+1,0);
		if (!vis[e[i].to]){
			sum[e[i].to]=0;
			for (int j=head[e[i].to];j;j=e[j].next)
				q[++top]=pii(Func(e[j].to,e[i].to)+1,e[i].to);
		}
	}
	sort(q+1,q+top+1);
	int tg=-2,mx=0;
	Rep(i,top,1){
		if (q[i].se==0) ++tg;
		else mx=max(mx,++sum[q[i].se]);
		ans[q[i].fi*2]=max(ans[q[i].fi*2],tg+mx);
	}
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to])
			solve(e[i].to,(sz[e[i].to]>sz[x]?n-sz[x]:sz[e[i].to]));
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		deg[x]++; deg[y]++;
	}
	For(i,1,n)
		ans[1]=max(ans[1],deg[i]+1);
	ans[n]=max(ans[n],1);
	ans[n-1]=max(ans[n-1],1);
	dfs(1); dfs2(1);
	For(i,1,n){
		*qq=0;
		for (int j=head[i];j;j=e[j].next)
			qq[++*qq]=Func(e[j].to,i)+1;
		sort(qq+1,qq+*qq+1);
		For(j,1,*qq){
			ans[2*qq[j]]=max(ans[2*qq[j]],(*qq)-j+1);
			ans[2*qq[j]-1]=max(ans[2*qq[j]-1],(*qq)-j+1+(j!=1&&qq[j-1]==qq[j]-1));
			if (j!=(*qq)&&qq[j]!=qq[j+1])
				ans[2*qq[j]+1]=max(ans[2*qq[j]+1],(*qq)-j+1);
		}
	}
	solve(1,n);
	Rep(i,n,1)
		ans[i]=max(ans[i],ans[i+2]);
	For(i,1,n) printf("%d ",ans[i]);
}
/*
11
1 11
11 2
1 3
3 4
1 5
5 6
2 7
7 8
2 9
9 10
*/