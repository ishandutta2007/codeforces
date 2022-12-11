#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 100000;
int a[MAX_N], b[MAX_N];
bool used[MAX_N];
int n;

int find(int x) {
	int left = 0, right = n, mid;
	while (right - left > 1) {
		//cout << right << ' ' << left << endl;
		mid = (left + right) / 2;
		if (b[mid] <= x) {
			left = mid;
		} else {
			right = mid;
		}
	}
	//cout << x << ' ' << left << endl;
	return left;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		used[i] = 0;
	}
	sort(b, b + n);
	vector <vector <int> > ans;
	vector <int> now;
	int j;
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			continue;
		}
		now.clear();
		j = i;
		while (!used[j]) {
			now.push_back(j);
			used[j] = 1;
			j = find(a[j]);
		}
		ans.push_back(now);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << ' ';
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] + 1 << ' ';
		}
		cout << endl;
	}
	return 0;
}