#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int C = 200020;
const int Z = 100010;
const int N = 400100;

vector<pii> a[2];
int c[N][2];

void read() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x += Z;
		y += Z;
		if ((x + y) & 1) {
			x++;
			a[1].push_back(mp(x + y, x - y));
		} else {
			a[0].push_back(mp(x + y, x - y));
		}
	}
}

ll solve(vector<pii> b) {
	if (b.empty()) return 0;
	sort(b.begin(), b.end());
	/*
	for (pii t : b)
		printf("%d %d\n", t.first, t.second);
	*/
	for (int i = 0; i < N; i++) {
		c[i][0] = -N;
		c[i][1] = N;
	}
	int L = N, R = -N;
	int pos = 0;
	for (int x = 0; x < N; x++) {
		while(pos < (int)b.size() && b[pos].first < x) {
			L = min(L, b[pos].second + 1);
			R = max(R, b[pos].second - 1);
			pos++;
		}
		c[x][0] = max(c[x][0], L);
		c[x][1] = min(c[x][1], R);
	}
	pos = (int)b.size() - 1;
	L = N;
	R = -N;
	for (int x = N - 1; x >= 0; x--) {
		while(pos >= 0 && b[pos].first > x) {
			L = min(L, b[pos].second + 1);
			R = max(R, b[pos].second - 1);
			pos--;
		}
		c[x][0] = max(c[x][0], L);
		c[x][1] = min(c[x][1], R);
	}
	ll res = 0;
	for (int x = 0; x < N; x++) {
		if (x % 2 == 0) continue;
		if (c[x][0] > c[x][1]) continue;
		L = c[x][0];
		if (L % 2 == 0) L++;
		R = c[x][1];
		if (R % 2 == 0) R--;
		if (R >= L) res += 1 + (R - L) / 2;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ll ans = 0;
	ans += solve(a[0]);
	ans += solve(a[1]);
	printf("%lld\n", ans);

	return 0;
}