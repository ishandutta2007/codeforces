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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll L, R;
const int N = 20;
const int A = 10;
int a[A];
int b[N];
int c[N];
int s[A];
int m;
int ans = 0;

bool solve()
{
	int cnt = 0;
	for (int i = 1; i < A; i++)
		cnt += a[i];
	if (cnt > m) return false;
	a[0] = m - cnt;
	int pos = m - 1;
	while(pos >= 0) {
		if (a[b[pos]] > 0) {
			c[pos] = b[pos];
			a[b[pos]]--;
			pos--;
			continue;
		}
		int minVal = A;
		for (int i = 0; i < A; i++)
			if (a[i] > 0)
				minVal = min(minVal, i);
		while(pos < m && minVal >= b[pos]) {
			pos++;
			if (pos == m) break;
			minVal = min(minVal, c[pos]);
			a[c[pos]]++;
		}
		if (pos == m) return false;
		int x = b[pos] - 1;
		while(x >= 0 && a[x] == 0) x--;
		if (x < 0) throw;
		c[pos] = x;
		a[x]--;
		pos--;
		x = A - 1;
		while(pos >= 0) {
			while(x >= 0 && a[x] == 0) x--;
			if (x < 0) throw;
			c[pos] = x;
			a[x]--;
			pos--;
		}
		break;
	}
	ll val = 0;
	for (int i = m - 1; i >= 0; i--)
		val = val * 10 + c[i];
	return val >= L;
}

void brute(int x, int lft)
{
	if (x == A) {
		if (lft == 18) return;
		for (int i = 0; i < A; i++)
			s[i] = a[i];
		ans += solve();
		for (int i = 0; i < A; i++)
			a[i] = s[i];
		return;
	}
	for (int i = 0; i <= lft; i++) {
		a[x] = i;
		brute(x + 1, lft - i);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> L >> R;
	while(R > 0) {
		b[m++] = R % 10;
		R /= 10;
	}
	brute(1, 18);
	cout << ans << endl;

	return 0;
}