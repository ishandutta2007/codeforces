#include <iostream>

using namespace std;

int main() {
	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	int t[n + 1];
	for (int i = 1; i <= n; i++) t[i] = -1;
	int cur = 0;
	while (a != x) {
		t[a] = cur;
		a = a + 1;
		if (a == n + 1) a = 1;
		cur++;
	}
	t[a] = cur;
	cur = 0;
	while (b != y) {
		if (t[b] == cur) {
			cout << "YES" << endl;
			return 0;
		}
		b = b - 1;
		if (b == 0) b = n;
		cur++;
	}
	if (t[b] == cur) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}