#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5+7;

int n, q[N], qmax[N], m[N], x, qqmax;
long long ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> m[i]; qmax[i] = 0;
		for(int j = 0; j < m[i]; ++j) {
			cin >> x;
			if(x > qmax[i]) qmax[i] = x;
		}

		if(qmax[i] > qqmax) qqmax = qmax[i];
	}

	for(int i = 0; i < n; ++i) {
		ans += 1LL * m[i] * (qqmax - qmax[i]);
	}

	cout << ans;
}