#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,B=450;
int n,Q,a[N],b[N];
struct q_node{
	int l,r;
	bool operator<(const q_node&rhs)const{
		if(l/B!=rhs.l/B){
			return l<rhs.l;
		}
		return l/B&1?r<rhs.r:r>rhs.r;
	}
}q[N];
int ql=1,qr=0,first[N],last[N],pre[N],nex[N],rb[N];
void umax(int&x,int y){if(x<y)x=y;}
void push_f(int x){
	first[a[x]]=x;
	if(!last[a[x]])last[a[x]]=x;
	umax(rb[x],last[a[x]]);
}
void push_b(int x){
	last[a[x]]=x;
	if(!first[a[x]])first[a[x]]=x;
	umax(rb[first[a[x]]],x);
}
void pop_f(int x){
	if(first[a[x]]==last[a[x]]){
		first[a[x]]=last[a[x]]=0;
	}else{
		first[a[x]]=nex[first[a[x]]];
	}
}
void pop_b(int x){
	if(first[a[x]]==last[a[x]]){
		first[a[x]]=last[a[x]]=0;
	}else{
		last[a[x]]=pre[last[a[x]]];
	}
}
struct seg{
	int l,r;
	seg(){}
	seg(int l,int r):l(l),r(r){}
	seg operator|(const seg&rhs)const{
		if(l>r)return rhs;
		if(rhs.l>rhs.r)return *this;
		return seg(min(l,rhs.l),max(r,rhs.r));
	}
}tr[N*4];
void update(int u){tr[u]=tr[u<<1]|tr[u<<1|1];}
void build(int u,int l,int r){
	if(l==r){
		tr[u]=seg(1,0);
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	update(u);
}
void modify(int u,int l,int r,int p,int x,int y){
	if(l==r){
		tr[u]=seg(x,y);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modify(u<<1,l,mid,p,x,y);
	else modify(u<<1|1,mid+1,r,p,x,y);
	update(u);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&Q);
		rep(i,1,n)scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		rep(i,1,n)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
		vector<int>lst(n+1);
		rep(i,1,n){
			pre[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		lst.assign(n+1,0);
		per(i,n,1){
			nex[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		rep(i,1,Q)scanf("%d%d",&q[i].l,&q[i].r);
		sort(q+1,q+1+Q);
		fill(first+1,first+n+1,0);
		fill(last+1,last+n+1,0);
		fill(rb+1,rb+n+1,0);
		ql=1,qr=0;
		rep(i,1,Q){
			while(ql<=qr&&ql<q[i].l){
				pop_f(ql++);
			}
			while(ql<=qr&&qr>q[i].r){
				pop_b(qr--);
			}
			if(ql>qr){
				ql=q[i].l,qr=q[i].l-1;
			}
			while(ql>q[i].l){
				push_f(--ql);
			}
			while(qr<q[i].r){
				push_b(++qr);
			}
		}
		build(1,1,n);
		rep(i,1,n){
			if(rb[i]==i)rb[i]=0;
			if(rb[i]){
				modify(1,1,n,i,i,pre[rb[i]]);
			}
		}
		int ans=tr[1].r-tr[1].l+1;
		rep(i,1,n)if(rb[i]){
			modify(1,1,n,i,nex[i],rb[i]);
			ans=min(ans,tr[1].r-tr[1].l+1);
		}
		printf("%d\n",ans);
	}
}