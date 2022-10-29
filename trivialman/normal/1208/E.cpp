#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 1e6+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, w, l; 
LL a[N];
LL tr[(1<<21)+5], lz[(1<<21)+5];

void app(int i, LL a, int l, int r) {
	lz[i] = lz[i] + a;
	tr[i] = tr[i] + a * (r - l + 1);
}

void pushdown(int i, int l, int m, int r) {
	app(i<<1, lz[i], l, m);
	app(i<<1|1, lz[i], m+1, r);
	lz[i] = 0;
}

void update(int l1, int r1, LL x, int i=1, int l2=1, int r2=w) {
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

LL query(int l1, int r1, int i=1, int l2=1, int r2=w) {
	if(l1<=l2&&r2<=r1)
		return tr[i];
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	return (l1<=m2 ? query(l1, r1, i<<1, l2, m2) : 0) + (m2<r1 ? query(l1, r1, i<<1|1, m2+1, r2) : 0);
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&w);
	memset(tr,0,sizeof tr);
	memset(lz,0,sizeof lz);
	while(n--){
		scanf("%d",&l);
		rep(i,1,l) scanf("%lld",a+i);
		a[0] = a[l+1] = 0;
		//rep(i,1,l) cout<<a[i]<<" ";cout<<endl;
		deque<int> Q; Q.push_back(0);
		rep(i,1,l){
			while(!Q.empty() && Q.front()<l-w+i) Q.pop_front();
			while(!Q.empty() && a[Q.back()]<a[i]) Q.pop_back();
			Q.push_back(i);
			//cout<<i<<" a[Q.front()]= "<<a[Q.front()]<<endl;
			update(i,i,a[Q.front()]);
		}
		
		while(!Q.empty() && a[Q.back()]<0) Q.pop_back();
		Q.push_back(l+1);
		rep(i,max(l+1,w-l+1),w){
			while(!Q.empty() && Q.front()<l-w+i) Q.pop_front();
			//cout<<i<<" a[Q.front()]= "<<a[Q.front()]<<endl;
			update(i,i,a[Q.front()]);
		}
		if(l*2<w) update(l+1,w-l,max(0ll,*max_element(a+1,a+l+1)) );
		//rep(i,1,w)printf("%lld ",query(i,i));cout<<endl;
	}
	rep(i,1,w)printf("%lld ",query(i,i));
	return 0;
}