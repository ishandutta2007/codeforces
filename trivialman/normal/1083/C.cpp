#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define ar2 array<int,2> 
const int N = 2e5+5;

int n, a[N], p[N], ds[N], de[N], dti, q, qt, qi, qj;
vector<int> g[N];
int dt[19][N<<1];
ar2 st[(1<<19)+5];

void dfs(int u=1){
	ds[u]=++dti;
	dt[0][dti]=u;
	for(int v:g[u])
		dfs(v), dt[0][++dti]=u;
	de[u]=dti;
}

int lca(int u, int v) {
	if((u=ds[u])>(v=ds[v])) swap(u, v);
	int k=31-__builtin_clz(v-u+1);
	return min(dt[k][u], dt[k][v-(1<<k)+1]);
};
bool d(int u, int v, int w) { //check whether w on the path from u to v
	int l=lca(u, v);
	return ds[l]<=ds[w] && de[w]<=de[l] && (ds[w]<=ds[u]&&de[u]<=de[w] || ds[w]<=ds[v]&&de[v]<=de[w]);
};
int c(ar2 &a, int b) {
	if(b==-1||a[0]==-1)
		a[0]=a[1]=-1;
	else if(d(a[0], b, a[1]))
		a[1]=b;
	else if(d(a[1], b, a[0]))
		a[0]=b;
	else if(!d(a[0], a[1], b))
		a[0]=a[1]=-1;
};
void cmb(ar2 &a, ar2 b) {	
	c(a,b[0]), c(a,b[1]);
}

void upd(int l1, ar2 x, int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		st[i]=x;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2) upd(l1, x, 2*i, l2, m2);
	else upd(l1, x, 2*i+1, m2+1, r2);
	st[i]=st[2*i];
	cmb(st[i], st[2*i+1]);
}

int qry(int i=1, int l2=0, int r2=n-1, ar2 p={}) {
	ar2 a=st[i];
	if(l2) cmb(a, p);
	if(a[0]!=-1) return r2+1;
	if(l2==r2) return l2;
	int m2=(l2+r2)/2;
	a=st[2*i];
	if(l2) cmb(a, p);
	return a[0]==-1 ? qry(2*i, l2, m2, p) : qry(2*i+1, m2+1, r2, a);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,2,n) scanf("%d",p+i), g[p[i]].push_back(i);
	dfs();
	rep(i,1,18) rep(j,1,2*n-(1<<i))
		dt[i][j]=min(dt[i-1][j], dt[i-1][j+(1<<i-1)]);
	rep(i,1,n) upd(a[i], {i, i});
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&qt);
		if(qt==1) {
			scanf("%d%d",&qi,&qj);
			swap(a[qi], a[qj]);
			upd(a[qi], {qi, qi});
			upd(a[qj], {qj, qj});
		} else
			printf("%d\n",qry());
	}
}