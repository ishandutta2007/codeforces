#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			--ptr;
		}
		while (ptr > 0 && a[ptr - 1] <= a[ptr]) {
			--ptr;
		}

		cout << ptr << "\n";
	}
}