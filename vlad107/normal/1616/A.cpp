#include <iostream>
#include <vector>

using namespace std;

const int M = 100;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(M + 1);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			++a[abs(x)];
		}
		int res = min(1, a[0]);
		for (int i = 1; i <= M; i++) {
			res += min(2, a[i]);
		}
		cout << res << "\n";
	}
	return 0;
}