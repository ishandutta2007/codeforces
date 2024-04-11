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

const int N = 300;
int n, m, k, t;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &k, &m, &t);
	k--;
	while(t--) {
		int w, p;
		scanf("%d%d", &w, &p);
		if (w == 0) {
			if (k < p) {
				n = p;
			} else {
				k -= p;
				n -= p;
			}
		} else {
			p--;
			if (p <= k) {
				k++;
			}
			n++;
		}
		printf("%d %d\n", n, k + 1);
	}

	return 0;
}