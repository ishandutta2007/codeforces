#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	//freopen("Desktop/input.txt", "r", stdin);
	vector <pair <int, int>> a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y) {
			a.push_back({y, i});
		} else {
			b.push_back({y, i});
		}
	}
	sort(a.begin(), a.end(), greater <pair <int, int>>());
	sort(b.begin(), b.end());
	if (a.size() > b.size()) {
		cout << a.size() << endl;
		for (pair <int, int> elem : a) cout << elem.second + 1 << ' ';
	} else {
		cout << b.size() << endl;
		for (pair <int, int> elem : b) cout << elem.second + 1 << ' ';
	}
	cout << endl;
	return 0;
}