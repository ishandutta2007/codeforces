#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long
#define mp make_pair

const ll mod = 1000000007;
const int maxn = 100001;

int n, a[201][201], m, q, x, y, z, t;
vector<pair<int, pair<int, pair<int, int> > > > v;

int main() {

	cin >> n >> m >> q;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			a[i][j] = -2000000000;
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1 || t == 2) {
			cin >> x;
			v.push_back(mp(t, mp(x, mp(-1, -1))));
		}
		else {
			cin >> x >> y >> z;
			v.push_back(mp(t, mp(x, mp(y, z))));
		}
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < q; i++) {
		t = v[i].first;
		if (t == 1) {
			x = v[i].second.first;
			x--;
			for (int j = m - 1; j > 0; j--) {
				swap(a[x][j], a[x][j - 1]);
			}
		}
		else if (t == 2) {
			x = v[i].second.first;
			x--;
			for (int j = n - 1; j > 0; j--) {
				swap(a[j][x], a[j - 1][x]);
			}
		}
		else {
			x = v[i].second.first;
			y = v[i].second.second.first;
			z = v[i].second.second.second;
			x--;
			y--;
			a[x][y] = z;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -2000000000) {
				cout << 1 << ' ';
			}
			else {
				cout << a[i][j] << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}