#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << '?';
	for (int i = 1; i <= 100; ++i) {
		cout << ' ' << (i << 7);
	}
	cout << endl;
	int a;
	cin >> a;
	a &= (1 << 7) - 1;
	cout << '?';
	for (int i = 0; i < 100; ++i) {
		cout << ' ' << i;
	}
	cout << endl;
	int b;
	cin >> b;
	b >>= 7;
	cout << '!' << ' ' << ((b << 7) + a) << endl;
}