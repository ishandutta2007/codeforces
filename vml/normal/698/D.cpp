#pragma comment(linker, "/STACK:3200000")
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
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = 1010;

pll a[10];
pll v[maxn];
bool ans[maxn];
int used[maxn];
int r[10];
int num = 0;
vector <int> b[10][maxn];

bool operator <(pll a, pll b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}

	return a.second < b.second;
}

pll operator -(pll a, pll b) {
	a.first -= b.first;
	a.second -= b.second;

	return a;
}

ll operator *(pll a, pll b) {
	return a.first * b.second - a.second * b.first;
}

ll dst(pll a) {
	return a.first * a.first + a.second * a.second;
}

pll g;

bool cmp(int a, int b) {
	return dst(v[a] - g) < dst(v[b] - g);
}

vector <int> f;
int k, n;

bool go(int pos, int d) {
	r[f[pos]] = num;

	if ((int)b[f[pos]][d].size() >= k) {
		return false;
	}

	int h = 0;

	for (int i = 0; i < (int)b[f[pos]][d].size(); i++) {
		if (used[b[f[pos]][d][i]] != num) {
			while (h < k && r[f[h]] == num) {
				h++;
			}

			if (h == k) {
				return false;
			}

			if (!go(h, b[f[pos]][d][i])) {
				return false;
			}
		}
	}

	used[d] = num;
	return true;
}

int main() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		scanf("%I64d %I64d", &a[i].first, &a[i].second);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%I64d %I64d", &v[i].first, &v[i].second);
	}
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < n; t++) {
				if (t != j && (a[i] - v[j]) * (a[i] - v[t]) == 0 && ((a[i] < v[t] && v[t] < v[j]) || (v[j] < v[t] && v[t] < a[i]))) {
					b[i][j].push_back(t);
				}

				if ((int)b[i][j].size() >= k) {
					break;
				}
			}

			g = a[i];
			sort(b[i][j].begin(), b[i][j].end(), cmp);
		}
	}
	
	for (int i = 0; i < k; i++) {
		f.push_back(i);
	}

	while (true) {
		for (int i = 0; i < n; i++) {
			num++;
			go(0, i);

			if (used[i] == num) {
				ans[i] = true;
			}
		}

		if (!next_permutation(f.begin(), f.end())) {
			break;
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (ans[i]) {
			//cout << i << endl;
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}