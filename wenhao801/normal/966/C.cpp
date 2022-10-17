#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define int long long
#define ll long long
inline ll read () {
	ll ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n; vector <ll> v[66], up, now;

signed main () {
	n = read(); ll i, j, k;
	for (i = 1; i <= n; i++) {
		ll x = read();
		for (j = -1, k = x; k; k >>= 1, ++j);
		v[j].push_back(x);
	}
	for (i = 59; i >= 0; i--) if (!v[i].empty()) {
		now.push_back(v[i][0]);
		int V = v[i].size(), U = up.size();
		for (j = 1, k = 0; j < V; j++) {
			while (k < U && (up[k] >> i) % 2 == 0) now.push_back(up[k]), ++k;
			if (k >= U) { puts("No"); return 0; }
			now.push_back(up[k++]); now.push_back(v[i][j]);
		}
		while (k < U) now.push_back(up[k++]);
		up.clear(); for (auto j: now) up.push_back(j); now.clear();
	}
	puts("Yes");
	for (auto i: up) printf("%lld ", i);
	return 0;
}