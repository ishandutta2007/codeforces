#include <bits/stdc++.h>

using namespace std;

int t, n, m, a[1 << 20], b;

int main() {
	cin >> t;
	while (t--) {
		vector<int> v1, v2;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++) {
			cin >> b;
			if (b == 1) 
				v1.push_back(a[i]);
			else
				v2.push_back(a[i]);
		}
		sort(v1.rbegin(), v1.rend());
		sort(v2.rbegin(), v2.rend());
		int j = v2.size() - 1, ans = 2 * n + 1;
		long long sum = accumulate(v2.begin(), v2.end(), 0ll);
		for (int i = 0; i <= v1.size(); i++) {
			while (0 <= j && sum - v2[j] >= m) 
				sum -= v2[j--];
			if (sum >= m)
				ans = min(ans, i + 2 * (j + 1));
			if (i < v1.size()) 
				sum += v1[i];
		}
		cout << (ans == 2 * n + 1 ? -1 : ans) << "\n";
	}
	
	return 0;
}