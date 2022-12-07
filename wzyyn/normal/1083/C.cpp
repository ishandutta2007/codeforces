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
const int N=200005;
vector<int> e[N];
int a[N],p[N],fa[N];
int head[N],tot,n,Q;
int sz[N],hson[N],top[N];
int dfn[N],ed[N],dep[N];
void dfs1(int x){
	sz[x]=1;
	dfn[x]=++*dfn;
	for (auto i:e[x]){
		dep[i]=dep[x]+1;
		dfs1(i);
		sz[x]+=sz[i];
		if (sz[i]>sz[hson[x]])
			hson[x]=i;
	}
	ed[x]=*dfn;
}
void dfs2(int x){
	if (!top[x]) top[x]=x;
	if (hson[x]) top[hson[x]]=top[x];
	for (auto i:e[x]) dfs2(i);
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
pii operator +(pii a,int b){
	if (a.fi==-1) return pii(-1,-1);
	int L=LCA(a.fi,a.se);
	if (isfa(L,b)&&(isfa(b,a.fi)||isfa(b,a.se))) return a;
	if (L!=a.fi&&L!=a.se){
		if (isfa(a.fi,b)) return pii(b,a.se);
		if (isfa(a.se,b)) return pii(a.fi,b);
		return pii(-1,-1);
	}
	if (L==a.se) swap(a.fi,a.se);
	if (isfa(a.se,b)) return pii(a.fi,b);
	if (dep[LCA(b,a.se)]<=dep[a.fi]) return pii(b,a.se);
	return pii(-1,-1);
}
pii operator +(pii a,pii b){
	if (a.fi==-1||b.fi==-1) return pii(-1,-1);
	return (a+b.fi)+b.se;
}
pii t[N*4];
void build(int k,int l,int r){
	if (l==r){
		t[k]=pii(p[l],p[l]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p){
	if (l==r){
		t[k]=pii(::p[l],::p[l]);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	t[k]=t[k*2]+t[k*2+1];
}
int ask(int k,int l,int r,pii p){
	//printf("%d %d %d %d %d\n",k,l,r,p.fi,p.se);
	if (l==r) return (p+t[k]).fi==-1?l-1:l;
	int mid=(l+r)/2;
	pii tmp=p+t[k*2];
	if (tmp.fi!=-1) return ask(k*2+1,mid+1,r,tmp);
	return ask(k*2,l,mid,p);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),++a[i];
	For(i,1,n) p[a[i]]=i;
	For(i,2,n) scanf("%d",&fa[i]);
	For(i,2,n) e[fa[i]].PB(i);
	//cerr<<233<<endl;
	dfs1(1);
	//cerr<<233<<endl;
	dfs2(1);
	//cerr<<233<<endl;
	build(1,1,n); 
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d",&tp);
		if (tp==1){
			scanf("%d%d",&x,&y);
			swap(a[x],a[y]);
			swap(p[a[x]],p[a[y]]);
			change(1,1,n,a[x]);
			change(1,1,n,a[y]);
			pii tmp=pii(6,6)+pii(5,5)+pii(1,1);
			//printf("%d %d %d %d\n",p[1],p[2],tmp.fi,tmp.se);
		}
		else
			printf("%d\n",ask(1,1,n,pii(p[1],p[1])));
	}
}