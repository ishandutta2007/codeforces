#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	cout << (a[n - 1] == a[n] ? "NO" : "YES") << endl;
	return 0;
}