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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 2020;
int n;
int a[N];
int ans = N;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	int cntOnes = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) cntOnes++;
	}
	if (cntOnes > 0) {
		printf("%d\n", n - cntOnes);
		return 0;
	}
	for (int l = 0; l < n; l++) {
		int x = a[l];
		int r = l + 1;
		while(r < n && x > 1) {
			x = gcd(x, a[r]);
			r++;
		}
		if (x > 1) continue;
		ans = min(ans, r - l);
	}
	if (ans == N) {
		printf("-1\n");
		return 0;
	}
	ans += n - 2;
	printf("%d\n", ans);

	return 0;
}