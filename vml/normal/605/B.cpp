#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <ctime>
#include <map>
#define ld double
#define ll long long
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;

pair <pair <int, int>, int> v[maxn];
pair <int, int> ans[maxn];

vector <pair <int, int> > now;

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].first.second = 1 - v[i].first.second;
		v[i].second = i;
	}

	sort(v, v + m);

	vector <int> c;

	int last = 1;
	c.push_back(1);

	for (int i = 0; i < m; i++) {
		if (v[i].first.second == 1) {
			if (now.empty()) {
				cout << -1 << endl;
				return 0;
			}

			ans[v[i].second] = now.back();
			now.pop_back();
		} else {
			ans[v[i].second] = (make_pair(last, last + 1));

			for (int j = 0; j < (int)c.size() && (int)now.size() < m; j++) {
				if (c[j] != last) {
					now.push_back(make_pair(c[j], last + 1));
				}
			}

			c.push_back(last + 1);
			last++;
		}
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}

	return 0;
}