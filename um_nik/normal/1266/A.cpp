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

char s[111];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		int n = strlen(s);
		int z = 0, e = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int x = (int)(s[i] - '0');
			if (x == 0) z++;
			if (x % 2 == 0) e++;
			sum += x;
		}
		sum %= 3;
		if (z > 0 && e > 1 && sum == 0)
			printf("red\n");
		else
			printf("cyan\n");
	}

	return 0;
}