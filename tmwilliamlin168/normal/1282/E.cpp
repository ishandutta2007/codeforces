#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q[mxN], d[mxN], nxt[mxN], prv[mxN];
set<int> a[mxN];
set<ar<int, 2>> b;
ar<int, 3> c[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n-2; ++i) {
		cin >> c[i][0] >> c[i][1] >> c[i][2], --c[i][0], --c[i][1], --c[i][2];
		a[c[i][0]].insert(i);
		a[c[i][1]].insert(i);
		a[c[i][2]].insert(i);
	}
	for(int i=0; i<n; ++i) {
		b.insert({(int)a[i].size(), i});
	}
	for(int i=0; i<n-2; ++i) {
		ar<int, 2> bf=*b.begin();
		while(!bf[0]) {
			b.erase(bf);
			bf=*b.begin();
		}
		q[i]=bf[1];
		d[i]=*a[q[i]].begin();
		b.erase({(int)a[c[d[i]][0]].size(), c[d[i]][0]});
		b.erase({(int)a[c[d[i]][1]].size(), c[d[i]][1]});
		b.erase({(int)a[c[d[i]][2]].size(), c[d[i]][2]});
		a[c[d[i]][0]].erase(d[i]);
		a[c[d[i]][1]].erase(d[i]);
		a[c[d[i]][2]].erase(d[i]);
		b.insert({(int)a[c[d[i]][0]].size(), c[d[i]][0]});
		b.insert({(int)a[c[d[i]][1]].size(), c[d[i]][1]});
		b.insert({(int)a[c[d[i]][2]].size(), c[d[i]][2]});
	}
	b.clear();
	//cout << "hi1" << endl;
	nxt[c[d[n-3]][0]]=c[d[n-3]][1];
	nxt[c[d[n-3]][1]]=c[d[n-3]][2];
	nxt[c[d[n-3]][2]]=c[d[n-3]][0];
	prv[c[d[n-3]][0]]=c[d[n-3]][2];
	prv[c[d[n-3]][1]]=c[d[n-3]][0];
	prv[c[d[n-3]][2]]=c[d[n-3]][1];
	for(int i=n-4; ~i; --i) {
		if(c[d[i]][1]==q[i])
			swap(c[d[i]][1], c[d[i]][0]);
		if(c[d[i]][2]==q[i])
			swap(c[d[i]][2], c[d[i]][0]);
		int u=c[d[i]][1];
		if(nxt[u]^c[d[i]][2])
			u=c[d[i]][2];
		int v=nxt[u];
		nxt[u]=q[i];
		prv[v]=q[i];
		prv[q[i]]=u;
		nxt[q[i]]=v;
	}
	for(int i=0, u=0; i<n; ++i, u=nxt[u]) {
		cout << u+1 << " ";
	}
	cout << "\n";
	for(int i=0; i<n-2; ++i)
		cout << d[i]+1 << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}