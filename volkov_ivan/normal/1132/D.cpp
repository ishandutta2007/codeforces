#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long

using namespace std;

const int MAX_N = 2e5 + 7, INF = 1e18;
int n, k;
int a[MAX_N], b[MAX_N];

bool check(int x) {
	int cnt = 0;
	//map <int, vector <pair <int, int>>> nxt;
	vector <pair <int, int>> nxt[k + 1];
	for (int i = 0; i < n; i++) {
		int est = a[i] / b[i] + 1;
		if (est >= k) continue;
		nxt[est].push_back({a[i] - b[i] * est, b[i]});
	}
	for (int t = 1; t < k; t++) {
		for (pair <int, int> elem : nxt[t]) {
			int need = (-elem.first) / x;
			if ((-elem.first) % x != 0) need++;
			cnt += need;
			int est = (elem.first + need * x) / elem.second + 1;
			if (t + est >= k) continue;
			nxt[t + est].push_back({elem.first + need * x - elem.second * est, elem.second});
		}
		if (cnt > t) return 0;
	}
	return 1;
}

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i] * (k - 1)) flag = 0;
	}
	if (flag) {
		cout << 0 << endl;
		return 0;
	}
	int l = 0, r = INF, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		//cout << m << endl;
		if (check(m)) r = m;
		else l = m;
	}
	if (r == INF) cout << "-1" << endl;
	else cout << r << endl;
	return 0;
}