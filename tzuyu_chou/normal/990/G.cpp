#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int n, a[mxN], centP[mxN], sz[mxN];
bool ic[mxN+1];
vector<int> pfs[mxN+1], adj[mxN];
ll ans[mxN+1], cnt1[mxN+1], cnt2[mxN+1];

int gcd(int a, int b) {
	return !b?a:gcd(b, a%b);
}

void dfs1(int u, int p) {
	sz[u]=1;
	for(int v : adj[u]) {
		if(v==p||centP[v]!=-1)
			continue;
		dfs1(v, u);
		sz[u]+=sz[v];
	}
}

int dfs2(int u, int p, int n) {
	for(int v : adj[u])
		if(v!=p&&centP[v]==-1&&sz[v]>n/2)
			return dfs2(v, u, n);
	return u;
}

void dfs3(int u, int p, int cg) {
	cg=gcd(a[u], cg);
	++cnt1[cg];
	for(int v : adj[u]) {
		if(v==p||centP[v]!=-1)
			continue;
		dfs3(v, u, cg);
	}
}

inline void dc(int c, vector<int> &dvs1, int s) {
	for(int pf : pfs[a[c]])
		for(int i=dvs1.size()-1; i>=0; --i)
			if(a[c]%(dvs1[i]*pf)==0)
				cnt1[dvs1[i]]+=cnt1[dvs1[i]*pf];
	for(int dv : dvs1)
		cnt2[dv]=cnt1[dv]*cnt1[dv];
	for(int pf : pfs[a[c]])
		for(int dv : dvs1)
			if(a[c]%(dv*pf)==0)
				cnt2[dv]-=cnt2[dv*pf];
	for(int dv : dvs1) {
		ans[dv]+=s*cnt2[dv];
		cnt1[dv]=0;
	}
}

void cd(int u, int p) {
	int c=dfs2(u, -1, sz[u]);
	centP[c]=p;
	vector<int> dvs1, dvs2;
	for(int i=1; i*i<=a[c]; ++i) {
		if(a[c]%i)
			continue;
		dvs1.push_back(i);
		if(i*i<a[c])
			dvs2.push_back(a[c]/i);
	}
	for(int i=dvs2.size()-1; i>=0; --i)
		dvs1.push_back(dvs2[i]);
//	for(int i=0; i<dvs1.size(); ++i)
//		cout << dvs1[i] << endl;
//	cout << endl;
	dfs1(c, -1);
	dfs3(c, -1, 0);
	dc(c, dvs1, 1);
	for(int v : adj[c]) {
		if(centP[v]==-1) {
			dfs3(v, c, a[c]);
			dc(c, dvs1, -1);
			cd(v, c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=2; i<=mxN; ++i) {
		if(ic[i])
			continue;
		for(int j=i; j<=mxN; j+=i) {
			if(j!=i)
				ic[j]=1;
			pfs[j].push_back(i);
		}
	}
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n-1; ++i) {
		int x, y;
		cin >> x >> y, --x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(centP, -1, 4*n);
	dfs1(0, -1);
	cd(0, -2);
	for(int i=0; i<n; ++i)
		++cnt1[a[i]];
	for(int i=1; i<=mxN; ++i)
		if(ans[i])
			cout << i << " " << (ans[i]-cnt1[i])/2+cnt1[i] << "\n";
}