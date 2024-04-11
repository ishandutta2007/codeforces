#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long n ,k;
		cin >> k >> n;
		long long low = 0, high = n * 2;
		while (low < high) {
			int mid = (low + high) / 2;
			if (mid - mid / k >= n) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << low << endl;
	}
}