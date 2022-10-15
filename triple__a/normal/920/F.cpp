#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 300000;
typedef long long LL;

LL ans=0;

int divs(int n){
	int ans=0;
	for (int i=1;i<=(int)sqrt(n);++i){
		if (n%i==0){
			ans++;
		}
	}
	ans*=2;
	if ((int)sqrt(n)*(int)sqrt(n)==n) ans--;
	return ans;
}

struct st{
	int l,r;
	LL sum;
	bool fg;
}tree[maxn<<2];

void pushup(int num){
	int tmp=num<<1;
	tree[num].sum=tree[tmp].sum+tree[tmp|1].sum;
	tree[num].fg=tree[tmp].fg&tree[tmp|1].fg;
}

void build(int num,int l,int r){
	tree[num].l=l;
	tree[num].r=r;
	if (l==r){
		scanf("%d",&tree[num].sum);
		if (tree[num].sum<3){
			tree[num].fg=1;
		}
		else{
			tree[num].fg=0;
		}
		return;
	}
	int md=(l+r)>>1,tmp=num<<1;
	build(tmp,l,md);
	build(tmp|1,md+1,r);
	pushup(num);
}

void update(int num,int l,int r){
	if (tree[num].fg){
		return;
	}
	if (tree[num].l==tree[num].r){
		tree[num].sum=divs(tree[num].sum);
		if (tree[num].sum<3){
			tree[num].fg=1;
		}
		return;
	}
	int md=(tree[num].l+tree[num].r)>>1,tmp=num<<1;
	if (l<=md){
		update(tmp,l,r);
	}
	if (r>md){
		update(tmp|1,l,r);
	}
	pushup(num);
}

void query(int num,int l,int r){
	if (l<=tree[num].l&&tree[num].r<=r){
		ans+=tree[num].sum;
		return;
	}
	int md=(tree[num].l+tree[num].r)>>1,tmp=num<<1;
	if (l<=md){
		query(tmp,l,r);
	}
	if (r>md){
		query(tmp|1,l,r);
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u&1){
			update(1,v,w);
		}
		else{
			ans=0;
			query(1,v,w);
			printf("%lld\n",ans);
		}
	}
	return 0;
}