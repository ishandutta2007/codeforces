#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair
const int M = 10000;
int a[2 * M];

void solve() {
	int m = 0;
	fill(a, a + 2 * M, 0);
	for (int i = 0; i < 250; i++) {
		int num;
		cin >> num;
		a[num + M]++;
		m = max(m, abs(num));
	}	
	int t = m / 2;
	if (m < 3)
		t = 1;
	int sum = 0;
	for (int i = M - t + 1; i <= M + t - 1; i++)
		sum += a[i];
	if ((double)sum / (2 * t - 1) > 1.4 * 250.0 / (2 * m + 1)) {
		cout << "poisson\n";
	} else {
		cout << "uniform\n";
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);	
	int v;
	cin >> v;
	while (v--)
		solve();
	return 0;
}