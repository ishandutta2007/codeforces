#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	map <int, int> cnt;
	map <int, int> to_pos;
	string ans;
	for (int i = 0; i < n; i++) ans += "B";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		ans[i] = 'B';
		to_pos[x] = i;
	}
	vector <int> left, right;
	int zp = -1;
	for (pair <int, int> elem : cnt) {
		if (elem.second == 1) {
			if (left.size() < right.size()) left.push_back(elem.first);
			else right.push_back(elem.first);
		}
		if (elem.second > 2) zp = elem.first;
	}
	if (left.size() == right.size()) {
		cout << "YES" << endl;
		for (int elem : left) ans[to_pos[elem]] = 'A';
		cout << ans << endl;
		return 0;
	}
	if (zp == -1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int elem : left) ans[to_pos[elem]] = 'A';
	ans[to_pos[zp]] = 'A';
	cout << ans << endl;
	return 0;
}