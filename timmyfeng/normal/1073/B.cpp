#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pos[a] = i;
	}

	int cur = -1;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		if (pos[b] > cur) {
			cout << pos[b] - cur << ' ';
			cur = pos[b];
		} else {
			cout << 0 << ' ';
		}
	}
	cout << '\n';
}