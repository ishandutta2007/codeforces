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

const int N = 300300;
const int INF = 2 * N;
int a[N];
bool b[N];
int n;

bool evaluate(int x) {
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			int val = min(bal, a[i]);
			bal -= val;
			x -= val;
		} else {
			bal += a[i] / 10;
		}
	}
	return x <= 0;
}

bool suf(int x) {
	int oldx = x;
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = n - 1; x > 0 && i >= 0; i--) {
		b[i] = 1;
		x -= a[i];
	}
	return evaluate(oldx);
}
bool skip1(int x) {
	int oldx = x;
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = n - 1; x > 0 && i >= 0; i--) {
		b[i] = 1;
		x -= a[i];
	}
	int pos = 0;
	while(pos < n && (a[pos] != 10 || !b[pos])) pos++;
	if (pos == n)
		return false;
	x += a[pos];
	b[pos] = 0;
	pos--;
	while(pos >= 0 && b[pos]) pos--;
	if (evaluate(oldx)) return true;
	if (pos >= 0) {
		b[pos] = 1;
	}
	return evaluate(oldx);
}
bool take1(int x) {
	int oldx = x;
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = n - 1; x > 0 && i >= 0; i--) {
		if (x <= 20 && a[i] == 20) continue;
		x -= a[i];
		b[i] = 1;
	}
	return evaluate(oldx);
}

bool solve(int x) {
	return suf(x) || skip1(x) || take1(x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] /= 100;
	}
	int l = 0, r = INF;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	int ans = -l;
	for (int i = 0; i < n; i++)
		ans += a[i];
	printf("%d\n", ans * 100);

	return 0;
}