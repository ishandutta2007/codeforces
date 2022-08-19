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

const int N = 105;
char s[N][N];
int n, m, k;

char getC(int id) {
	if (id < 26) return 'A' + id;
	id -= 26;
	if (id < 26) return 'a' + id;
	id -= 26;
	return '0' + id;
}

int want(int tot, int k, int p) {
	return (tot / k) * p + min(p, tot % k);
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	int tot = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'R')
				tot++;
	int id = 0;
	int sum = 0;
	for (int x = 0; x < n; x++)
		for (int j = 0; j < m; j++) {
			int y = (x % 2 == 0 ? j : m - 1 - j);
			int cc = s[x][y] == 'R';
			s[x][y] = getC(min(id, k - 1));
			if (cc == 1) {
				sum++;
				if (sum == want(tot, k, id + 1)) id++;
			}
		}
	for (int i = 0; i < n; i++)
		printf("%s\n", s[i]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}