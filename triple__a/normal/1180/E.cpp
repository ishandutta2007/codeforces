#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxm=1000000;
const int maxn=300007;
const int INF=1e9;

int n,m;
int a[maxn],b[maxn];

struct st{
	int l,r,mx,lz;
}tree[(maxm<<2)+7];

void pushup(int num){
	tree[num].mx=max(tree[num<<1].mx,tree[num<<1|1].mx);
}

void pushdown(int num){
	if (tree[num].lz){
		tree[num<<1].lz+=tree[num].lz;
		tree[num<<1|1].lz+=tree[num].lz;
		tree[num<<1].mx+=tree[num].lz;
		tree[num<<1|1].mx+=tree[num].lz;
		tree[num].lz=0;
	}
}

void build(int num,int l,int r){
	tree[num].l=l;
	tree[num].r=r;
	tree[num].mx=tree[num].lz=0;
	if (l==r){
		return;
	}
	int md=(l+r)>>1;
	build(num<<1,l,md);
	build(num<<1|1,md+1,r);
	pushup(num);
}

void update(int num,int l,int r,int u){
	if (l<=tree[num].l&&tree[num].r<=r){
		tree[num].mx+=u;
		tree[num].lz+=u;
		return;
	} 
	pushdown(num);
	int md=(tree[num].l+tree[num].r)>>1;
	if (l<=md) update(num<<1,l,r,u);
	if (r>md) update(num<<1|1,l,r,u);
	pushup(num);
}

int query(int num,int l,int r){
	if (l<=tree[num].l&&tree[num].r<=r){
		return tree[num].mx;
	}
	pushdown(num);
	int md=(tree[num].l+tree[num].r)>>1,ans=-INF;
	if (l<=md) ans=max(ans,query(num<<1,l,r));
	if (r>md) ans=max(ans,query(num<<1|1,l,r));
	pushup(num);
	return ans;
}

int get_ans(){
	if (query(1,1,maxm)<=0) return -1;
	int l=1,r=maxm,md=(l+r)>>1;
	while(l!=r){
		md=(l+r)>>1;
		if (query(1,md+1,r)>0){
			l=md+1;
		}
		else{
			r=md;
		}
	}
	return l;
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,maxm);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		update(1,1,a[i],1);
	}
	for (int i=1;i<=m;++i){
		scanf("%d",&b[i]);
		update(1,1,b[i],-1);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u==1){
			update(1,1,a[v],-1);
			update(1,1,w,1);
			a[v]=w;
			printf("%d\n",get_ans());
		}
		else{
			update(1,1,b[v],1);
			update(1,1,w,-1);
			b[v]=w;
			printf("%d\n",get_ans());
		}
	}
	return 0;
}