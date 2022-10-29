#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
#define ar6 array<int, 6>
typedef long long LL;
const int P = 1e9+7;
const int N = 1e5;
const double PI = acos(-1);
mt19937 rng(time(0));

struct dat{
	int sa, ea, sb, eb;
	void in(){scanf("%d%d%d%d",&sa,&ea,&sb,&eb);}
	void out(){printf("%d %d %d %d\n",sa,ea,sb,eb);}
	bool operator<(dat y){return sa<y.sa;}
}a[N+5];

int n, m, st[N*4+5], b[N+5];
vector<int> ids[N+5]; 
int tr[(1<<20)+5], lz[(1<<20)+5];


void app(int i, LL a, int l, int r) {
	lz[i] = lz[i] + a;
	tr[i] = tr[i] + a;
}

void pushdown(int i, int l, int m, int r) {
	app(i<<1, lz[i], l, m);
	app(i<<1|1, lz[i], m+1, r);
	lz[i] = 0;
}

void update(int l1, int r1, int x, int i=1, int l2=1, int r2=m) {
	if(l1<=l2&&r2<=r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	if(l1<=m2) update(l1, r1, x, i<<1, l2, m2);
	if(m2<r1) update(l1, r1, x, i<<1|1, m2+1, r2);
	tr[i]=max(tr[i<<1],tr[i<<1|1]);
}

int query(int l1, int r1, int i=1, int l2=1, int r2=m) {
	if(l1<=l2&&r2<=r1)
		return tr[i];
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	return max(l1<=m2 ? query(l1, r1, i<<1, l2, m2) : 0,  m2<r1 ? query(l1, r1, i<<1|1, m2+1, r2) : 0);
}

bool check(){
	memset(tr,0,sizeof tr);
	memset(lz,0,sizeof lz);
	sort(a+1,a+n+1);
	rep(i,1,n+1) ids[i].clear();
	
	rep(i,1,n) b[i] = a[i].sa;
	rep(i,1,n){
		int x = upper_bound(b+1, b+n+1, a[i].ea) - b;
		ids[x].PB(i);
	}

	rep(i,1,n){
		for(auto id:ids[i]) update(a[id].sb, a[id].eb, 1);
		if( query(a[i].sb, a[i].eb) ) return false;
	}
	return true;
}

bool change(){
	rep(i,1,n) swap(a[i].sa, a[i].sb), swap(a[i].ea, a[i].eb);
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n){
		a[i].in();
		st[++m] = a[i].sa, st[++m] = a[i].ea;
		st[++m] = a[i].sb, st[++m] = a[i].eb;
	}
	sort(st+1,st+m+1);
	m = unique(st+1,st+m+1) - st - 1;
	rep(i,1,n){
		a[i].sa = lower_bound(st+1, st+m+1, a[i].sa) - st;
		a[i].ea = lower_bound(st+1, st+m+1, a[i].ea) - st;
		a[i].sb = lower_bound(st+1, st+m+1, a[i].sb) - st;
		a[i].eb = lower_bound(st+1, st+m+1, a[i].eb) - st;
	}
	bool flag = check() && change() && check();
	printf(flag?"YES":"NO");
	return 0;
}