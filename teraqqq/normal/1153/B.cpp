#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;

const int INF = 1e9;
const ll LINF = 1e18;

const int N = 106;

int n, m, h, x[N], y[N], a[N][N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> h;
	for(int i = 0; i < m; ++i) cin >> x[i];
	for(int i = 0; i < n; ++i) cin >> y[i];
	for(int i = 0; i < n; ++i) 
	for(int j = 0; j < m; ++j)
		(cin >> a[i][j]), a[i][j] *= INF;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			cout << min(a[i][j], min(y[i], x[j])) << ' ';
		cout << endl;
	}
}