#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, q, anc[mxN][17], ds[mxN], de[mxN], dt, dp[mxN], li, ri;
vector<int> ch[mxN];
array<int, 2> st1[mxN*2], st2[mxN*2];

void dfs(int u) {
	for(int j=1; j<17; ++j)
		anc[u][j]=anc[u][j-1]==-1?-1:anc[anc[u][j-1]][j-1];
	dp[u]=u?dp[anc[u][0]]+1:0;
	ds[u]=dt++;
	for(int v : ch[u])
		dfs(v);
	de[u]=dt;
}

int lca(int u, int v) {
	if(dp[u]<dp[v])
		swap(u, v);
	for(int i=16; i>=0; --i)
		if(dp[u]-(1<<i)>=dp[v])
			u=anc[u][i];
	if(u==v)
		return u;
	for(int i=16; i>=0; --i) {
		if(anc[u][i]!=anc[v][i]) {
			u=anc[u][i];
			v=anc[v][i];
		}
	}
	return anc[u][0];
}

void upd1(int i, array<int, 2> x) {
	for(st1[i+=n]=x; i/=2; )
		st1[i]=min(st1[2*i], st1[2*i+1]);
}

void upd2(int i, array<int, 2> x) {
	for(st2[i+=n]=x; i/=2; )
		st2[i]=max(st2[2*i], st2[2*i+1]);
}

array<int, 2> qry1(int l, int r) {
	array<int, 2> b{INT_MAX};
	for(l+=n, r+=n; l<r; ++l/=2, r/=2) {
		if(l&1)
			b=min(st1[l], b);
		if(r&1)
			b=min(st1[r-1], b);
	}
	return b;
}

array<int, 2> qry2(int l, int r) {
	array<int, 2> b{INT_MIN};
	for(l+=n, r+=n; l<r; ++l/=2, r/=2) {
		if(l&1)
			b=max(st2[l], b);
		if(r&1)
			b=max(st2[r-1], b);
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	anc[0][0]=-1;
	for(int i=1; i<n; ++i) {
		cin >> anc[i][0], --anc[i][0];
		ch[anc[i][0]].push_back(i);
	}
	dfs(0);
	for(int i=0; i<n; ++i) {
		upd1(i, {ds[i], i});
		upd2(i, {ds[i], i});
	}
	while(q--) {
		cin >> li >> ri, --li;
		array<int, 2> mnp1=qry1(li, ri), mxp1=qry2(li, ri);
		upd1(mnp1[1], {INT_MAX});
		upd2(mxp1[1], {INT_MIN});
		array<int, 2> mnp2=qry1(li, ri), mxp2=qry2(li, ri);
		int w1=lca(mnp1[1], mxp2[1]), w2=lca(mnp2[1], mxp1[1]), a1=mxp1[1];
		if(dp[w1]<dp[w2]) {
			w1=w2;
			a1=mnp1[1];
		}
		cout << a1+1 << " " << dp[w1] << "\n";
		upd1(mnp1[1], mnp1);
		upd2(mxp1[1], mxp1);
	}
}