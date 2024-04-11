#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a[2*mxN], b[2*mxN], c[2*mxN];
vector<int> adj[mxN], adj2[mxN], p;
bool vis[mxN];

void dfs(int u=0) {
	vis[u]=1;
	p.push_back(u);
	for(int v : adj2[u])
		if(!vis[v])
			dfs(v);
}

bool chk() {
	set<ar<int, 2>> s1, s2;
	for(int i=0; i<2*n; ++i) {
		if(a[i]>b[i])
			swap(a[i], b[i]);
		s1.insert({a[i], b[i]});
	}
	for(int i=0; i<n; ++i)
		for(int j=1; j<3; ++j) {
			int c=p[i], d=p[(i+j)%n];
			if(c>d)
				swap(c, d);
			s2.insert({c, d});
		}
	return s1==s2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<2*n; ++i) {
		cin >> a[i] >> b[i], --a[i], --b[i];
		adj[a[i]].push_back(i);
		adj[b[i]].push_back(i);
	}
	if(n<7) {
		p=vector<int>(n);
		iota(p.begin(), p.end(), 0);
		do {
			if(chk()) {
				for(int i=0; i<n; ++i)
					cout << p[i]+1 << " ";
				return 0;
			}
		} while(next_permutation(p.begin(), p.end()));
		cout << -1;
		return 0;
	}
	for(int i=0; i<n; ++i) {
		if(adj[i].size()^4) {
			cout << -1;
			return 0;
		}
	}
	for(int i=0; i<2*n; ++i) {
		for(int e1 : adj[a[i]])
			for(int e2 : adj[b[i]])
				if((a[e1]^b[e1]^a[i])==(a[e2]^b[e2]^b[i]))
					++c[i];
		//cout << c[i] << endl;
		if(c[i]==2) {
			adj2[a[i]].push_back(b[i]);
			adj2[b[i]].push_back(a[i]);
			//cout << a[i] << " " << b[i] << endl;
		}
	}
	dfs();
	if(p.size()^n) {
		cout << -1;
		return 0;
	}
	if(!chk()) {
		cout << -1;
		return 0;
	}
	for(int i=0; i<n; ++i)
		cout << p[i]+1 << " ";
}