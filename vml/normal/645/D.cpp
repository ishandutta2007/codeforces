#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
int n, m;

vector <int> ed[maxn];

int cnt[maxn];
bool us[maxn];
set <int> s;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		s.insert(i + 1);
	}

	int res = 0;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);

		if (us[x]) {
			continue;
		}

		if (cnt[y] == 0) {
			s.erase(y);
		}

		cnt[y]++;

		while ((int)s.size() == 1) {
			res++;

			int v = *s.begin();

			s.erase(v);
			us[v] = true;

			for (int j = 0; j < (int)ed[v].size(); j++) {
				int u = ed[v][j];

				cnt[u]--;

				if (cnt[u] == 0) {
					s.insert(u);
				}
			}
		}

		if (res == n) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}