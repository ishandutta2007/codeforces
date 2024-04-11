#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2e5;
int n, m, k, a[mxN], d0[mxN], d1[mxN];
vector<int> adj[mxN];
bool b[mxN];
 
void bfs(int s, int d[mxN]) {
	memset(d, 0x3f, 4*n);
	d[s]=0;
	queue<int> qu;
	qu.push(s);
	while(qu.size()) {
		int u=qu.front();
		qu.pop();
		for(int v : adj[u]) {
			if(d[v]>n) {
				d[v]=d[u]+1;
				qu.push(v);
			}
		}
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m >> k;
	for(int i=0; i<k; ++i) {
		cin >> a[i], --a[i];
		b[a[i]]=1;
	}
	bool c=0;
	for(int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		if(b[u]&&b[v])
			c=1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(0, d0);
	bfs(n-1, d1);
	int ans=d0[n-1], a2=0;
	if(!c) {
		auto test=[&](ar<int, 2> a, ar<int, 2> b) {
			a2=max(a2, min(a[0]+b[1], a[1]+b[0]));
		};
		vector<ar<int, 2>> v;
		for(int i=0; i<k; ++i)
			v.push_back({d0[a[i]], d1[a[i]]});
		sort(v.begin(), v.end());
		int j=0;
		for(int i=0; i<v.size(); ++i) {
			while(j&&v[j-1][0]<=v[i][0]&&v[j-1][1]<=v[i][1]) {
				--j;
				test(v[j], v[i]);
			}
			v[j++]=v[i];
		}
		v.resize(j);
		//for(int i=0, j=v.size()-1; i<v.size(); ++i) {
			//while(j&&min(v[i][0]+v[j-1][1], v[i][1]+v[j-1][0])>min(v[i][0]+v[j][1], v[i][1]+v[j][0]))
				//--j;
			//test(v[i], v[j]);
		//}
		for(int i=0; i<v.size(); ++i) {
			if(i)
				test(v[i], v[i-1]);
		}
	} else
		a2=ans;
	cout << min(a2+1, ans);
}