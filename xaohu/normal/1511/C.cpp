#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int n, q, a[300111];

int main() {
	cin >> n >> q;
	FOR(i, n)
		cin >> a[i];
	while (q--) {
		int x;
		cin >> x;
		FOR(i, n) {
			if (a[i] == x) {
				cout << i + 1 << " ";
				for (int j = i - 1; 0 <= j; j--)
					a[j + 1] = a[j];
				a[0] = x;
				break;
			}
		}
	}
	
	return 0;
}