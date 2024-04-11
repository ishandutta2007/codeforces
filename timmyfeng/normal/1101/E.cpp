#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int mxa = 0, mxb = 0;
	while (n--) {
		char t;
		int a, b;
		cin >> t >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		if (t == '+') {
			mxa = max(mxa, a);
			mxb = max(mxb, b);
		} else {
			cout << (mxa <= a && mxb <= b ? "YES" : "NO") << '\n';
		}
	}
}