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

const int N = 111;
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
		a[i] = n;
	while(n--) {
		int k;
		scanf("%d", &k);
		while(k--) {
			int x;
			scanf("%d", &x);
			a[x]--;
		}
	}
	for (int i = 0; i < N; i++)
		if (a[i] == 0)
			printf("%d ", i);
	printf("\n");

	return 0;
}