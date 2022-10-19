using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define pb(x) push_back(x)
#define N 400005
int ne[N],to[N],fir[N],C[N],cnt=0;
//For the edges in the MST.
bool in[N],flag,debug=0;

int st[N][20],mx[N][20],F[N],n,m;

struct edge{
	int from,to,id,val;
	friend bool operator <(edge x,edge y) {
		return x.val<y.val;
	}
}E[N];

int pos[N],x,y,z,ans[N],fa[N],par[N],de[N];




void add(int x,int y,int z,int id) {
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;C[cnt]=z;pos[cnt]=id;
}


void init() {
	for(int i=1;i<=n;i++) {
		fa[i]=par[i]=i;
	}	
}
int getf(int x) {
	return x==fa[x]?x:fa[x]=getf(fa[x]);
}
int getp(int x) {
	return x==par[x]?x:par[x]=getp(par[x]);
}


void dfs(int x,int f,int d,int id) {
	if(debug)cout<<x<<" "<<f<<endl;
	st[x][0] = f; mx[x][0]= d ;de[x]= de[f] + 1 ;F[x]= id ;
	for(int i= 1 ;i<= 18 ;i ++ ) {
		st[x][i]=st[st[x][i-1]][i-1];
		mx[x][i]=max(mx[st[x][i-1]][i-1],mx[x][i-1]);
	}
	forw(i,x) {
		int V=to[i];if(V==f) continue;
		dfs(V,x,C[i],pos[i]);
	}
}


int MAX(int x,int y,int z) {
	return max(max(z,y),x);
}
int LCA(int x,int y,int &d) {
	if(x==y) {
		d=0;return (x+y)>>1;
	}
	if(de[x]>de[y]) swap(x,y);
	for(int i=18;i>=0;i--) {
		if(de[st[y][i]]>=de[x]) d=max(d,mx[y][i]),y=st[y][i];
	}
	if(x==y) {
		return (x+y)>>1;
	}
	for(int i=18;i>=0;i--) {
		if(st[x][i]!=st[y][i]) {
			d=MAX(mx[x][i],mx[y][i],d);
			x=st[x][i];y=st[y][i];
		}
	}
	d=MAX(d,mx[x][0],mx[y][0]);
	return (st[x][0]+st[y][0])>>1;
}
void chg(int x,int y,int z) {
	int a;int lca=LCA(x,y,a);
	while(x!=lca) {
		ans[F[x]]=min(ans[F[x]],z);
		par[getp(x)]=getp(st[x][0]);
		x=getp(x);if(de[x]<=de[lca])break;
	}
	while(y!=lca) {
		ans[F[y]]=min(ans[F[y]],z);
		par[getp(y)]=getp(st[y][0]);
		y=getp(y);
		if(de[y]<=de[lca])break;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		E[i].from=x;E[i].to=y;E[i].id=i;E[i].val=z;
	}
	sort(E+1,E+m+1);
	init();
	for(int i=1;i<=m;i++) {
		int x=E[i].from,y=E[i].to,z=E[i].val,id=E[i].id;
		if (debug) cout<<x<<' '<<y<<' '<<z<<' '<<id<<endl;
		if(getf(x)!=getf(y)) {
			fa[getf(x)]=getf(y);
			add(x,y,z,id);add(y,x,z,id);in[id]=1;ans[id]=2e9+1e8+4e7;
		}
	}
	dfs(1,0,0,0);
	for(int i=1;i<=m;i++) {
		if(!in[E[i].id]) {
			chg(E[i].from,E[i].to,E[i].val);
		}
	}
	for(int i=1;i<=m;i++) {
		if(!in[E[i].id]) {
			int d=0;
			LCA(E[i].from,E[i].to,d);
			ans[E[i].id]=d;
		}
	}
	for(int i=1;i<=m;i++) {
		if(ans[i]>2e9) {
			printf("-1 ");
		}
		else printf("%d ",ans[i]-1);
	}
}