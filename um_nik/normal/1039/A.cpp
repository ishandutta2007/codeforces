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

const int N = 200200;
int n;
ll t;
ll a[N];
ll b[N];
int c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &t);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		c[i]--;
		if (c[i] < i) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		b[i] = a[i] + t;
	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, c[i]);
		if (m > i)
			b[i] = max(b[i], a[i + 1] + t);
	}
	for (int i = 1; i < n; i++)
		b[i] = max(b[i], b[i - 1] + 1);

	int r = 0;
	for (int l = 0; l < n; l++) {
		if (r <= l) r = l + 1;
		while(r < n && a[r] + t <= b[r - 1]) r++;
		if (c[l] != r - 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 0; i < n; i++)
		printf("%lld ", b[i]);
	printf("\n");

	return 0;
}