#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

const int N=300005;
int n,h[N],b[N],q[N];
long long f[N];
long long mx[N*4],tg[N*4];
void build(int k,int l,int r){
	mx[k]=-(1ll<<60);
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void add(int k,long long v){
	mx[k]+=v; tg[k]+=v;
}
void pushdown(int k){
	if (!tg[k]) return;
	add(k*2,tg[k]);
	add(k*2+1,tg[k]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,long long v){
	if (x<=l&&r<=y) return add(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&h[i]);
	For(i,1,n) scanf("%d",&b[i]);
	build(1,0,n);
	change(1,0,n,0,0,(1ll<<60));
	int t=1; q[1]=0; h[0]=-1; f[0]=0;
	For(i,1,n){
		for (;h[i]<h[q[t]];--t)
			change(1,0,n,q[t-1],q[t]-1,-b[q[t]]);
		change(1,0,n,q[t],i-1,b[i]);
		f[i]=mx[1];
		change(1,0,n,i,i,(1ll<<60)+f[i]);
		q[++t]=i;
	}
	cout<<f[n]<<endl;
}