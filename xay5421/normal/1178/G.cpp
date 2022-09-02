// author: xay5421
// created: Mon Nov  8 14:08:16 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,INF=0X3F3F3F3F;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,Q,fa[N],ind,tin[N],tou[N],dfn[N],a[N],b[N];
vector<int>e[N];
struct node{
	int dt;
	LL val;
};
LL calc(const node&a,const node&b){ // a>=b
	if(a.dt>=b.dt)return INFLL;
	return (a.val-b.val)/(b.dt-a.dt)+1;
}
struct segTree{
	node c[N];
	node t[N*4];
	LL rem[N*4],tg[N*4];
	void upd(int k1){
		rem[k1]=min(rem[k1*2],rem[k1*2+1]);
		if(t[k1*2].val<t[k1*2+1].val){
			rem[k1]=min(rem[k1],calc(t[k1*2+1],t[k1*2]));
			t[k1]=t[k1*2+1];
		}else{
			rem[k1]=min(rem[k1],calc(t[k1*2],t[k1*2+1]));
			t[k1]=t[k1*2];
		}
	}
	void pst(int k1,LL k2){
		tg[k1]+=k2;
		rem[k1]-=k2;
		t[k1].val+=t[k1].dt*k2;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
	}
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			t[k1]=c[k2];
			rem[k1]=INFLL;
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void down(int k1,int k2,int k3){
		if(rem[k1]>0)return;
		if(k2==k3)return;
		psd(k1);
		int mid=(k2+k3)>>1;
		down(k1*2,k2,mid),down(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void add(int k1,int k2,int k3,int k4,int k5,LL k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1,k6);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
	LL res;
	void ask(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			if(rem[k1]<=0)down(k1,k2,k3);
			res=max(res,t[k1].val);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
	LL ask(int l,int r){
		res=0;
		ask(1,1,n,l,r);
		return res;
	}
}t1,t2;
void dfs(int k1,int k2){
	tin[k1]=++ind,dfn[ind]=k1;
	t1.c[ind]=(node){abs(b[k1]),1LL*a[k1]*abs(b[k1])};
	t2.c[ind]=(node){-abs(b[k1]),-1LL*a[k1]*abs(b[k1])};
	for(auto x:e[k1]){
		a[x]+=a[k1];
		b[x]+=b[k1];
		dfs(x,k1);
	}
	tou[k1]=ind;
}
int main(){
	rd(n),rd(Q);
	rep(i,2,n){
		rd(fa[i]),e[fa[i]].pb(i);
	}
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);
	dfs(1,0);
	t1.bud(1,1,n),t2.bud(1,1,n);
	while(Q--){
		int opt,v,x;
		rd(opt),rd(v);
		if(opt==1){
			rd(x);
			t1.add(1,1,n,tin[v],tou[v],x);
			t2.add(1,1,n,tin[v],tou[v],x);
		}else{
			LL w1=t1.ask(tin[v],tou[v]);
			LL w2=t2.ask(tin[v],tou[v]);
			printf("%lld\n",max(w1,w2));
		}
	}
	return 0;
}