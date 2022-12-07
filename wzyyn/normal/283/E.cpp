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
int n,m,a[N],S[N];
vector<pii> vec[N];
int t[N*4][2],rev[N*4];
void rever(int k){
	swap(t[k][0],t[k][1]);
	rev[k]^=1;
}
void pushdown(int k){
	if (!rev[k]) return;
	rever(k*2);
	rever(k*2+1);
	rev[k]=0;
}
void build(int k,int l,int r){
	t[k][1]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y)
		return rever(k);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y);
	if (y>mid) change(k*2+1,mid+1,r,x,y);
	t[k][0]=t[k*2][0]+t[k*2+1][0];
	t[k][1]=t[k*2][1]+t[k*2+1][1];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	build(1,1,n);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		x=lower_bound(a+1,a+n+1,x)-a;
		y=lower_bound(a+1,a+n+1,y+1)-a-1;
		if (x>y) continue;
		S[x]^=1; S[y+1]^=1;
		vec[x].PB(pii(x,y));
		vec[y+1].PB(pii(x,y));
	}
	ll ans=1ll*n*(n-1)*(n-2)/6;
	For(i,1,n){
		S[i]^=S[i-1];
		for (auto j:vec[i])
			change(1,1,n,j.fi,j.se);
		int v=t[1][1];
		change(1,1,n,i,i);
		v=min(v,t[1][1]);
		ans-=1ll*v*(v-1)/2; 
	}
	printf("%lld\n",ans);
}