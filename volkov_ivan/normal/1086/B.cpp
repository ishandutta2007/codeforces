#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 7;
int cnt[MAX_N];

int main() {
	cout.precision(30);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		cnt[v]++;
		cnt[u]++;
	}
	int b = 0;
	for (int i = 1; i <= n; i++) if (cnt[i] == 1) b++;
	long double ans = 2 * ((long double) s) / b;
	cout << fixed << ans << endl;
	return 0;
}