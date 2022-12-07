#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
ll P[15];
ll v[N*4],tg[N*4],dif[N*4];
int n,Q;

void setv(int k,ll val){
	v[k]=val; tg[k]=0;
	dif[k]=lower_bound(P+1,P+13,v[k])-P;
	dif[k]=P[dif[k]]-v[k];
}
void addv(int k,ll val){
	dif[k]-=val;
	tg[k]+=val;
}
void pushdown(int k){
	if (v[k]){
		setv(k*2,v[k]);
		setv(k*2+1,v[k]);
		v[k]=0;
	}
	if (tg[k]){
		addv(k*2,tg[k]);
		addv(k*2+1,tg[k]);
		tg[k]=0;
	}	
}
void build(int k,int l,int r){
	if (l==r){
		int v;
		scanf("%d",&v);
		return setv(k,v);
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	dif[k]=min(dif[k*2],dif[k*2+1]);
}
void setv(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y)
		return setv(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) setv(k*2,l,mid,x,y,v);
	if (y>mid) setv(k*2+1,mid+1,r,x,y,v);
	dif[k]=min(dif[k*2],dif[k*2+1]);
}
void addv(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		//printf("%d %d %d\n",k,l,r,v);
		return addv(k,v);
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) addv(k*2,l,mid,x,y,v);
	if (y>mid) addv(k*2+1,mid+1,r,x,y,v);
	dif[k]=min(dif[k*2],dif[k*2+1]);
}
ll query(int k,int l,int r,int p){
	//printf("%d %d %d %d %lld %lld\n",k,l,r,p,v[k],tg[k]);
	if (v[k]) return v[k]+tg[k];
	int mid=(l+r)/2;
	if (p<=mid) return query(k*2,l,mid,p)+tg[k];
	return query(k*2+1,mid+1,r,p)+tg[k];
}
bool check(int k,int l,int r){
	//printf("%d %d %d %lld\n",k,l,r,dif[k]);
	if (dif[k]>0) return 0;
	if (v[k]){
		setv(k,v[k]+tg[k]);
		return dif[k]==0;
	}
	pushdown(k);
	int mid=(l+r)/2;
	bool ans=check(k*2,l,mid)|check(k*2+1,mid+1,r);
	dif[k]=min(dif[k*2],dif[k*2+1]);
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	P[0]=1;
	scanf("%d%d",&n,&Q);
	For(i,1,12) P[i]=42ll*P[i-1];
	build(1,1,n);
	while (Q--){
		int tp,x,y,v;
		scanf("%d%d",&tp,&x);
		if (tp==1)
			printf("%lld\n",query(1,1,n,x));
		if (tp==2){
			scanf("%d%d",&y,&v);
			setv(1,1,n,x,y,v);
		}
		if (tp==3){
			scanf("%d%d",&y,&v);
			addv(1,1,n,x,y,v);
			for (;check(1,1,n);)
				addv(1,1,n,x,y,v);
		}
	}
}