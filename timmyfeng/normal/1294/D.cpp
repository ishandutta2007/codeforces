#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q, x;
	cin >> q >> x;
	int mex = 0;
	vector<int> freq(x);
	while (q--) {
		int a;
		cin >> a;
		++freq[a % x];
		for ( ; freq[mex % x] >= mex / x + 1; ++mex);
		cout << mex << '\n';
	}
}