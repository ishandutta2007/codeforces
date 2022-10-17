#include <iostream>
using namespace std;

int main() {
	long long int n, m;
	cin >> n >> m;
	long long int cnt = 0;
	for (long long int i = 1; i <= n; ++i) {
		cnt += (i + m) / 5 - i / 5;
	}
	// for (int j = 1; j < m; ++j) {
	// 	cnt += (j + n) / 5;
	// }
	cout << cnt << endl;
	return 0;
}