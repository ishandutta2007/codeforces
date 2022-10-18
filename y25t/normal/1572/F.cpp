#include<bits/stdc++.h>
#define ll long long
#define N 200005

int n,q;

namespace seg{
	struct node{
		ll sum,add;
	}t[N<<2];
	inline void psh(int p,int L,int R,int d){
		t[p].add+=d;
		t[p].sum+=(R-L+1)*d;
	}
	inline void pshd(int p,int L,int R){
		int mid=(L+R)>>1;
		psh(p<<1,L,mid,t[p].add),psh(p<<1|1,mid+1,R,t[p].add);
		t[p].add=0;
	}
	inline void build(int p,int L,int R){
		if(L==R){
			t[p].sum=1;
			return;
		}
		int mid=(L+R)>>1;
		build(p<<1,L,mid),build(p<<1|1,mid+1,R);
		t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	}
	inline void add(int p,int L,int R,int l,int r,int d){
		if(L>r||R<l)
			return;
		if(l<=L&&R<=r){
			psh(p,L,R,d);
			return;
		}
		pshd(p,L,R);
		int mid=(L+R)>>1;
		add(p<<1,L,mid,l,r,d),add(p<<1|1,mid+1,R,l,r,d);
		t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	}
	inline ll sum(int p,int L,int R,int l,int r){
		if(L>r||R<l)
			return 0;
		if(l<=L&&R<=r)
			return t[p].sum;
		pshd(p,L,R);
		int mid=(L+R)>>1;
		return sum(p<<1,L,mid,l,r)+sum(p<<1|1,mid+1,R,l,r);
	}
}

struct node{
	int mx,cnt,smx;
}t[N<<2];
node operator + (node x,node y){
	node res;
	if(x.mx<y.mx)
		std::swap(x,y);
	res.mx=x.mx;
	res.cnt=x.cnt+(y.mx==x.mx?y.cnt:0);
	res.smx=std::max(x.smx,y.mx==x.mx?y.smx:y.mx);
	return res;
}
inline void pshd(int p){
	t[p<<1].mx=std::min(t[p<<1].mx,t[p].mx);
	t[p<<1|1].mx=std::min(t[p<<1|1].mx,t[p].mx);
}
inline void build(int p,int L,int R){
	if(L==R){
		t[p].mx=L,t[p].cnt=1,t[p].smx=-1;
		return;
	}
	int mid=(L+R)>>1;
	build(p<<1,L,mid),build(p<<1|1,mid+1,R);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline void cmn(int p,int L,int R,int l,int r,int d){
	if(L>r||R<l||d>=t[p].mx)
		return;
	if(l<=L&&R<=r&&d>t[p].smx){
		seg::add(1,1,n,d+1,t[p].mx,-t[p].cnt);
		t[p].mx=d;
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	cmn(p<<1,L,mid,l,r,d),cmn(p<<1|1,mid+1,R,l,r,d);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline void chg(int p,int L,int R,int x,int d){
	if(L==R){
		seg::add(1,1,n,t[p].mx+1,d,1);
		t[p].mx=d;
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	if(x<=mid)
		chg(p<<1,L,mid,x,d);
	else
		chg(p<<1|1,mid+1,R,x,d);
	t[p]=t[p<<1]+t[p<<1|1];
}

int main(){
	scanf("%d%d",&n,&q);
	seg::build(1,1,n),build(1,1,n);
	while(q--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			cmn(1,1,n,1,x,x-1);
			chg(1,1,n,x,y);
		}
		else
			printf("%lld\n",seg::sum(1,1,n,x,y));
	}
}