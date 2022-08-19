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

const int N = (1 << 22) + 5;
int n, m;
bool used[N];
int cnt[N];

void add(int x, int d) {
	int Z = x & ((1 << m) - 1);
	int y = x - Z;
	Z ^= (1 << m) - 1;
	for(int z = Z; z > 0; z = (z - 1) & Z)
		cnt[y + (1 << m) - 1 - z] += d;
	cnt[y + (1 << m) - 1] += d;
}

void dfs(int x) {
//	cerr << "dfs " << x << endl;
	used[x] = 1;
	add(x, -1);
	x ^= (1 << n) - 1;
	int Z = x & ((1 << m) - 1);
	int Y = x - Z;
	for(int y = Y;; y = (y - 1) & Y) {
		while (cnt[y + Z] > 0) {
			int z = Z;
			for (int i = 0; i < m; i++) {
				if (((z >> i) & 1) && cnt[y + z ^ (1 << i)] > 0) z ^= 1 << i;
			}
			if (used[y + z]) throw;
			dfs(y + z);
		}
		if (y == 0) break;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < (1 << n); i++)
		used[i] = 1;
	while(m--) {
		int x;
		scanf("%d", &x);
		used[x] = 0;
	}
	m = n / 2;
	for (int x = 0; x < (1 << n); x++) {
		if (used[x]) continue;
		add(x, 1);
	}
	int ans = 0;
	for (int x = 0; x < (1 << n); x++) {
		if (!used[x]) {
			dfs(x);
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}