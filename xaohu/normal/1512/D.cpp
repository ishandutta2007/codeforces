#include <bits/stdc++.h>

using namespace std;

int t, n, b[200111];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n + 2; i++)
			cin >> b[i];
		sort(b, b + n + 2);
		long long sum = accumulate(b, b + n + 2, 0ll);
		bool ok = false;
		for (int x = n; x <= n + 1; x++) {
			for (int y = 0; y < n + 2; y++)
				if (!ok && x != y && sum - b[x] - b[y] == b[x]) {
					ok = true;
					for (int i = 0; i < n + 2; i++)	
						if (i != x && i != y)
							cout << b[i] << " ";
					cout << "\n";
				}
		}
		if (!ok)
			cout << "-1\n";
	}
	return 0;
}