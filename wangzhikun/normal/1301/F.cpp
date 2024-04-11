#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3, mxK=40;
int n, m, k, a[mxN*mxN], q, d[mxK][mxN*mxN];
vector<int> occ[mxK], nb[mxN*mxN];
bool vis[mxK];

vector<int> gn(int x) {
	int i=x/m, j=x%m;
	vector<int> r;
	if(i) r.push_back((i-1)*m+j);
	if(i<n-1) r.push_back((i+1)*m+j);
	if(j) r.push_back(i*m+j-1);
	if(j<m-1) r.push_back(i*m+j+1);
	return r;
}

void bfs(int c) {
	memset(d[c], 0x3f, sizeof(d[0]));
	queue<int> qu;
	memset(vis, 0, k);
	vis[c]=1;
	for(int a : occ[c]) {
		d[c][a]=0;
		qu.push(a);
	}
	while(qu.size()) {
		int u=qu.front();
		qu.pop();
		if(!vis[a[u]]) {
			for(int b : occ[a[u]])
				if(d[c][b]>1e9) {
					d[c][b]=d[c][u]+1;
					qu.push(b);
				}
			vis[a[u]]=1;
		}
		//vector<int> nb=gn(u);
		for(int v : nb[u]) {
			if(d[c][v]>1e9) {
				d[c][v]=d[c][u]+1;
				qu.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i=0; i<n*m; ++i) {
		cin >> a[i], --a[i];
		occ[a[i]].push_back(i);
		nb[i]=gn(i);
	}
	for(int i=0; i<k; ++i)
		bfs(i);
	cin >> q;
	while(q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2, --r1, --c1, --r2, --c2;
		int ans=abs(r1-r2)+abs(c1-c2);
		for(int i=0; i<k; ++i)
			ans=min(ans, 1+d[i][r1*m+c1]+d[i][r2*m+c2]);
		cout << ans << "\n";
	}
}