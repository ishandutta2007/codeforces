#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;

int ans[MX + 1];
bool done[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cur = n;
	for (int i = n; i; --i) {
		for (int j = i * 2; j <= n; j += i) {
			if (!done[j]) {
				ans[cur--] = i;
				done[j] = true;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}