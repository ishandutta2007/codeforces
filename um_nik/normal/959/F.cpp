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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

const int N = 100100;
const int K = 20;
int p2[N];
vector<pii> q[N];
int n, m;
int a[N];
int b[K];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = add(p2[i - 1], p2[i - 1]);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int l, x;
		scanf("%d%d", &l, &x);
		q[l].push_back(mp(x, i));
	}

	for (int i = 0; i < K; i++)
		b[i] = -1;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 0; j < K; j++) {
			if (((x >> j) & 1) == 0) continue;
			if (b[j] == -1) {
				b[j] = x;
				break;
			}
			x ^= b[j];
		}
		int cnt = i + 1;
		for (int j = 0; j < K; j++)
			if (b[j] != -1)
				cnt--;
		for (pii t : q[i + 1]) {
			x = t.first;
			for (int j = 0; j < K; j++) {
				if ((x >> j) & 1) {
					if (b[j] == -1) break;
					x ^= b[j];
				}
			}
			if (x == 0)
				ans[t.second] = p2[cnt];
		}
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	return 0;
}