#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,Q,t[N*4];
int mx[N*4],smx[N*4],mxs[N*4];
struct Tarr{
	long long t[N];
	void add(int k,long long v){
		for (;k<N;k+=k&(-k)) t[k]+=v;
	}
	long long ask(int k){
		long long s=0;
		for (;k;k-=k&(-k)) s+=t[k];
		return s;
	}
}T1,T2;
void change(int x,int y,int v){
	T1.add(x,v);
	T2.add(x,-1ll*v*(x-1));
	T1.add(y+1,-v);
	T2.add(y+1,1ll*v*y);
}
long long ask(int x){
	return 1ll*x*T1.ask(x)+T2.ask(x);
}
void upd(int k,int v){
	if (v<mx[k])
		mx[k]=v;
}
void pushdown(int k){
	if (mx[k*2]>mx[k])
		upd(k*2,mx[k]);
	if (mx[k*2+1]>mx[k])
		upd(k*2+1,mx[k]);
}
void pushup(int k){
	mx[k]=max(mx[k*2],mx[k*2+1]);
	smx[k]=max(mx[k]==mx[k*2]?smx[k*2]:mx[k*2],
			   mx[k]==mx[k*2+1]?smx[k*2+1]:mx[k*2+1]);
	mxs[k]=(mx[k]==mx[k*2]?mxs[k*2]:0)+
		   (mx[k]==mx[k*2+1]?mxs[k*2+1]:0);
}
void build(int k,int l,int r){
	if (l==r){
		mx[k]=l;
		smx[k]=0;
		mxs[k]=1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		if (v>smx[k]){
			if (v<mx[k])
				change(v+1,mx[k],-mxs[k]);
			return upd(k,v);
		}
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	pushup(k);
}
void update(int k,int l,int r,int p,int v){
	if (l==r){
		change(p,mx[k],-1);
		change(p,v,1);
		mx[k]=v;
		mxs[k]=1;
		smx[k]=0;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) update(k*2,l,mid,p,v);
	else update(k*2+1,mid+1,r,p,v);
	pushup(k);
}
int main(){
	scanf("%d%d",&n,&Q);
	build(1,1,n);
	change(1,n,1);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			if (x!=1)
				change(1,1,n,1,x-1,x-1);
			update(1,1,n,x,y);
		}
		else{
			printf("%lld\n",ask(y)-ask(x-1));
		}
	} 
}