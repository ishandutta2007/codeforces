#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=200005;
char s[N],t[N];
int n,Q,l[N],r[N];
int tg[N*4],v[N*4],sz[N*4];
void color(int k,int c){
	tg[k]=c; v[k]=c*sz[k];
}
void pushdown(int k){
	if (tg[k]==-1) return;
	color(k*2,tg[k]);
	color(k*2+1,tg[k]);
	tg[k]=-1;
}
void build(int k,int l,int r){
	tg[k]=-1; sz[k]=r-l+1;
	if (l==r) return color(k,t[l]-'0');
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	v[k]=v[k*2]+v[k*2+1];
}
void change(int k,int l,int r,int x,int y,int c){
	if (x<=l&&r<=y) return color(k,c);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,c);
	if (y>mid) change(k*2+1,mid+1,r,x,y,c);
	v[k]=v[k*2]+v[k*2+1];
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return v[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
void solve(){
	scanf("%d%d",&n,&Q);
	scanf("%s%s",s+1,t+1);
	For(i,1,Q) scanf("%d%d",&l[i],&r[i]);
	build(1,1,n);
	Rep(i,Q,1){
		int s=ask(1,1,n,l[i],r[i]);
		if (2*s==r[i]-l[i]+1)
			return puts("NO"),void(0);
		if (2*s<r[i]-l[i]+1)
			change(1,1,n,l[i],r[i],0);
		else change(1,1,n,l[i],r[i],1);
	}
	For(i,1,n)
		if ((s[i]=='1')!=(ask(1,1,n,i,i)==1))
			return puts("NO"),void(0);
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}