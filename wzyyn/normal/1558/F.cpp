#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
int n,a[N],p[N],L[N],R[N];
int mx[N*4],tg[N*4];
void build(int k,int l,int r){
	tg[k]=0;
	if (l==r){
		mx[k]=r-(r&1);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v; mx[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mx[k]=max(mx[k*2],mx[k*2+1])+tg[k];
}
int ask(int k,int l,int r,int x,int y){
	if (x>y) return -(1<<30);
	if (x<=l&&r<=y) return mx[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y)+tg[k];
	if (x>mid) return ask(k*2+1,mid+1,r,x,y)+tg[k];
	return max(ask(k*2,l,mid,x,y),ask(k*2+1,mid+1,r,x,y))+tg[k];
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]]=i;
	L[n+1]=n+1; R[0]=0;
	for (int i=n;i>=1;i--)
		L[i]=min(L[i+1],p[i]);
	for (int i=1;i<=n;i++)
		R[i]=max(R[i-1],p[i]);
	build(1,1,n);
	int ans=0;
	for (int i=1;i<n;i++){
		int x=p[i];
		change(1,1,n,x,x,x&1?1:-1);
		if (x!=1) change(1,1,n,1,x-1,1);
		if (x!=n) change(1,1,n,x+1,n,-1);
		ans=max(ans,ask(1,1,n,L[i+1],R[i]));
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
00001110000
00010110000
00101010000

*/