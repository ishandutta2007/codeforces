#include <iostream>

using namespace std;

const long long MAX_N = 1007, INF = 4000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll + 12;
unsigned long long f[MAX_N];

void init() {
	f[0] = 0;
	f[1] = 1;
	for (int i = 1; i < MAX_N; i++) {
		if (f[i - 1] == INF) {
			f[i] = INF;
			continue;
		}
		f[i] = min(1 + 4 * f[i - 1], INF * 1ull);
	}
}

int main() {
	//freopen("Desktop/inp.in", "r", stdin);
	init();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n, k;
		cin >> n >> k;
		if (n >= MAX_N || f[n - 1] + 1 >= k) {
			cout << "YES " << n - 1 << '\n';
			continue;
		} else {
			long long now = 1, did = 0;
			bool flag = 0;
			for (int ans = n - 1; ans >= 0; ans--) {
				did += now;
				now *= 2;
				now++;
				long long rest = f[n] - now * f[ans];
				if (did <= k && k <= rest) {
					cout << "YES " << ans << '\n';
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "NO\n";
			}
		}
	}
	return 0;
}