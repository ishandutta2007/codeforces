#include <iostream>

using namespace std;

const int MAX_N = 107;
int cnt[MAX_N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < MAX_N; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		for (int j = 0; j < r; j++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
	}
	for (int i = 0; i < MAX_N; i++) {
		if (cnt[i] == n) cout << i << ' ';
	}
	return 0;
}