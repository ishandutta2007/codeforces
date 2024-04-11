#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, l, r;
	cin >> n;
	pair <int, char> shows[2 * n];
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		shows[2 * i] = make_pair(l, '(');
		shows[2 * i + 1] = make_pair(r, ')');
	}
	sort(shows, shows + 2 * n);
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (shows[i].second == '(') {
			cnt++;
		} else {
			cnt--;
		}
		if (cnt > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}