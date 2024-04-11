#include <iostream>

using namespace std;

int main() {
	//freopen("Desktop/input.txt", "r", stdin); 
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n, k;
		cin >> n >> k;
		long long cnt = 0;
		while (n != 0) {
			if (n % k == 0) {
				cnt++;
				n /= k;
				continue;
			}
			cnt += n % k;
			n = (n / k) * k;
		}
		cout << cnt << endl;
	}
	return 0;
}