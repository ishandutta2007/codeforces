#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
struct JIRY_SEG{
	int mx[N*4],smx[N*4];
	int mtg[N*4],mxs[N*4],fa[N];
	ll sum[N*4];
	int get(int x){
		return x==fa[x]?x:fa[x]=get(fa[x]);	
	}
	void build(int k,int l,int r){
		mx[k]=1<<30; smx[k]=0;
		mtg[k]=1<<30; mxs[k]=0;
		if (l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
	}
	void wzp(int k,int v){
		if (mx[k]<=v) return;
		assert(smx[k]<v);
		sum[k]+=1ll*(v-mx[k])*mxs[k];
		mx[k]=v; mtg[k]=v;
	}
	void pushup(int k){
		mxs[k]=0; 
		mx[k]=max(mx[k*2],mx[k*2+1]);
		smx[k]=max(smx[k*2],smx[k*2+1]);
		sum[k]=sum[k*2]+sum[k*2+1];
		mx[k]==mx[k*2]?mxs[k]+=mxs[k*2]:smx[k]=max(smx[k],mx[k*2]);
		mx[k]==mx[k*2+1]?mxs[k]+=mxs[k*2+1]:smx[k]=max(smx[k],mx[k*2+1]);
	}
	void pushdown(int k){
		if (mtg[k]==1<<30) return; 
		wzp(k*2,mtg[k]);
		wzp(k*2+1,mtg[k]);
		mtg[k]=1<<30;
	} 
	void changev(int k,int l,int r,int p){
		if (l==r){
			sum[k]=mx[k];
			mxs[k]=1;
			return;
		}
		pushdown(k);
		int mid=(l+r)/2;
		if (p<=mid) changev(k*2,l,mid,p);
		else changev(k*2+1,mid+1,r,p);
		pushup(k);
	}
	void change(int k,int l,int r,int x,int y,int v){
		if (mx[k]<=v) return;
		if (x<=l&&r<=y&&smx[k]<v)
			return wzp(k,v);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,v);
		if (y>mid) change(k*2+1,mid+1,r,x,y,v);
		pushup(k);
	}
	ll ask(int k,int l,int r,int x,int y){
		//cout<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
		if (l==x&&r==y) return sum[k];
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y);
		return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
	}
	void build(){
		build(1,1,N-1);
	}
	void change(int l,int r,int v){
		///printf("C %d %d %d\n",l,r,v);
		change(1,1,N-1,l,r,v);
	}
	void change(int l){
		///cout<<"C"<<' '<<l<<endl;
		changev(1,1,N-1,l);
	}
	ll ask(int l,int r){
		return ask(1,1,N-1,l,r);
	}
}T1,T2;
set<int> S[3];
void updS(int id,int l,int r){
	auto it=S[0].lower_bound(l);
	for (;it!=S[0].end()&&*it<=r;S[0].erase(it++))
		S[id].insert(*it);
	it=S[3-id].lower_bound(l);
	for (;it!=S[3-id].end()&&*it<=r;S[3-id].erase(it++))
		T1.change(*it),T2.change(*it);
}
int main(){
	int Q;
	scanf("%d",&Q);
	For(i,1,N-1) S[0].insert(i);
	T1.build();
	T2.build();
	while (Q--){
		int tp,l,r,v;
		scanf("%d%d%d",&tp,&l,&r); r--;
		if (tp==2) printf("%lld\n",T1.ask(l,r)+T2.ask(l,r));
		else{
			scanf("%d",&v);
			if (v>0){
				updS(1,l,r);
				T1.change(l,r,v);
			}
			else{
				updS(2,l,r);
				T2.change(l,r,-v);
			}
		}
	}
}
/*
sto jry orz
*/