#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, ans[mxN], c[mxN+1], d[mxN+1];
vector<ar<int, 3>> v[30];

void solve(vector<ar<int, 3>> v, int k) {
	memset(c, 0, 4*(n+1));
	for(ar<int, 3> a : v)
		if(a[2])
			++c[a[0]], --c[a[1]+1];
	for(int i=0; i<n; ++i) {
		c[i+1]+=c[i];
		c[i]=min(c[i], 1);
		ans[i]|=c[i]<<k;
	}
	memset(d, 0, 4*(n+1));
	for(int i=0; i<n; ++i)
		d[i+1]=d[i]+c[i];
	for(ar<int, 3> a : v) {
		if(!a[2]&&d[a[1]+1]-d[a[0]]==a[1]-a[0]+1) {
			cout << "NO";
			exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int l, r, q;
		cin >> l >> r >> q, --l, --r;
		for(int j=0; j<30; ++j)
			v[j].push_back({l, r, q>>j&1});
	}
	for(int i=0; i<30; ++i)
		solve(v[i], i);
	cout << "YES\n";
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
}