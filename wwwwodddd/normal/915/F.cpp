#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
vector<int> a[1000020];
pair<int, int> b[1000020];
long long ansmin;
long long ansmax;
int f[1000020];
int c[1000020];
long long C2(long long x) {
	return x * (x - 1) / 2;
}
bool v[1000020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}

void U(int x, int y) {
	x = F(x);
	y = F(y);
	if (x == y) {
		return;
	}
	f[x] = y;
	c[y] += c[x];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i + 1;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	sort(b, b + n);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		c[i] = 1;
	}
	memset(v, 0, sizeof v);
	for (int i = 0; i < n; i++) {
		int u = b[i].second;
		v[u] = true;
		long long cnt = 0;
		for (int j = 0; j < a[u].size(); j++) {
			int y = a[u][j];
			if (v[y]) {
				cnt -= C2(c[F(y)]);
				U(u, y);
			}
		}
		cnt += C2(c[F(u)]);
		ansmin += cnt * b[i].first;
	}
	reverse(b, b + n);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		c[i] = 1;
	}
	memset(v, 0, sizeof v);
	for (int i = 0; i < n; i++) {
		int u = b[i].second;
		v[u] = true;
		long long cnt = 0;
		for (int j = 0; j < a[u].size(); j++) {
			int y = a[u][j];
			if (v[y]) {
				cnt -= C2(c[F(y)]);
				U(u, y);
			}
		}
		cnt += C2(c[F(u)]);
		ansmax += cnt * b[i].first;
	}
	printf("%lld\n", ansmin - ansmax);
	return 0;
}