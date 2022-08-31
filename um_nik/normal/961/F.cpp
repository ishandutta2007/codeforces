/*
C.cpp
*/
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

const int N = (int)2e6 + 100;
int n;
char s[N];
int z[N];
pii st[N];
int m;
int ans[N];

int main()
{
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	for (int i = n - 1; i > 0; i--)
		s[2 * i] = s[i];
	for (int i = 1; i < 2 * n; i += 2)
		s[i] = s[2 * n - 1 - i];
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r)
			z[i] = min(r - i, z[l + r - i]);
		while (i - z[i] -1 >= 0 && s[i - z[i] - 1] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) {
			l = i - z[i] ;
			r = i + z[i] ;
		}
	}

	for (int i = 1; i < n; i += 2) {
		l = i - z[i];
		while (m > 0 && st[m - 1].first >= l) m--;
		st[m++] = mp(l, i);
	}
	for (int i = 0; i <= n; i++)
		ans[i] = -1;
	for (int i = 0; i < m; i++) {
		r = st[i].second;
		if (i + 1 < m) r = min(r, st[i + 1].first);
		for (int j = st[i].first; j < r; j++)
			ans[j] = st[i].second - j;
	}
	for (int i = 0; i < n; i += 2)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}