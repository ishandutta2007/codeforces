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
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = (int)1e6 + 10;
int a[maxn], t[maxn], x[maxn];
vector <int> v;
vector <int> d[maxn];
vector <int> tr[maxn];

void change(int it, int x, int pos) {
	for ( ; pos < (int)tr[it].size(); pos = pos | (pos + 1)) {
		tr[it][pos] += x;
	}
}

int go(int it, int pos) {
	int ans = 0;

	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += tr[it][pos];
	}

	return ans;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i], &t[i], &x[i]);
		v.push_back(x[i]);
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();

		d[x[i]].push_back(t[i]);
	}

	for (int i = 0; i < (int)v.size(); i++) {
		sort(d[i].begin(), d[i].end());
		d[i].resize(unique(d[i].begin(), d[i].end()) - d[i].begin());
		tr[i].resize(d[i].size(), 0);
	}

	for (int i = 0; i < n; i++) {
		t[i] = lower_bound(d[x[i]].begin(), d[x[i]].end(), t[i]) - d[x[i]].begin();
		if (a[i] == 1) {
			change(x[i], 1, t[i]);
		} else if (a[i] == 2) {
			change(x[i], -1, t[i]);
		} else {
			printf("%d\n", go(x[i], t[i]));
		}
	}

	return 0;
}