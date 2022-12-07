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
int n,Q,V,a[N];
struct node{
	ll ans;
	int lc,rc,l,r,all;
	pii vl[22],vr[22];
	node(){
		lc=rc=all=ans=0;
	}
	node(int p,int v){
		ans=(v<V); lc=rc=1;
		vl[1].fi=vr[1].fi=all=v;
		vl[1].se=vr[1].se=l=r=p;
	}
}t[1<<18];
node operator +(node a,node b){
	node c;
	c.l=a.l; c.lc=a.lc;
	c.r=b.r; c.rc=b.rc;
	c.all=a.all|b.all;
	c.ans=a.ans+b.ans;
	memcpy(c.vl,a.vl,sizeof(c.vl));
	memcpy(c.vr,b.vr,sizeof(c.vr));
	for (int i=a.rc,j=0;i;--i){
		for (;j<b.lc&&(a.vr[i].fi|b.vl[j+1].fi)<V;++j);
		c.ans+=1ll*(a.vr[i].se-(i==a.rc?a.l-1:a.vr[i+1].se))*
				   ((j==b.lc?b.r+1:b.vl[j+1].se)-b.l); 
	}
	For(i,1,b.lc)
		if ((a.all|b.vl[i].fi)!=c.vl[c.lc].fi)
			c.vl[++c.lc]=pii(b.vl[i].fi|a.all,b.vl[i].se);
	For(i,1,a.rc)
		if ((b.all|a.vr[i].fi)!=c.vr[c.rc].fi)
			c.vr[++c.rc]=pii(a.vr[i].fi|b.all,a.vr[i].se);
	return c;
}
void build(int k,int l,int r){
	if (l==r){
		t[k]=node(l,a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k]=(node){l,v};
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	t[k]=t[k*2]+t[k*2+1]; 
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d%d",&n,&Q,&V);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(1,1,n,x,y);
		else{
			int len=y-x+1;
			printf("%lld\n",1ll*len*(len+1)/2-ask(1,1,n,x,y).ans);
		}
	}
}