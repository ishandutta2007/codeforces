#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 7;
long long a[MAX_N], b[MAX_N];

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n / 2; i++) {
		cin >> b[i];
		if (i == 0) {
			a[i] = 0;
			a[n - i - 1] = b[i];
			continue;
		} else {
			long long l = a[i - 1], r = a[n - i];
			if (b[i] - r > l) {
				a[i] = b[i] - r;
				a[n - i - 1] = r;
			} else {
				a[i] = l;
				a[n - i - 1] = b[i] - l;	
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	return 0;
}