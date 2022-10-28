#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		cout << (a + c == b && b == d ? "YES" : "NO") << '\n';
	}
}