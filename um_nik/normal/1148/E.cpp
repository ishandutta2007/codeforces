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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 300300;
pii a[N];
int b[N];
int ans[2 * N][3];
int ansSz;
int n;
int st[N][2];
int stSz;

void addAns(int x, int y, int z) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ans[ansSz][2] = z;
	ansSz++;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		if (a[i].first < b[i]) {
			st[stSz][0] = a[i].second;
			st[stSz][1] = b[i] - a[i].first;
			stSz++;
		} else if (a[i].first > b[i]) {
			int x = a[i].first - b[i];
			while(x > 0) {
				if (stSz == 0) {
					printf("NO\n");
					return 0;
				}
				stSz--;
				if (st[stSz][1] <= x) {
					x -= st[stSz][1];
					addAns(st[stSz][0], a[i].second, st[stSz][1]);
				} else {
					addAns(st[stSz][0], a[i].second, x);
					st[stSz][1] -= x;
					stSz++;
					x = 0;
				}
			}
		}
	}
	while(stSz > 0) {
		stSz--;
		if (st[stSz][1] > 0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2]);

	return 0;
}