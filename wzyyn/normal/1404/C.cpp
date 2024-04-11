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

const int N=300005;
int n,Q,a[N],ans[N];
vector<pii> op[N];
pii mn[N*4];
int tg[N*4];
int t[N*4];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
void pushdown(int k){
	tg[k*2]+=tg[k];
	tg[k*2+1]+=tg[k];
	mn[k*2].fi+=tg[k];
	mn[k*2+1].fi+=tg[k];
	tg[k]=0;
}
void build(int k,int l,int r){
	mn[k]=pii(1<<30,l);
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v;
		mn[k].fi+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mn[k]=min(mn[k*2],mn[k*2+1]);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		op[l].PB(pii(n-r,i));
	}
	build(1,1,n);
	Rep(i,n,0){
		for (auto j:op[i])
			ans[j.se]=ask(j.fi);
		if (!i) break;
		int v=(a[i]>i?1<<30:i-a[i]);
		change(1,1,n,i,i,v-(1<<30));
		for (;mn[1].fi<=0;){
			int p=mn[1].se;
			change(p,1);
			change(1,1,n,p,n,-1);
			change(1,1,n,p,p,(1<<30));
		}
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}