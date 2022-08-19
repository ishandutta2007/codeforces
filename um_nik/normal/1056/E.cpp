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

const int N = (int)1e6 + 7;
const int LOG = 20;
const int A = 30;
int b[N];
int SA[N], nSA[N];
int ord[N], nord[N];
int revSA[N];
int a[N];
int n, m;
int C0, C1;
int LCP[N];
int sparse[LOG][N];
int pp2[N];

void buildSA() {
	n++;
	for (int i = 0; i <= A; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++)
		a[b[i] + 1]++;
	for (int i = 0; i < A; i++)
		a[i + 1] += a[i];
	for (int i = 0; i < n; i++)
		SA[a[b[i]]++] = i;
	ord[SA[0]] = 0;
	for (int i = 0; i < n - 1; i++) {
		int p = SA[i], q = SA[i + 1];
		ord[q] = ord[p];
		if (b[p] != b[q])
			ord[q]++;
	}
	for (int len = 1; len < n; len <<= 1) {
		for (int i = 0; i <= n; i++)
			a[i] = 0;
		for (int i = 0; i < n; i++) {
			int p = SA[i];
			int q = (p + n - len);
			if (q >= n) q -= n;
			a[ord[q] + 1]++;
		}
		for (int i = 0; i < n; i++)
			a[i + 1] += a[i];
		for (int i = 0; i < n; i++) {
			int p = SA[i];
			int q = (p + n - len);
			if (q >= n) q -= n;
			nSA[a[ord[q]]++] = q;
		}
		nord[nSA[0]] = 0;
		for (int i = 0; i < n - 1; i++) {
			int p1 = nSA[i], p2 = nSA[i + 1];
			int q1 = p1 + len, q2 = p2 + len;
			if (q1 >= n) q1 -= n;
			if (q2 >= n) q2 -= n;
			nord[p2] = nord[p1];
			if (ord[p1] != ord[p2] || ord[q1] != ord[q2])
				nord[p2]++;
		}
		for (int i = 0; i < n; i++) {
			SA[i] = nSA[i];
			ord[i] = nord[i];
		}
	}
	for (int i = 0; i < n; i++)
		revSA[SA[i]] = i;
	int curLCP = 0;
	for (int i = 0; i < n; i++) {
		int p = revSA[i];
		if (p == n - 1) {
			curLCP = 0;
			continue;
		}
		curLCP--;
		if (curLCP < 0) curLCP = 0;
		int q = SA[p + 1];
		while(i + curLCP < n && q + curLCP < n && b[i + curLCP] == b[q + curLCP])
			curLCP++;
		LCP[p] = curLCP;
	}
/*
	for (int i = 0; i < n; i++)
		printf("%d ", SA[i]);
	printf("\n");
	
	for (int i = 0; i < n - 1; i++)
		printf("%d ", LCP[i]);
	printf("\n");
*/
}

int getMin(int l, int r) {
	int k = pp2[r - l];
	return min(sparse[k][l], sparse[k][r - (1 << k)]);
}
int getLCP(int L, int R) {
	if (L == R) throw;
	L = revSA[L];
	R = revSA[R];
	if (L > R) swap(L, R);
	return getMin(L, R);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	char s[N];
	char p[N];

	scanf("%s %s", p, s);
	n = strlen(s);
	m = strlen(p);

	for (int i = 0; i < n; i++)
		b[i] = (int)(s[i] - 'a') + 1;

	buildSA();
	n--;
	for (int i = 0; i < n; i++)
		sparse[0][i] = LCP[i];
	for (int k = 1; k < LOG; k++)
		for (int i = 0; i + (1 << k) <= n; i++)
			sparse[k][i] = min(sparse[k - 1][i], sparse[k - 1][i + (1 << (k - 1))]);

	for (int i = 2; i < N; i++)
		pp2[i] = pp2[i / 2] + 1;

	for (int i = 0; i < m; i++)
		b[i] = (int)(p[i] - '0');
	for (int i = 0; i < m; i++) {
		if (b[i] == 0)
			C0++;
		else
			C1++;
	}
	if (C0 == 0 || C1 == 0) throw;

	int ans = 0;

	for (int x = 1; x <= n; x++) {
		ll z = n - (ll)x * C0;
		if (z <= 0) continue;
		if (z % C1 != 0) continue;
		int y = z / C1;
		int F0 = -1, F1 = -1;
		int pos = 0;
		bool ok = true;
		for (int i = 0; ok && i < m; i++) {
			if (b[i] == 0) {
				if (F0 == -1)
					F0 = pos;
				else
					ok &= getLCP(F0, pos) >= x;
				pos += x;
			} else {
				if (F1 == -1)
					F1 = pos;
				else
					ok &= getLCP(F1, pos) >= y;
				pos += y;
			}
		}
		if (x == y)
			ok &= getLCP(F0, F1) < x;
		if (ok) ans++;
	}
	printf("%d\n", ans);

	return 0;
}