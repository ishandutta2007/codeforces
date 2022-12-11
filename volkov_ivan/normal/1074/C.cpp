#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 7, INF = 1e9 + 7;
pair <int, int> p[MAX_N];


long long calc(int i, int j, int k) {
	if (i == j || j == k || i == k) return 0;
	long long ans = 0;
	ans += abs(p[i].first - p[j].first);
	ans += abs(p[j].first - p[k].first);
	ans += abs(p[k].first - p[i].first);
	ans += abs(p[i].second - p[j].second);
	ans += abs(p[j].second - p[k].second);
	ans += abs(p[k].second - p[i].second);
	return ans;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int max_x = -INF, max_y = -INF, min_x = INF, min_y = INF;
	long long ans = 0, ans_3 = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		max_x = max(max_x, p[i].first);
		min_x = min(min_x, p[i].first);
		max_y = max(max_y, p[i].second);
		min_y = min(min_y, p[i].second);
		if (i >= 1) {
			ans += abs(p[i].first - p[i - 1].first);
			ans += abs(p[i].second - p[i - 1].second);
		}
	}
	ans += abs(p[0].first - p[n - 1].first);
	ans += abs(p[0].second - p[n - 1].second);
	vector <int> poss;
	for (int i = 0; i < n; i++) {
		if (p[i].first == max_x || p[i].first == min_x || p[i].second == max_y || p[i].second == min_y) poss.push_back(i);
	}
	for (int i = 0; i < poss.size(); i++) {
		for (int j = i + 1; j < poss.size(); j++) {
			for (int k = 0; k < n; k++) {
				ans_3 = max(ans_3, calc(poss[i], poss[j], k));	
			}
		}
	}
	cout << ans_3 << ' ';
	for (int i = 4; i <= n; i++) cout << ans << ' ';
	cout << endl;
	return 0;
}