#include <iostream>

using namespace std;

int main() {
	const int max_t = 86400;
	int n, t, a;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a;
		t -= (max_t - a);
		if (t <= 0) {
			cout << i + 1 << endl;
			return 0;
		}
	}
}