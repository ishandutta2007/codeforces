#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <ctime>
#include <cassert>
#include <bitset>
#include <cstdio>

using namespace std;

int n, d, h;
vector<pair<int, int> > v;

int main() {

	cin >> n >> d >> h;
	if (d == 1 && h == 1) {
		if (n == 2) {
			cout << "1 2";
			return 0;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	if (2 * h < d) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= h; i++) {
		v.push_back(make_pair(i, i + 1));
	}
	if (d == h) {
		int lst = h + 2;
		while (lst <= n) {
			v.push_back(make_pair(2, lst));
			lst++;
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << ' ' << v[i].second << endl;
		}
		return 0;
	}
	v.push_back(make_pair(1, h + 2));
	int lst = h + 2;
	for (int i = 0; i < d - h - 1; i++) {
		v.push_back(make_pair(lst, lst + 1));
		lst++;
	}
	lst++;
	for (int i = lst; i <= n; i++) {
		v.push_back(make_pair(1, i));
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
	return 0;
}