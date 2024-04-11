#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int calc(int n, int m) {
	return round(100 * (((long double) n) / m)); 
}

bool good[10000];

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	queue <int> q;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	for (int i = 1; i <= n; i++) good[i] = 0;
	pair <int, int> num[k];
	int cur[k];
	for (int i = 0; i < k; i++) {
		if (!q.empty()) {
			cur[i] = q.size();
			num[i] = {q.front(), 1};
			q.pop();
		} else {
			num[i] = {3, -1};
		}
	}
	while (cnt != n) {
		//cout << cnt << endl;
		for (int i = 0; i < k; i++) {
			if (num[i].second == -1) continue;
			num[i].second++;
			if (num[i].second == num[i].first + 1) {
				cnt++;
				num[i].second = -1;
				if (!q.empty()) {
					cur[i] = q.size();
					num[i] ={q.front(), 1};
					q.pop();
				}
			}
		}
		int t = calc(cnt, n);
		for (int i = 0; i < k; i++) {
			if (num[i].second == t) good[cur[i]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (good[i]) ans++;
	cout << ans << endl;
	return 0;
}