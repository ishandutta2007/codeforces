#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 5e5 + 7, K = 20;
int nxt[MAX_N], jump[K][MAX_N];
int mx[MAX_N];

int main() {
	//freopen("Desktop/input.txt", "r", stdin); 
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < MAX_N; i++) mx[i] = -1;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		mx[l] = max(mx[l], r);
	}
	nxt[0] = mx[0];
	for (int i = 1; i < MAX_N; i++) {
		nxt[i] = max(nxt[i - 1], mx[i]);
	}
	for (int i = MAX_N - 1; i >= 0; i--) {
		if (nxt[i] <= i) {
			for (int j = 0; j < K; j++) jump[j][i] = -1;
			continue;
		}
		jump[0][i] = nxt[i];
		for (int j = 1; j < K; j++) {
			if (jump[j - 1][i] == -1) {
				jump[j][i] = -1;
				continue;
			}
			jump[j][i] = jump[j - 1][jump[j - 1][i]];
		}
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		int ans = 0, v = l;
		for (int j = K - 1; j >= 0; j--) {
			if (jump[j][v] == -1) continue;
			if (jump[j][v] < r) {
				ans += (1 << j);
				v = jump[j][v];
			}
		}
		if (jump[0][v] != -1) {
			ans++;
			v = jump[0][v];
		}
		if (v < r) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}