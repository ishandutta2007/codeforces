#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;

int n, t[N], k[N], q, r1, r2, p;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; p = t[i++]) {
		cin >> t[i] >> k[i];
		int dx = min(q, t[i]-p);
		q += k[i] - dx;
		r2 = max(q, r2);
		r1 = max(r1, t[i]+q);
	}

	cout << r1 << ' ' << r2;
}