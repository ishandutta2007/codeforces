#include <iostream>
using namespace std;
int a[100020], n, c, z;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 1) {
			if (a[i] == a[i - 1] + a[i - 2]) {
				c++;
			} else {
				c = 0;
			}
			z = max(z, c);
		}
	}
	cout << min(z + 2, n) << endl;
	return 0;
}