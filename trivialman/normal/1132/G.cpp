#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 1e6+5;
 
int n,k,T=0,a[N],in[N],out[N];
vector<int> g[N];
int tr[(1<<22)+5], lz[(1<<22)+5];

void app(int i, int a, int l, int r) {
	lz[i] = lz[i] + a;
	tr[i] = tr[i] + a;
}

void pushdown(int i, int l, int m, int r) {
	app(i<<1, lz[i], l, m);
	app(i<<1|1, lz[i], m+1, r);
	lz[i] = 0;
}

void update(int l1, int r1, int x, int i=1, int l2=1, int r2=T) {
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

int query(int l1, int r1, int i=1, int l2=1, int r2=T) {
	if(l1<=l2&&r2<=r1)
		return tr[i];
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	return max(l1<=m2 ? query(l1, r1, i<<1, l2, m2) : 0,  m2<r1 ? query(l1, r1, i<<1|1, m2+1, r2) : 0);
}

void dfs(int x){
	in[x] = ++T;
	for(auto u:g[x]) dfs(u);
	out[x] = ++T;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",a+i);
	a[n+1] = n+1;
	stack<int> s;
	rep(i,1,n+1){
		while(!s.empty() && a[i]>a[s.top()]){
			g[i].push_back(s.top()); s.pop();
		}
		s.push(i);
	}
	dfs(n+1);
	rep(i,1,n){
		update(in[i],out[i],1);
		if(i>k) update(in[i-k],out[i-k],-1);
		if(i>=k) printf("%d ",query(1,T));
	}
	return 0;
}