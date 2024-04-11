#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

const int N = 300300;

int n, k, res[N], t[N];

void solve() {
	cin >> n >> k;
	rep(i, 1, n + 1)
		t[i] = 0;
	rep(i, 0, k)
		cin >> res[i];
	rep(i, 0, k) {
		int x;
		cin >> x;
		t[res[i]] = x;
	}

	rep(i, 1, n + 1)
		res[i] = 2e9;
	int best = 2e9;
	rep(i, 1, n + 1) {
		if (t[i])
			best = min(best, t[i] - i);
		res[i] = min(res[i], i + best);
	}
	best = 2e9;
	per(i, 1, n + 1) {
		if (t[i])
			best = min(best, t[i] + i);
		res[i] = min(res[i], best - i);
	}
	rep(i, 1, n + 1)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}