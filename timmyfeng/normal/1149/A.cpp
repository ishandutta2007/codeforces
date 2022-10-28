#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int one = 0;
	int two = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == 1) {
			++one;
		} else {
			++two;
		}
	}

	if (two) {
		cout << 2 << " ";
	}
	if (one) {
		cout << 1 << " ";
	}
	for (int i = 1; i < two; ++i) {
		cout << 2 << " ";
	}
	for (int j = 1; j < one; ++j) {
		cout << 1 << " ";
	}
	cout << "\n";
}