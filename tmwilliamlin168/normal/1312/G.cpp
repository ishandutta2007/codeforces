#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6+5;
int n, c[mxN][26], m, a[mxN], dt, ds[mxN], de[mxN], dep[mxN], s2[mxN];
ll co[mxN], co2[mxN], dp1[mxN], dp2[mxN];
bool b[mxN];
vector<int> sc[mxN];

//current add, max add
int lz1[1<<21], lz2[1<<21];

void app(int i, int x, int y) {
	lz2[i]=min(lz2[i], lz1[i]+y);
	lz1[i]+=x;
}

void psh(int i) {
	app(2*i, lz1[i], lz2[i]);
	app(2*i+1, lz1[i], lz2[i]);
	lz1[i]=lz2[i]=0;
}

void upd(int l1, int r1, int x, int y, int i=1, int l2=0, int r2=n) {
	if(l1<=l2&&r2<=r1) {
		if(!y)
			app(i, x, x);
		else {
			lz1[i]=lz2[i]=x;
		}
		return;
	}
	int m2=(l2+r2)/2;
	psh(i);
	if(l1<=m2)
		upd(l1, r1, x, y, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, x, y, 2*i+1, m2+1, r2);
}

ar<int, 2> qry(int l1, int i=1, int l2=0, int r2=n) {
	if(l2==r2)
		return {lz1[i], lz2[i]};
	int m2=(l2+r2)/2;
	psh(i);
	if(l1<=m2)
		return qry(l1, 2*i, l2, m2);
	return qry(l1, 2*i+1, m2+1, r2);
}

void dfs1(int u, int sp) {
	ds[u]=dt++;
	if(b[u]) {
		if(u) {
			sc[sp].push_back(u);
			++s2[u];
		}
		sp=u;
	}
	for(int v=0; v<26; ++v)
		if(c[u][v]) {
			dep[c[u][v]]=dep[u]+1;
			dfs1(c[u][v], sp);
			s2[u]+=s2[c[u][v]];
		}
	de[u]=dt;
}

int dfs2(int u) {
	if(b[u]) {
		co[u]=qry(ds[u])[1];
		//cout << u << " " << co[u] << endl;
		int i=u>0;
		//cout << "sc" << endl;
		for(int v : sc[u]) {
			//cout << v << " ";
			/*
			upd(ds[v], ds[v], dep[v]-dep[u], 1);
			upd(ds[v], ds[v], i-(dep[v]-dep[u]), 0);
			*/
			upd(ds[v], ds[v], i+1, 1);
			i+=s2[v];
		}
		//cout << endl;
	}
	int t=0;
	upd(ds[u], de[u], u>0&&b[u]?0:1, 0);
	for(int v=0; v<26; ++v) {
		if(c[u][v]) {
			int s=dfs2(c[u][v]);
			t+=s;
			//add t to range [de[c[u][v]], de[u])
			if(de[c[u][v]]<de[u])
				upd(de[c[u][v]], de[u]-1, -s2[c[u][v]], 0);
		}
	}
	return b[u]?1:t;
}

int dfs3(int u) {
	if(b[u]) {
		co2[u]=qry(ds[u])[1];
		//cout << u << " " << co[u] << endl;
		int i=0;
		//cout << "sc" << endl;
		for(int v : sc[u]) {
			//cout << v << " ";
			//++i;
			upd(ds[v], ds[v], i+1, 1);
			i+=s2[v];
		}
		//cout << endl;
	}
	int t=0;
	upd(ds[u], de[u], 1, 0);
	for(int v=0; v<26; ++v) {
		if(c[u][v]) {
			int s=dfs3(c[u][v]);
			t+=s;
			//add t to range [de[c[u][v]], de[u])
			if(de[c[u][v]]<de[u])
				upd(de[c[u][v]], de[u]-1, -s2[c[u][v]], 0);
		}
	}
	return b[u]?1:t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		int p;
		char d;
		cin >> p >> d;
		c[p][d-'a']=i+1;
	}
	cin >> m;
	for(int i=0; i<m; ++i) {
		cin >> a[i];
		b[a[i]]=1;
	}
	b[0]=1;

	dfs1(0, -1);
	dfs2(0);
	dfs3(0);

	//dp2[0]=1e9;
	for(int i=0; i<n; ++i) {
		if(!b[i])
			continue;
		for(int j : sc[i]) {
			dp2[j]=min(dp2[i]+co2[j], dp1[i]+co[j]);
			dp1[j]=min(dp1[i], dp2[i])+dep[j]-dep[i];
		}
	}
	for(int i=0; i<m; ++i)
		cout << min(dp1[a[i]], dp2[a[i]]) << " ";
}