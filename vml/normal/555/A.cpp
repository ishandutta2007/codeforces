#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> v[maxn];

int main() {
	int n, k;

	scanf("%d %d", &k, &n);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		v[i].resize(x);

		for (int j = 0; j < x; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	sort(v, v + n);

	int ans = 0;
	int cnt = 1;

	for (int i = 1; i < (int)v[0].size(); i++) {
		if (v[0][i] != v[0][i - 1] + 1) {
			ans += (int)v[0].size() - i;
			cnt += (int)v[0].size() - i;
			break;
		}
	}

	for (int i = 1; i < n; i++) {
		cnt += (int)v[i].size();
		ans += (int)v[i].size() - 1;
	}

	cout << ans + cnt - 1 << endl;

	return 0;
}