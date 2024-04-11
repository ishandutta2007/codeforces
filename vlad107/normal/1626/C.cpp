#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long calcCost(int l, int r) {
	int len = r - l + 1;
	return len * 1LL * (len + 1) / 2;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> k(n);
		for (int &x : k) cin >> x;
		vector<int> h(n);
		for (int &x : h) cin >> x;
		vector<long long> f(n + 1, calcCost(1, k.back()));
		f[0] = 0;
		for (int i = 0; i < n; i++) {
			int last = (i == 0 ? 0 : k[i - 1]);
			int needStart = k[i] - h[i] + 1;
			for (int j = i; (j < n) && (needStart > last); j++) {
				needStart = min(needStart, k[j] - h[j] + 1);
				if (needStart > last) 
					f[j + 1] = min(f[j + 1], f[i] + calcCost(needStart, k[j]));
			}

		}
		cout << f[n] << "\n";
	}
	return 0;
}