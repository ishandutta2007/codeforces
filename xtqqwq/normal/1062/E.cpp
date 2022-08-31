#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int left,right,max1,max2,min1,min2;
}t[300000];

int n,q,tot,cnt;
int v[200005],nxt[200005],h[100005],dfn[100005],rnk[100005],dep[100005],f[100005][20];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void update(int id){
	if(t[id<<1].max1>t[id<<1|1].max1){
		t[id].max1=t[id<<1].max1;
		if(t[id<<1].max2>t[id<<1|1].max1) t[id].max2=t[id<<1].max2;
		else t[id].max2=t[id<<1|1].max1;
	}
	else{
		t[id].max1=t[id<<1|1].max1;
		if(t[id<<1].max1>t[id<<1|1].max2) t[id].max2=t[id<<1].max1;
		else t[id].max2=t[id<<1|1].max2;
	}
	if(t[id<<1].min1<t[id<<1|1].min1){
		t[id].min1=t[id<<1].min1;
		if(t[id<<1].min2<t[id<<1|1].min1) t[id].min2=t[id<<1].min2;
		else t[id].min2=t[id<<1|1].min1;
	}
	else{
		t[id].min1=t[id<<1|1].min1;
		if(t[id<<1].min1<t[id<<1|1].min2) t[id].min2=t[id<<1].min1;
		else t[id].min2=t[id<<1|1].min2;
	}
}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r,t[id].min1=t[id].min2=1<<30;
	if(l==r){
		t[id].max1=t[id].min1=dfn[l];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

node query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return t[id];
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	node lson=query(id<<1,l,t[id<<1].right),rson=query(id<<1|1,t[id<<1|1].left,r),ret;
	if(lson.max1>rson.max1){
		ret.max1=lson.max1;
		if(lson.max2>rson.max1) ret.max2=lson.max2;
		else ret.max2=rson.max1;
	}
	else{
		ret.max1=rson.max1;
		if(lson.max1>rson.max2) ret.max2=lson.max1;
		else ret.max2=rson.max2;
	}
	if(lson.min1<rson.min1){
		ret.min1=lson.min1;
		if(lson.min2<rson.min1) ret.min2=lson.min2;
		else ret.min2=rson.min1;
	}
	else{
		ret.min1=rson.min1;
		if(lson.min1<rson.min2) ret.min2=lson.min1;
		else ret.min2=rson.min2;
	}
	return ret;
}

void dfs(int u,int fa){
	dfn[u]=++cnt,rnk[cnt]=u;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,f[v[p]][0]=u;
		dfs(v[p],u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main(){
	n=readint(); q=readint();
	int x,y; node now;
	for(int i=2;i<=n;i++){
		x=readint();
		addedge(x,i);
	}
	dfs(1,-1);
	build(1,1,n);
	while(q--){
		x=readint(); y=readint();
		now=query(1,x,y);
		if(dep[lca(rnk[now.min1],rnk[now.max2])]>dep[lca(rnk[now.min2],rnk[now.max1])])
			printf("%d %d\n",rnk[now.max1],dep[lca(rnk[now.min1],rnk[now.max2])]);
		else
			printf("%d %d\n",rnk[now.min1],dep[lca(rnk[now.min2],rnk[now.max1])]);
	}
	return 0;
}