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
const int N=500005;
int n,a[N];
vector<int> op[N];
int pos[N];
pii mx[N*4];
int tg[N*4];
void build(int k,int l,int r){
	mx[k]=pii(0,r-l+1);
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v;
		mx[k].fi+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mx[k]=pii(max(mx[k*2].fi,mx[k*2+1].fi),0);
	if (mx[k].fi==mx[k*2].fi) mx[k].se+=mx[k*2].se;
	if (mx[k].fi==mx[k*2+1].fi) mx[k].se+=mx[k*2+1].se;
	mx[k].fi+=tg[k];
}
void change(int x,int v){
	change(1,0,n,op[x][pos[x]],op[x][pos[x]+1]-1,v);
	if (pos[x]+3<op[x].size()-1)
		change(1,0,n,op[x][pos[x]+3],op[x][pos[x]+4]-1,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) op[i].PB(0);
	For(i,1,n) op[a[i]].PB(i);
	For(i,1,n) op[i].PB(n+1);
	build(1,0,n);
	For(i,1,n){
		pos[i]=0;
		change(i,1);
	}
	ll ans=0;
	For(i,1,n){
		change(1,0,n,i-1,i-1,-233333);
		if (mx[1].fi==n)
			ans+=mx[1].se;
		//cout<<mx[1].fi<<' '<<mx[1].se<<' '<<i<<endl;
		change(a[i],-1);
		++pos[a[i]];
		change(a[i],1);
	}
	cout<<ans<<endl;
}