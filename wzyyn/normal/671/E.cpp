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
const ll inf=(1ll<<55);
const int N=100005;
int n,K,ans;
int q[N],qq[N];
vector<int> e[N];
ll d[N],g[N];
ll pre[N],suf[N];
ll mxa[N*4],mxb[N*4];
ll mxc[N*4],tg[N*4];
void addv(int k,ll v){
	mxa[k]+=v;
	mxc[k]+=v;
	tg[k]+=v;
}
void pushdown(int k){
	if (!tg[k]) return;
	addv(k*2,tg[k]);
	addv(k*2+1,tg[k]);
	tg[k]=0;
}
ll calc(int k,int l,int r,ll v){
	if (l==r) return v+mxb[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (v<=mxa[k*2])
		return min(mxc[k],calc(k*2,l,mid,v));
	return min(v+mxb[k*2],calc(k*2+1,mid+1,r,v));
}
void pushup(int k,int l,int r){
	mxa[k]=max(mxa[k*2],mxa[k*2+1]);
	mxb[k]=min(mxb[k*2],mxb[k*2+1]);
	mxc[k]=calc(k*2+1,(l+r)/2+1,r,mxa[k*2]);
}
void build(int k,int l,int r){
	if (l==r){
		mxa[k]=suf[l];
		mxb[k]=-suf[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k,l,r);
}
void change(int k,int l,int r,int x,int y,ll v){
	//if (l==1&&r==n) printf("change %d %d %d\n",x,y,v);
	if (l==x&&r==y){
		addv(k,v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k,l,r);
}
int solve(int k,int l,int r,ll x){
	//printf("solve %d %d %lld\n",l,r,x);
	if (l==r) return x+mxb[k]>K?0:l;
	pushdown(k);
	int mid=(l+r)/2;
	if (x+mxb[k*2+1]<=K)
		return solve(k*2+1,mid+1,r,x);
	return solve(k*2,l,mid,x);
}
int ask(int k,int l,int r,ll x){
	//printf("ask %d %d %d %lld\n",k,l,r,x);
	if (l==r) return x+mxb[k]>K?0:l;
	pushdown(k);
	int mid=(l+r)/2,ans=0;
	if (x>mxa[k*2]) ans=solve(k*2,l,mid,x);
	else if (mxc[k]>K) return ask(k*2,l,mid,x);
	return max(ans,ask(k*2+1,mid+1,r,max(mxa[k*2],x)));
}
void solve(int x){
	//printf("solve %d\n",x);
	qq[++*qq]=x;
	int l=1,r=*qq,pos=n;
	while (l<=r){
		int mid=(l+r)/2;
		if (pre[x]-pre[qq[mid]]>K)
			pos=qq[mid]-1,l=mid+1;
		else r=mid-1;
	}
	if (x-1) change(1,1,n,1,x-1,-inf);
	change(1,1,n,pos,n,inf);
	ans=max(ans,ask(1,1,n,-inf)-x+1);
	if (x-1) change(1,1,n,1,x-1,inf);
	change(1,1,n,pos,n,-inf);
	For(i,0,e[x].size()-1){
		change(1,1,n,x-1,n,pre[e[x][i]]-pre[x]);
		solve(e[x][i]);
		change(1,1,n,x-1,n,-pre[e[x][i]]+pre[x]);
	}
	--*qq;
}
int main(){
	scanf("%d%d",&n,&K);
	For(i,1,n-1) scanf("%d",&d[i]);
	For(i,1,n) scanf("%d",&g[i]);
	For(i,1,n-1) pre[i+1]=pre[i]+g[i]-d[i];
	For(i,1,n-1) suf[i+1]=suf[i]+g[i+1]-d[i];
	build(1,1,n);
	For(i,1,n){
		for (;*q&&pre[i]<pre[q[*q]];--*q)
			e[i].PB(q[*q]);
		q[++*q]=i;
	}
	For(i,1,*q)
		solve(q[i]);
	printf("%d\n",ans);
}