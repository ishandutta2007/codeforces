#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int MAX_N = 5e5 + 7, INF = 1e9 + 7;
int a[MAX_N];
vector <int> pos[MAX_N];
int cnt_c[MAX_N];

int main() {
	int n, c;
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	int cc = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == c) cc++;
		cnt_c[i] = cc;
		pos[a[i]].push_back(i);
	}
	int res = cc;
	for (int d = 1; d < MAX_N; d++) {
		if (d == c) continue;
		int now = 0, mini = INF;
		if (!pos[d].empty()) now = 1;
		int cn = 0;
		for (int elem : pos[d]) {
			cn++;
			int m = cn - cnt_c[elem];
			now = max(now, (m - mini + 1));
			mini = min(mini, m);
		}
		res = max(res, cc + now);
	}
	cout << res << endl;
	return 0;
}