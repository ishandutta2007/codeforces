#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cstdio>
#include <cassert>
#include <climits>
#include <ctime>

using namespace std;

#define ll long long
#define mp make_pair

ll n, s, d, m, x, y;
vector<ll> v;
vector<pair<int, ll> > ans;

int main() {

	cin >> n >> m >> s >> d;
	if (d < 2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	x = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - x - 1 >= s) {
			ans.push_back(mp(1, v[i] - x - 1));
			if (i == v.size() - 1) {
				ans.push_back(mp(2, 2));
				if (m != v[i] + 1)
					ans.push_back(mp(1, m - v[i] - 1));
				x = m;
				break;
			}
			else {
				y = i + 1;
				while (y < v.size() && v[y] - v[y - 1] - 2 < s) {
					y++;
				}
				y--;
				if (v[y] + 1 - (v[i] - 1) <= d) {
					ans.push_back(mp(2, v[y] + 1 - (v[i] - 1)));
					x = v[y] + 1;
					i = y;
				}
				else {
					cout << "IMPOSSIBLE";
					return 0;
				}
			}
		}
		else {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	if (x != m) {
		ans.push_back(mp(1, m - x));
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].first == 1) {
			cout << "RUN " << ans[i].second << endl;
		}
		else {
			cout << "JUMP " << ans[i].second << endl;
		}
	}

	return 0;
}