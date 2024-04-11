#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
vector<int> cnt(N, 0);
int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x;
		cin >> n >> x;
		x--;
		for (int i = 0; i < N; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			cnt[a]++;
			cnt[b]++;
		}
		int count;
		if (cnt[x] < 2) {
			count = 1;
		} else {
			count = (n + 1) % 2;
		}
		cout << (count % 2 == 0 ? "Ashish" : "Ayush") << endl;
	}
}