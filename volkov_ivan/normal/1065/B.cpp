#include <iostream>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	long long mini = max(0ll, n - 2 * m);
	long long maxi;
	for (long long i = 0; i <= n; i++) {
		long long full = i * (i - 1) / 2;
		if (full >= m) {	
			cout << mini << ' ' << n - i << endl;
			return 0;
		}
	}
	cout << mini << ' ' << n << endl;
	return 0;
}