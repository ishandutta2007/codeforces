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
int l[N], r[N];

bool all_given() {
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &l[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &r[i]);
	int k = n + 1;
	while(!all_given()) {
		k--;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			if (l[i] < 0 || r[i] < 0) {
				printf("NO\n");
				return 0;
			}
			if (l[i] > 0 || r[i] > 0) continue;
			ok = true;
			a[i] = k;
		}
		for (int i = 0; i < n; i++) {
			if (used[i] || a[i] == 0) continue;
			used[i] = 1;
			for (int j = 0; j < n; j++) {
				if (a[j] != 0) continue;
				if (j < i)
					r[j]--;
				else
					l[j]--;
			}
		}
		if (!ok) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}