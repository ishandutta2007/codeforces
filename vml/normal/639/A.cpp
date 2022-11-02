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

int n, k, q, x, y;
set<int> s;
set<int>::iterator it;
int a[200001];

int main() {

	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		y--;
		if (x == 1) {
			s.insert(-1 * a[y]);
			if (s.size() > k) {
				it = s.end();
				it--;
				s.erase(it);
			}
		}
		else {
			if (s.count(-1 * a[y])) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}