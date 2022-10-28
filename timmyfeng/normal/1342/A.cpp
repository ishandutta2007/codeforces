#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			swap(x, y);
		}
		if (b > a * 2) {
			b = a * 2;
		}
		cout << (long long)x * b + (long long)(y - x) * a << '\n';
	}
}