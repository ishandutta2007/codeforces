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
ll t[N*4][10];
int n,Q,a[N];
struct node{
	int a[10];
	node(){
		For(i,0,9) a[i]=i;
	}
	node operator +(const node &b)const{
		node ans;
		For(i,0,9) ans.a[i]=b.a[a[i]];
		return ans;
	}
}tg[N*4];
void build(int k,int l,int r){
	if (l==r){
		int v=1;
		for (;a[l];a[l]/=10,v*=10)
			t[k][a[l]%10]+=v;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	For(i,0,9) t[k][i]=t[k*2][i]+t[k*2+1][i]; 
}
void work(int k,node a){
	static ll tmp[10];
	memset(tmp,0,sizeof(tmp));
	For(i,0,9) tmp[a.a[i]]+=t[k][i];
	For(i,0,9) t[k][i]=tmp[i];
	tg[k]=tg[k]+a;
}
void pushdown(int k){
	work(k*2,tg[k]);
	work(k*2+1,tg[k]);
	tg[k]=node();
}
void change(int k,int l,int r,int x,int y,node v){
	if (x<=l&&r<=y) return work(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	For(i,0,9) t[k][i]=t[k*2][i]+t[k*2+1][i]; 
}
void ask(int k,int l,int r,int x,int y,ll &ans){
	if (x<=l&&r<=y){
		For(i,0,9) ans+=t[k][i]*i;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) ask(k*2,l,mid,x,y,ans);
	if (y>mid) ask(k*2+1,mid+1,r,x,y,ans);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	while (Q--){
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1){
			int x,y;
			scanf("%d%d",&x,&y);
			node tmp; tmp.a[x]=y;
			change(1,1,n,l,r,tmp);
		}
		else{
			ll ans=0;
			ask(1,1,n,l,r,ans);
			printf("%lld\n",ans);
		}
	}
}