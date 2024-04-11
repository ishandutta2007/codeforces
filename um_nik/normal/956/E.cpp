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

const int N = 10010;
bool dp[N][2];
int a[N];
int n, m;
int L, R;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &L, &R);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = 0;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			for (int x = R; x >= a[i]; x--)
				dp[x][0] |= dp[x - a[i]][0];
		} else {
			a[m++] = a[i];
		}
	}
	n = m;
	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	for (int it = n - 1; it >= 0; it--) {
		for (int x = R; x >= a[it]; x--)
			dp[x][1] |= dp[x - a[it]][1];
		for (int x = 0; x <= R; x++)
			dp[x][1] |= dp[x][0];
		for (int x = R; x >= a[it]; x--)
			dp[x][0] |= dp[x - a[it]][0];
		sum -= a[it];
		bool ans = false;
		for (int x = L; x <= R - sum; x++) {
			if (dp[x][1]) {
				printf("%d\n", it + 1);
				return 0;
			}
			ans |= dp[x][0];
		}
		if (ans) {
			printf("%d\n", it);
			return 0;
		}
	}
	printf("0\n");

	return 0;
}