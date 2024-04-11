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

const int INF = (int)1e6 + 4;
const int N = 500500;
const int B = 750;
//const int B = 4;
int n, m, k;
int a[N];
int b[N], c[N];
int pref[N];
bool inter[N];
int Q[N][2];
int pos[B + 5];
int d[B + 5][2];
int e[B + 5][2];
int f[B + 5][2];

bool used[N];
void dfs(int v) {
	used[v] = 1;
	for (int u = 0; u < n; u++) {
		if (u == v) continue;
		if (used[u]) continue;
		if ((v > u) ^ (a[v] < a[u]))
			dfs(u);
	}
}
int slow() {
	for (int i = 0; i < n; i++)
		used[i] = false;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		dfs(i);
		ans++;
	}
	return ans;
}

void calcD(int p) {
	d[p][0] = upper_bound(b, b + n + 1, -a[pos[p]]) - b;
	d[p][1] = lower_bound(c, c + n + 1, -a[pos[p]]) - c;
}

int calcAns() {
	e[k][0] = n + 1;
	for (int i = k - 1; i > 0; i--) {
		e[i][0] = min(e[i + 1][0], d[i][0]);
	}
	e[0][1] = 0;
	for (int i = 1; i < k; i++) {
		e[i][1] = max(e[i - 1][1], d[i][1]);
	}
	f[0][0] = INF;
	for (int i = 1; i < k; i++) {
		f[i][0] = min(f[i - 1][0], a[pos[i]]);
	}
	f[k][1] = 0;
	for (int i = k - 1; i > 0; i--) {
		f[i][1] = max(f[i + 1][1], a[pos[i]]);
	}
	/*
	eprintf("f:\n");
	for (int i = 0; i <= k; i++)
		eprintf("%d ", f[i][0]);
	eprintf("\n");
	for (int i = 0; i <= k; i++)
		eprintf("%d ", f[i][1]);
	eprintf("\n");
	*/
	int ans = -1;
	for (int i = 0; i < k; i++) {
		if (f[i][0] < f[i + 1][1]) continue;
		int p = e[i][1], q = e[i + 1][0];
		p = max(p, pos[i] + 1);
		q = min(q, pos[i + 1] + 1);
		if (p < q) {
			ans += pref[q - 1];
			if (p > pos[i] + 1) ans -= pref[p - 1];
		}
//		eprintf("%d ", ans);
	}
//	eprintf("\n");
	return ans;
}

void solve(int L, int R) {
	for (int i = 0; i < n; i++)
		inter[i] = false;
	for (int i = L; i < R; i++) {
		inter[Q[i][0]] = true;
	}
	b[0] = INF;
	for (int i = 0; i < n; i++) {
		b[i + 1] = b[i];
		if (!inter[i])
			b[i + 1] = min(b[i + 1], a[i]);
	}
	c[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		c[i] = c[i + 1];
		if (!inter[i])
			c[i] = max(c[i], a[i]);
	}
	k = 0;
	pos[k++] = -1;
	for (int i = 0; i < n; i++)
		if (inter[i])
			pos[k++] = i;
	pos[k] = n;
/*	
	eprintf("pos:\n");
	for (int i = 0; i <= k; i++)
		eprintf("%d ", pos[i]);
	eprintf("\n");
	eprintf("pref:\n");
*/	
	for (int i = 0; i < k; i++) {
		int bal = 0;
		for (int j = pos[i] + 1; j <= pos[i + 1]; j++) {
			if (b[j] >= c[j]) bal++;
			pref[j] = bal;
//			eprintf("%d ", bal);
		}
//		eprintf("\n");
	}
	for (int i = 0; i <= n; i++) {
		b[i] = -b[i];
		c[i] = -c[i];
	}
	for (int i = 1; i < k; i++)
		calcD(i);
	for (int i = L; i < R; i++) {
		a[Q[i][0]] = Q[i][1];
		int pp = lower_bound(pos, pos + k, Q[i][0]) - pos;
		calcD(pp);
		int ans = calcAns();
//		int sl = slow();
		printf("%d\n", ans);
		/*
		if (ans != sl) {
			printf("ans = %d, sl = %d\n", ans, sl);
			throw;
		}
		*/
	}
}

void read() {
/*	
	int C = 100;
	n = 10;
	m = 100;
	for (int i = 0; i < n; i++)
		a[i] = abs((int)rng()) % C + 1;
	for (int i = 0; i < m; i++) {
		Q[i][0] = abs((int)rng()) % n;
		Q[i][1] = abs((int)rng()) % C + 1;
	}
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < m; i++)
		printf("%d %d\n", Q[i][0] + 1, Q[i][1]);
	return;
*/	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &Q[i][0], &Q[i][1]);
		Q[i][0]--;
	}

}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();

	for (int i = 0; i * B < m; i++)
		solve(i * B, min(m, (i + 1) * B));

	return 0;
}