#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

const int N = 1e5+7;

int t, n, l[N], r[N], q[N], p[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);


	for(cin >> t; t--; ) {
		cin >> n;
		fill(q, q+n, 1);
		iota(p, p+n, 0);

		for(int i = 0; i < n; ++i)
			cin >> l[i] >> r[i];

		sort(p, p+n, [&](int a, int b) {
			return l[a] < l[b];
		});

		int k = 0, mr = r[p[0]];
		for(int i = 0; i < n; ++i)
			if(l[p[i]] <= mr) {
				++k;
				mr = max(mr, r[p[i]]);
				q[p[i]] = 2;
			}

		if(k == n) cout << -1 << endl;
		else {
			for(int i = 0; i < n; ++i)
				cout << q[i] << ' ';
			cout << endl;
		}
	}

}