#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n;
vector<int> adj[mxN], bd[mxN], fv;

ar<int, 2> ask(vector<int> v) {
	if(!v.size())
		return {-1, 2*mxN};
	cout << "? " << v.size();
	for(int a : v)
		cout << " " << a+1;
	cout << endl;
	int x, d;
	cin >> x >> d, --x;
	return {x, d};
}

void dfs1(int u, int p=-1, int d=0) {
	bd[d].push_back(u);
	for(int v : adj[u])
		if(v^p)
			dfs1(v, u, d+1);
}

void dfs2(int u, int d, int pr, int p=-1) {
	if(pr==u)
		pr=-1;
	if(!d&&pr<0) {
		fv.push_back(u);
		return;
	}
	for(int v : adj[u])
		if(v^p)
			dfs2(v, d-1, pr, u);
}

void solve() {
	cin >> n;
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> va(n);
	iota(va.begin(), va.end(), 0);
	ar<int, 2> rt=ask(va);
	dfs1(rt[0]);
	int x=(rt[1]+1)/2-1, u1=rt[0];
	for(int i=8; ~i; --i) {
		int y=x+(1<<i);
		vector<int> vb;
		for(int j=y; j<n; ++j)
			vb.insert(vb.end(), bd[j].begin(), bd[j].end());
		ar<int, 2> a=ask(vb);
		if(a[1]==rt[1])
			x=y, u1=a[0];
	}
	dfs2(u1, rt[1], rt[0]);
	int u2=ask(fv)[0];
	fv.clear();
	cout << "! " << u1+1 << " " << u2+1 << endl;
	string s;
	cin >> s;
	for(int i=0; i<n; ++i) {
		adj[i].clear();
		bd[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}