#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=300, mxQ=2e6;
int n, m, q, ans[mxQ+1], a[mxN][mxN], p[mxN*mxN];
vector<ar<int, 3>> ta[mxQ+1], td[mxQ+1];
bool vis[mxN*mxN];
 
int find(int x) {
	return x^p[x]?p[x]=find(p[x]):x;
}
 
bool join(int x, int y) {
	if((x=find(x))==(y=find(y)))
		return 0;
	p[x]=y;
	return 1;
}
 
void solve(int c) {
	iota(p, p+n*m, 0);
	memset(vis, 0, n*m);
	auto f=[&](int x1, int y1, int x2, int y2, int t) {
		if(x2<0||x2>=n||y2<0||y2>=m||!vis[x2*m+y2])
			return;
		int x=join(x1*m+y1, x2*m+y2);
		ans[t]-=x;
	};
	for(ar<int, 3> a : ta[c]) {
		++ans[a[0]];
		f(a[1], a[2], a[1]-1, a[2], a[0]);
		f(a[1], a[2], a[1]+1, a[2], a[0]);
		f(a[1], a[2], a[1], a[2]-1, a[0]);
		f(a[1], a[2], a[1], a[2]+1, a[0]);
		vis[a[1]*m+a[2]]=1;
	}
	for(ar<int, 3> a : td[c])
		vis[a[1]*m+a[2]]=0;
	iota(p, p+n*m, 0);
	auto g=[&](int x1, int y1, int x2, int y2, int t) {
		if(x2<0||x2>=n||y2<0||y2>=m||!vis[x2*m+y2])
			return;
		int x=join(x1*m+y1, x2*m+y2);
		ans[t]+=x;
	};
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(!vis[i*m+j])
				continue;
			g(i, j, i-1, j, q);
			g(i, j, i+1, j, q);
			g(i, j, i, j-1, q);
			g(i, j, i, j+1, q);
		}
	}
	reverse(td[c].begin(), td[c].end());
	for(ar<int, 3> a : td[c]) {
		--ans[a[0]];
		g(a[1], a[2], a[1]-1, a[2], a[0]);
		g(a[1], a[2], a[1]+1, a[2], a[0]);
		g(a[1], a[2], a[1], a[2]-1, a[0]);
		g(a[1], a[2], a[1], a[2]+1, a[0]);
		vis[a[1]*m+a[2]]=1;
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m >> q;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			ta[0].push_back({0, i, j});
	for(int i=0, x, y, c; i<q; ++i) {
		cin >> x >> y >> c, --x, --y;
		if(a[x][y]==c)
			continue;
		ta[c].push_back({i, x, y});
		td[a[x][y]].push_back({i, x, y});
		a[x][y]=c;
	}
	for(int i=0; i<=max(1000, (mxQ-1)/(n*m)+1); ++i)
		solve(i);
	for(int i=0; i<q; ++i) {
		ans[i+1]+=ans[i];
		cout << ans[i] << "\n";
	}
}