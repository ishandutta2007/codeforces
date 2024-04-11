#include<set>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005, M = 5000005;
int n, m;
long long p[N], v[N], anss[M];

int minTurn() {
	for (int i = 0; i < n; ++i) {
		v[i] = p[i];
	}
	int ret = 0;
	long long maxm = m;
	while (true) {
		for (int i = n - 1; i >= 0; --i) {
			long long now = min(maxm, v[i]);
			if (now == 0) {
				return ret;
			} else {
				maxm = now - 1;
				v[i] -= now;
			}
		}
		++ret;
	}
}

int maxTurn() {
	for (int i = 0; i < n; ++i) {
		v[i] = p[i];
	}
	int ret = 0;
	long long minm = 1;
	while (true) {
		for (int i = 0; i < n; ++i) {
			if (minm > m) {
				return ret;
			}
			if (v[i] < minm) {
				return ret;
			} else {
				v[i] -= minm++;
			}
		}
		++ret;
	}
}

long long mins[N];

long long solve(int t) {
	if (anss[t] != -1) {
		return anss[t];
	}
	long long last = 0;
	for (int i = 0; i < n; ++i) {
		v[i] = p[i];
	}
	long long ret = 0;
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < n; ++j) {
			v[j] -= ++last;
			ret += last;
		}
	}
	int delta = m - last; 
	for (int i = t - 1; i >= 0 && delta; --i) {
		for (int j = n - 1; j >= 0 && delta; --j) {
			delta = v[j] > delta ? delta : v[j];
			v[j] -= delta;
			ret += delta;
		}
	}
	return anss[t] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	int l = minTurn(), r = maxTurn();
	for (int i = l; i <= r; ++i) {
		anss[i] = -1;
	}
	long long ans = max(solve(l), solve(r));
	int mid1, mid2;
	for (int i = 0; i < 100; ++i) {
		mid1 = (l + l + r) / 3;
		mid2 = (l + r + r) / 3;
		ans = max(ans, solve(mid1));
		ans = max(ans, solve(mid2));
		if (solve(mid1) > solve(mid2)) {
			r = mid2;
		} else {
			l = mid1;
		}
	}
	cout << ans << endl;
	return 0;
}