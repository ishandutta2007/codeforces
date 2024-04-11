#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl << endl

int n, m;
bool a[501];

int qry() {
	cout << "? ";
	for(int i = 0; i < m; ++i) cout << a[i];
	cout nl;
	int x; cin >> x;
	return x;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	fill(a, a + m, 0);
	array<int, 2> e[m];

	for(int i = 0; i < m; ++i) {
		a[i] = 1;
		e[i] = {qry(), i};
		a[i] = 0;
	}

	sort(e, e + m);
	reverse(e, e + m);
	fill(a, a + m, 1);
	int prv = qry(), sum {};
	int j = e[m-1][1];

	for(auto [w, i] : e) if(i != j) {
		a[i] = 0;
		int x = qry();
		if(x + w == prv) {
			a[i] = 1;
			sum += w;
		} else {
			a[i] = 0;
			prv = x;
		}
	}

	cout << "! " << prv nl;
}