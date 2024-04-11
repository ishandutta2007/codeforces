#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define M 10

int n,m,q;
ll a[N];

std::vector<int> operator * (std::vector<int> &x,std::vector<int> &y){
	std::vector<int> res(m+1);
	for(int i=0;i<=m;i++)
		res[i]=x[y[i]];
	return res;
}

struct node{
	std::vector<int> a[2];
	int tag;
}t[N<<2];
inline void psh(int p){
	std::swap(t[p].a[0],t[p].a[1]);
	t[p].tag^=1;
}
inline void pshd(int p){
	if(t[p].tag)
		psh(p<<1),psh(p<<1|1);
	t[p].tag=0;
}
inline void upd(int p){
	for(int i=0;i<2;i++)
		t[p].a[i]=t[p<<1].a[i]*t[p<<1|1].a[i];
}
inline void build(int p,int L,int R){
	if(L==R){
		for(int i=0;i<2;i++){
			t[p].a[i].resize(m+1);
			for(int j=1;j<=m;j++)
				t[p].a[i][j]=(j+1)%(m+1);
			t[p].a[i][0]=i^(a[L]&1);
		}
		return;
	}
	int mid=(L+R)>>1;
	build(p<<1,L,mid);
	build(p<<1|1,mid+1,R);
	upd(p);
}
inline void rev(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		psh(p);
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	rev(p<<1,L,mid,l,r);
	rev(p<<1|1,mid+1,R,l,r);
	upd(p);
}
inline int qry(int p,int L,int R,int l,int r,int x){
	if(L>r||R<l)
		return x;
	if(l<=L&&R<=r)
		return t[p].a[0][x];
	pshd(p);
	int mid=(L+R)>>1;
	return qry(p<<1,L,mid,l,r,qry(p<<1|1,mid+1,R,l,r,x));
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int op,l,r;
		ll d;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			scanf("%lld",&d);
			if(d&1)
				rev(1,1,n,l,r);
		}
		else
			printf("%d\n",1+(qry(1,1,n,l,r,0)==1));
	}
}