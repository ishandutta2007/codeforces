#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
struct edge{
	int to,nxt;
}ed[N<<1];
int h[N],cnt;
void add(int u, int v){
	ed[++cnt]={v,h[u]};
	h[u]=cnt;
}
int n,m;
int dep[N],f[N],sz[N],son[N],topp[N],st[N],en[N],id[N],dfn;
void dfs1(int x, int fa){
	sz[x]=1;
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		dep[v]=dep[x]+1; f[v]=x;
		dfs1(v,x);
		sz[x]+=sz[v];
		son[x]=(sz[son[x]]<sz[v]?v:son[x]);
	}
	return;
}
void dfs2(int x, int fa, int tp){
	topp[x]=tp;
    st[x]=++dfn;
    id[dfn]=x;
	if(son[x])dfs2(son[x],x,tp);
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa || v==son[x]) continue;
		dfs2(v,x,v);
	}
	en[x]=dfn;
	return;
}
struct node{
	int sum,mx;
	friend node operator+(const node &x, const node &y){
		return {x.sum+y.sum,max(x.mx+y.sum,y.mx)};
	}
};
struct Segment_Tree{
	node sum[N<<2];
	int tag[N<<2];
	void pushup(int rt){
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
		return;
	}
	void pushdown(int rt){
		if(!tag[rt])return;
		tag[rt<<1]=tag[rt<<1|1]=1;
		sum[rt<<1]=sum[rt<<1|1]={0,0};
		tag[rt]=0;
	}
	void build(int rt, int l, int r){
		sum[rt]={0,0}; tag[rt]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	void upd2(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			sum[rt]={0,0};
			tag[rt]=1;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(L<=mid)upd2(rt<<1,l,mid,L,R);
		if(R>mid)upd2(rt<<1|1,mid+1,r,L,R);
		pushup(rt);
	}
	void upd1(int rt, int l, int r, int x, int val){
		if(l==r){
			sum[rt]={val,dep[id[l]]+val};
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(x<=mid)upd1(rt<<1,l,mid,x,val);
		else upd1(rt<<1|1,mid+1,r,x,val);
		pushup(rt); 
	}
	node findmx(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R)return sum[rt];
		pushdown(rt);
		int mid=(l+r)>>1;
		if(R<=mid)return findmx(rt<<1,l,mid,L,R);
		if(L>mid)return findmx(rt<<1|1,mid+1,r,L,R);
		return findmx(rt<<1,l,mid,L,R)+findmx(rt<<1|1,mid+1,r,L,R);
	}
}tr;
int calc(int x){
	node res={0,0};
	int tpx=topp[x];
	while(x){
		res=tr.findmx(1,1,n,st[tpx],st[x])+res;
		x=f[tpx];
		tpx=topp[x];
	}
	return res.mx;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(x,i);
		add(i,x);
	}
	dfs1(1,0); dfs2(1,0,1);
	while(m--){
		int ope,x;
		scanf("%d%d",&ope,&x);
			if(ope==1){
				tr.upd1(1,1,n,st[x],tr.findmx(1,1,n,st[x],st[x]).sum+1);
			}
			if(ope==2){
				tr.upd2(1,1,n,st[x],en[x]);
				int tmp=calc(x);
				if(tmp>=dep[x]+1)tr.upd1(1,1,n,st[x],dep[x]-tmp);
			}
			if(ope==3){
				puts(calc(x)>=dep[x]+1?"black":"white");
			}
	}
	return 0;
}