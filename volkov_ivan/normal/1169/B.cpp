#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 3e5 + 7;
pair <int, int> a[MAX_N];

bool check(int n, int m, int x) {
	int cnt_bad = 0;
	map <int, int> cnt;
	for (int i = 0; i < m; i++) {
		if (a[i].first != x && a[i].second != x) {
			cnt_bad++;
			cnt[a[i].first]++;
			cnt[a[i].second]++;
		}
	}
	if (cnt_bad == 0) return 1;
	for (pair <int, int> elem : cnt) {
		if (elem.second == cnt_bad) return 1;
	}
	return 0;
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
	if (check(n, m, a[0].first) || check(n, m, a[0].second)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}