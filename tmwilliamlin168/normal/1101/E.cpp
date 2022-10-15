#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		if (x > y)
			swap(x, y);
		if (ch == '+') {
			a = max(a, x);
			b = max(b, y);
		}
		else if (x >= a && y >= b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}