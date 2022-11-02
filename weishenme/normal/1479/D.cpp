#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
mt19937 rd(time(0));
#define ull unsigned long long
const int N=300005;
int ne[N<<1],fi[N],zz[N<<1],in[N],out[N],sd[N],fa[N][20],rt[N],tot,cnt,x,y,z,l,r,n,q,a[N],id[N];
ull val[N];
vector<pii> V,G;
struct Tree{
	ull num;
	int lson,rson;
}T[N*20];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
inline int pd(int x,int y){
	if (!x)return 1;
	return in[x]<=in[y]&&out[x]>=out[y];
}
inline int lca(int x,int y){
	if (x==y)return x;
	if (sd[x]<sd[y])swap(x,y);
	for (int i=19;i>=0;i--)
		if (!pd(fa[x][i],y))x=fa[x][i];
	return fa[x][0];
}
void dfs(int x,int y){
	fa[x][0]=y;in[x]=++tot;id[tot]=x;
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y){
			sd[zz[i]]=sd[x]+1;
			dfs(zz[i],x);
		}
	out[x]=tot;
}
void insert(int x,int y,int l,int r,int z){
	T[x]=T[y];T[x].num^=val[z];
	if (l==r)return;
	int mid=(l+r)/2;
	if (z<=mid){
		T[x].lson=++cnt;
		insert(T[x].lson,T[y].lson,l,mid,z);
	}
	else {
		T[x].rson=++cnt;
		insert(T[x].rson,T[y].rson,mid+1,r,z);
	}
}
ull find(int x,int L,int R,int l,int r){
	if (!x||L>r||l>R)return 0;
	if (L>=l&&R<=r)return T[x].num;
	int mid=(L+R)/2;
	return find(T[x].lson,L,mid,l,r)^find(T[x].rson,mid+1,R,l,r);
}
void find2(int x,int y,int L,int R,int l,int r){
	if (L>r||l>R)return;
	if (L>=l&&R<=r){
		V.push_back(mp(x,y));
		G.push_back(mp(L,R));
		return;
	}
	int mid=(L+R)/2;
	find2(T[x].lson,T[y].lson,L,mid,l,r);
	find2(T[x].rson,T[y].rson,mid+1,R,l,r);
}
int find3(int x,int y,int l,int r,int z){
	if (l==r)return l;
	int mid=(l+r)/2;
	if (T[T[x].lson].num^T[T[y].lson].num^(z>=l&&z<=mid?val[z]:0))return find3(T[x].lson,T[y].lson,l,mid,z);
	return find3(T[x].rson,T[y].rson,mid+1,r,z);
}
inline int calc(int x,int y,int z,int l,int r){
	return (find(rt[x],1,n,l,r)^find(rt[y],1,n,l,r)^(z>=l&&z<=r?val[z]:0))!=0;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)val[i]=(ull)rd()<<32|rd();
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		jb(x,y);jb(y,x);
	}
	tot=0;
	dfs(1,0);
	for (int i=1;i<=19;i++)
		for (int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	for (int i=1;i<=n;i++)rt[id[i]]=++cnt,insert(rt[id[i]],rt[fa[id[i]][0]],1,n,a[id[i]]);
	while (q--){
		scanf("%d%d%d%d",&x,&y,&l,&r);
		int z=lca(x,y);
		if (!calc(x,y,a[z],l,r))puts("-1");
		else {
			V.clear();
			G.clear();
			find2(rt[x],rt[y],1,n,l,r);
			for (int i=0;i<(int)V.size();i++)
				if (T[V[i].fi].num^T[V[i].se].num^(a[z]>=G[i].fi&&a[z]<=G[i].se?val[a[z]]:0)){
					printf("%d\n",find3(V[i].fi,V[i].se,G[i].fi,G[i].se,a[z]));
					break;
				}
		}
	}
}