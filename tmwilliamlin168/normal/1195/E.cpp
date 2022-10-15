#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e3;
int n, m, a, b, g0, x, y, z, g[mxN*mxN];
vector<int> c[mxN];
ll ans;

vector<int> sw(vector<int> &a, int l) {
	deque<int> dq;
	vector<int> b;
	for(int i=0; i<a.size(); ++i) {
		while(dq.size()&&a[dq.back()]>a[i])
			dq.pop_back();
		dq.push_back(i);
		if(i>=l-1) {
			b.push_back(a[dq.front()]);
			if(dq.front()<=i-(l-1))
				dq.pop_front();
		}
	}
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
	g[0]=g0;
	for(int i=1; i<n*m; ++i)
		g[i]=((ll)g[i-1]*x+y)%z;
	for(int i=0; i<n; ++i) {
		vector<int> d;
		for(int j=0; j<m; ++j)
			d.push_back(g[i*m+j]);
		c[i]=sw(d, b);
	}
	for(int j=0; j<=m-b; ++j) {
		vector<int> d;
		for(int i=0; i<n; ++i)
			d.push_back(c[i][j]);
		vector<int> e=sw(d, a);
		ans=accumulate(e.begin(), e.end(), ans);
	}
	cout << ans;
}