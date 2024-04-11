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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;
int n;
int a[N];
bool used[N];
int ans[N][2];
int ansSz;

void addEdge(int v, int u) {
	ans[ansSz][0] = v;
	ans[ansSz][1] = u;
	ansSz++;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d%d", &a[i], &x);
		if (x != n) {
			printf("NO\n");
			return 0;
		}
	}
	sort(a + 1, a + n);
	int cur = 1;
	int l = 1;
	while(l < n) {
		int r = l + 1;
		while(r < n && a[r] == a[l]) r++;
		int v = n;
		while(l < r - 1) {
			while(used[cur]) cur++;
			addEdge(v, cur);
			used[cur] = 1;
			v = cur;
			l++;
		}
		if (used[a[l]]) {
			printf("NO\n");
			return 0;
		}
		used[a[l]] = 1;
		addEdge(v, a[l]);
		l++;
	}
	printf("YES\n");
	for (int i = 0; i < n - 1; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}