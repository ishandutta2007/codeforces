#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int , int>;

const int INF = 1e9;
const ll LINF = 1e18;

const int N = 1e5+7;

ll a[N], p[N], q;
int n, m, k, l[N], r[N], d[N], x, y, z[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i) cin >> l[i] >> r[i] >> d[i];
	for(int i = 0; i < k; ++i) 
		(cin >> x >> y), z[x-1]++, z[y]--;
	
	for(int i = 0, j = 0; i < m; ++i) {
		ll dx = (ll)d[i]*(j += z[i]);
		p[l[i]-1] += dx, p[r[i]+0] -= dx;
	}

	for(int i = 0; i < n; ++i) 
		cout << a[i] + (q += p[i]) << ' ';
	cout << endl;
}