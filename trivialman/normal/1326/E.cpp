#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 1e9;
const int N = 3e5+5;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, x;
int a[N], tr[(1<<20)+5], lz[(1<<20)+5];

void app(int i, LL a, int l, int r) {
	lz[i] = lz[i] + a;
	tr[i] = tr[i] + a;
}

void pushdown(int i, int l, int m, int r) {
	app(i<<1, lz[i], l, m);
	app(i<<1|1, lz[i], m+1, r);
	lz[i] = 0;
}

void update(int l1, int r1, int x, int i=1, int l2=1, int r2=n) {
	if(l1<=l2&&r2<=r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	if(l1<=m2) update(l1, r1, x, i<<1, l2, m2);
	if(m2<r1) update(l1, r1, x, i<<1|1, m2+1, r2);
	tr[i]=min(tr[i<<1],tr[i<<1|1]);
}

int query(int l1, int r1, int i=1, int l2=1, int r2=n) {
	if(l1<=l2&&r2<=r1)
		return tr[i];
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	return min(l1<=m2 ? query(l1, r1, i<<1, l2, m2) : INF,  m2<r1 ? query(l1, r1, i<<1|1, m2+1, r2) : INF);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&x), a[x]=i;
	
	int ans = n-1;
	update(1, a[n], -1);
	rep(i,1,n){
		printf("%d ",ans+1);
		
		scanf("%d",&x);
		update(1, x, 1);
		while(ans && query(1, n) >= 0){
			update(1, a[ans], -1);
			ans--;
		}
	}
	return 0;
}