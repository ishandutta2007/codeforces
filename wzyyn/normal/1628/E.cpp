#include<bits/stdc++.h>

using namespace std;

const int N=600005;
int n,Q,nd;
struct edge{
	int x,y,v;
}e[N];
int fa[N],ffa[N],sz[N],co[N];
int dfn[N],pos[N],top[N];
vector<int> E[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool cmp(edge a,edge b){
	return a.v<b.v;
}
void dfs(int x,int tp){
	top[x]=tp;
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	//cout<<"debug "<<x<<' '<<dfn[x]<<' '<<co[x]<<endl;
	int k=0;
	for (auto i:E[x])
		if (sz[i]>sz[k])
			k=i;
	if (k)
		dfs(k,tp);
	for (auto i:E[x])
		if (i!=k)
			dfs(i,i);
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=ffa[top[x]])
		if (top[x]>top[y]) swap(x,y);
	return max(x,y);
}
int mn[N*4],mx[N*4];
int tmn[N*4],tmx[N*4];
int tg[N*4];
void build(int k,int l,int r){
	tg[k]=-1;
	if (l==r){
		mn[k]=mx[k]=dfn[l];
		tmn[k]=1<<30; tmx[k]=-1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	mn[k]=min(mn[k*2],mn[k*2+1]);
	mx[k]=max(mx[k*2],mx[k*2+1]);
	tmn[k]=min(tmn[k*2],tmn[k*2+1]);
	tmx[k]=max(tmx[k*2],tmx[k*2+1]);
}
void cov(int k,int ntg){
	tg[k]=ntg;
	tmn[k]=(ntg?mn[k]:1<<30);
	tmx[k]=(ntg?mx[k]:-1);
}
void pushdown(int k){
	if (tg[k]!=-1){
		cov(k*2,tg[k]);
		cov(k*2+1,tg[k]);
		tg[k]=-1;
	}
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y)
		return cov(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	tmn[k]=min(tmn[k*2],tmn[k*2+1]);
	tmx[k]=max(tmx[k*2],tmx[k*2+1]);
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<n;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	sort(e+1,e+n,cmp);
	for (int i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	nd=n;
	for (int i=1;i<n;i++){
		int x=get(e[i].x);
		int y=get(e[i].y);
		++nd;
		co[nd]=e[i].v;
		fa[nd]=fa[x]=fa[y]=nd;
		ffa[x]=ffa[y]=nd;
		sz[nd]=sz[x]+sz[y];
		E[nd].push_back(x);
		E[nd].push_back(y); 
	}
	dfs(nd,nd);
	build(1,1,n);
	while (Q--){
		int tp,x,y;
		scanf("%d",&tp);
		if (tp==1||tp==2){
			scanf("%d%d",&x,&y);
			change(1,1,n,x,y,tp==1);
		}
		else{
			int x;
			scanf("%d",&x);
			if (tmx[1]==-1) puts("-1");
			else{
				int re=-1;
				int p=LCA(pos[tmn[1]],x);
				if (p>n) re=max(re,co[p]);
				p=LCA(pos[tmx[1]],x);
				if (p>n) re=max(re,co[p]);
				printf("%d\n",re);
			}
		}
	}
}