#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i] / 2;
	}

	for (int i = 0; i < n; ++i) {
		if (sum < 0 && a[i] > 0 && a[i] % 2) {
			++a[i];
			++sum;
		} else if (sum > 0 && a[i] < 0 && a[i] % 2) {
			--a[i];
			--sum;
		}
		a[i] /= 2;
		cout << a[i] << "\n";
	}
}