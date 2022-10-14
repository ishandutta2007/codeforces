#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int lim = 1;
	int res=0;
	for(;n>0;) {
		n -= lim;
		lim <<= 1;
		++res;
	}

	cout << res << endl;
}