#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL INF = 1e12;
const int N = 1e5+5;
 
LL a[N],s[N],sum[N];
LL tr[(1<<18)+5], lz[(1<<18)+5];
int n,q,x,y;
char ch;
 
void build(int i=1, int l=1, int r=n) {
	lz[i] = -INF;
	if(l==r) {
		tr[i]=a[l];
		return;
	}
	int m=l+r>>1;
	build(i<<1, l, m);
	build(i<<1|1, m+1, r);
	tr[i]=tr[i<<1]+tr[i<<1|1];
}
 
void app(int i, LL a, int l, int r) {
	lz[i] = max(lz[i], a);
	tr[i] = a!=-INF ? a * (r - l + 1) : tr[i];
}
 
void pushdown(int i, int l, int m, int r) {
	app(i<<1, lz[i], l, m);
	app(i<<1|1, lz[i], m+1, r);
	lz[i] = -INF;
}
 
void update(int l1, int r1, LL x, int i=1, int l2=1, int r2=n) {
	if(l1<=l2&&r2<=r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	if(l1<=m2) update(l1, r1, x, i<<1, l2, m2);
	if(m2<r1) update(l1, r1, x, i<<1|1, m2+1, r2);
	tr[i]=tr[i<<1]+tr[i<<1|1];
}
 
LL query(int l1, int r1, int i=1, int l2=1, int r2=n) {
	if(l1<=l2&&r2<=r1)
		return tr[i];
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	return (l1<=m2 ? query(l1, r1, i<<1, l2, m2) : 0ll) + (m2<r1 ? query(l1, r1, i<<1|1, m2+1, r2) : 0ll);
}
 
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",a+i);
	s[1] = sum[1] = 0;
	rep(i,2,n)scanf("%d",&x),s[i]=s[i-1]+x;
	rep(i,2,n) a[i] -= s[i], sum[i] = sum[i-1] + s[i];
	
	build();
	scanf("%d\n",&q);
	rep(i,1,q){
		scanf("%c %d %d\n",&ch,&x,&y);
		if(ch=='+'){
			LL now = query(x,x) + y;
			int l=x, r=n, pos=x;
			while(l<=r){
				int mid = l+r>>1;
				if(query(mid,mid)>now) r = mid-1;
				else l = mid+1, pos = mid;
			}
			update(x,pos,now);
		}else printf("%lld\n",sum[y]-sum[x-1]+query(x,y));
	}
	return 0;
}