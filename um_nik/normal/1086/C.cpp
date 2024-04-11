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

const int N = (int)1e6 + 77;
const int A = 26;
int n, k;
char s[N];
int a[3][N];
bool used[A];
int ans[A];
bool oldUsed[A];
int oldAns[A];

bool trySet(int x, int y) {
	if (ans[x] == y) return true;
	if (ans[x] != -1) return false;
	if (used[y]) return false;
	ans[x] = y;
	used[y] = true;
	return true;
}

void printAns() {
	int cur = 0;
	for (int i = 0; i < k; i++) {
		if (ans[i] != -1) continue;
		while(used[cur]) cur++;
		used[cur] = 1;
		ans[i] = cur;
	}
	printf("YES\n");
	for (int i = 0; i < k; i++)
		printf("%c", (char)('a' + ans[i]));
	printf("\n");
}

void solve() {
	scanf("%d", &k);
	for (int p = 0; p < 3; p++) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; i++)
			a[p][i] = (int)(s[i] - 'a');
	}
	for (int i = 0; i < k; i++) {
		used[i] = false;
		ans[i] = -1;
	}
	int pos = 0;
	while(pos < n && a[1][pos] == a[2][pos]) {
		if (!trySet(a[0][pos], a[1][pos])) {
			printf("NO\n");
			return;
		}
		pos++;
	}
	if (pos == n) {
		printAns();
		return;
	}
	for (int i = a[1][pos] + 1; i < a[2][pos]; i++)
		if (trySet(a[0][pos], i)) {
			printAns();
			return;
		}
	for (int i = 0; i < k; i++) {
		oldAns[i] = ans[i];
		oldUsed[i] = used[i];
	}

	for (int i = 0; i < k; i++) {
		ans[i] = oldAns[i];
		used[i] = oldUsed[i];
	}
	if (trySet(a[0][pos], a[1][pos])) {
		bool ok = true;
		for (int i = pos + 1; ok && i < n; i++) {
			for (int j = a[1][i] + 1; j < k; j++)
				if (trySet(a[0][i], j)) {
					printAns();
					return;
				}
			ok &= trySet(a[0][i], a[1][i]);
		}
		if (ok) {
			printAns();
			return;
		}
	}

	for (int i = 0; i < k; i++) {
		ans[i] = oldAns[i];
		used[i] = oldUsed[i];
	}
	if (trySet(a[0][pos], a[2][pos])) {
		bool ok = true;
		for (int i = pos + 1; ok && i < n; i++) {
			for (int j = 0; j < a[2][i]; j++)
				if (trySet(a[0][i], j)) {
					printAns();
					return;
				}
			ok &= trySet(a[0][i], a[2][i]);
		}
		if (ok) {
			printAns();
			return;
		}
	}

	printf("NO\n");
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