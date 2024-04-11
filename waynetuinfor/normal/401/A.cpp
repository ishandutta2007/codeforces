#include <iostream>
using namespace std;

int main() {
	int n, x, c;
	cin >> n >> x;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		sum += c;
	}
	if (sum > 0) {
		while (sum > 0) {
			sum -= x;
			cnt++;
		}
	} else if (sum < 0) {
		while (sum < 0) {
			sum += x;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}