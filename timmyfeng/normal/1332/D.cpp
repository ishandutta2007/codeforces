#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	int b = (1 << (32 - __builtin_clz(k)));
	cout << 2 << ' ' << 3 << '\n';
	cout << b + k << ' ' << k << ' ' << 0 << '\n';
	cout << b << ' ' << b + k << ' ' << k << '\n';
}