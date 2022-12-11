#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 7;
int p[MAX_N], wh[MAX_N];
vector <pair <int, int>> ans;

void swp(int a, int b) {
	ans.push_back({a, b});
	swap(p[a], p[b]);
	wh[p[a]] = a;
	wh[p[b]] = b;
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		wh[p[i]] = i;
	}
	if (p[1] != 1) {
		int pos = wh[1];
		if (pos > n / 2) {
			swp(pos, 1);
		} else {
			swp(pos, n);
			swp(n, 1);
		}
	}
	for (int i = 2; i <= n / 2; i++) {
		int pos = wh[i];
		if (wh[i] == i) continue;
		if (pos == n) {
			swp(i, n);
			continue;
		}
		if (pos > n / 2) {
			swp(pos, 1);
			swp(1, n);
			swp(n, i);
			swp(1, pos);
		} else {
			swp(pos, n);
			swp(n, i);
		}
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		int pos = wh[i];
		if (pos == i) continue;
		swp(1, pos);
		swp(1, i);
		swp(1, pos);
	}
	cout << ans.size() << endl;
	for (pair <int, int> elem : ans) {
		cout << elem.first << ' ' << elem.second << "\n";
	}
	return 0;
}