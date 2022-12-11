#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	int cnt1 = 0, s = 2;
	vector <int> one;
	vector <int> not_one;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {one.push_back(i); cnt1++;}
		else {not_one.push_back(i); s += a[i] - 2;}
	}
	if (cnt1 > s) {
		cout << "NO" << endl;
		return 0;
	}
	vector <pair <int, int>> ans;
	int res = not_one.size() - 1;
	res += min(2, (int) one.size());
	for (int i = 1; i < not_one.size(); i++) {
		ans.push_back(make_pair(not_one[i - 1], not_one[i]));
		a[not_one[i - 1]]--;
		a[not_one[i]]--;
	}
	if (!one.empty()) {
		ans.push_back(make_pair(one[0], not_one[0]));
		a[not_one[0]]--;
	}
	int tail = (int) not_one.size() - 1;
	for (int i = 1; i < one.size(); i++) {
		while (tail >= 0 && a[not_one[tail]] == 0) tail--;
		if (tail < 0) {
			cout << "NO" << endl;
			return 0;
		}
		a[not_one[tail]]--;
		ans.push_back(make_pair(not_one[tail], one[i]));
	}
	cout << "YES " << res << endl << ans.size() << endl;
	for (pair <int, int> elem : ans) {
		cout << elem.first + 1 << ' ' << elem.second + 1 << endl;
	}
	return 0;
}