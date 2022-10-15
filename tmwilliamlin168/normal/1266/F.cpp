#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, d[mxN], ans[mxN+1];
vector<int> adj[mxN];

struct node {
	int a, b;
} st[1<<19];

void app(int i, int x, int y) {
	st[i].a=max(st[i].a, st[i].b+x);
	st[i].b+=y;
}

void psh(int i) {
	app(2*i, st[i].a, st[i].b);
	app(2*i+1, st[i].a, st[i].b);
	st[i].a=st[i].b=0;
}

void upd(int l1, int r1, int x, int i=1, int l2=0, int r2=n/2) {
	if(l1<=l2&&r2<=r1) {
		app(i, x, x);
		return;
	}
	int m2=(l2+r2)/2;
	psh(i);
	if(l1<=m2)
		upd(l1, r1, x, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, x, 2*i+1, m2+1, r2);
}

void psha(int i=1, int l2=0, int r2=n/2) {
	if(l2==r2) {
		ans[l2*2]=max(ans[l2*2], st[i].a);
		return;
	}
	int m2=(l2+r2)/2;
	psh(i);
	psha(2*i, l2, m2);
	psha(2*i+1, m2+1, r2);
}

void dfs1(int u=0, int p=-1) {
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs1(v, u);
		d[u]=max(d[u], d[v]+1);
	}
}

void dfs2(int u=0, int p=-1, int pd=0) {
	//cout << u << " " << p << " " << pd << endl;
	//odd
	{
		vector<int> a{pd, 0};
		for(int v : adj[u])
			if(v^p)
				a.push_back(d[v]+1);
		sort(a.begin(), a.end());
		for(int i=0; i<a.size(); ++i) {
			if(a[i])
				ans[2*a[i]-1]=max(ans[2*a[i]-1], (int)a.size()-i);
			if(i==a.size()-1||a[i]<a[i+1])
				ans[2*a[i]+1]=max(ans[2*a[i]+1], (int)a.size()-i);
		}
	}
	//even
	{
		upd(0, pd, 1);
		for(int v : adj[u]) {
			if(v==p)
				continue;
			upd(0, d[v]+1, 1);
		}
		for(int v : adj[u]) {
			if(v==p)
				continue;
			upd(0, d[v]+1, -1);
			for(int w : adj[v]) {
				if(w==u)
					continue;
				upd(0, d[w]+1, 1);
			}
			for(int w : adj[v]) {
				if(w==u)
					continue;
				upd(0, d[w]+1, -1);
			}
			upd(0, d[v]+1, 1);
		}
		upd(0, pd, -1);
		for(int v : adj[u]) {
			if(v==p)
				continue;
			upd(0, d[v]+1, -1);
		}
	}
	//go to children
	{
		vector<int> a{pd};
		for(int v : adj[u])
			if(v^p)
				a.push_back(d[v]+1);
		sort(a.begin(), a.end(), greater<int>());
		for(int v : adj[u])
			if(v^p)
				dfs2(v, u, (d[v]+1==a[0]?a[1]:a[0])+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ans[n]=ans[n-1]=1;
	dfs1();
	dfs2();
	psha();
	for(int i=n; i>2; --i)
		ans[i-2]=max(ans[i], ans[i-2]);
	for(int i=1; i<=n; ++i)
		cout << ans[i] << " ";
}