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

const int N = (int)1e6 + 7;
char s[N], p[N];
int n, m;

bool solve() {
	scanf("%s %s", s, p);
	n = strlen(s);
	m = strlen(p);
	int p1 = 0, p2 = 0;
	while(p1 < n) {
		if (p2 >= m) {
			return false;
		}
		int r1 = p1 + 1, r2 = p2 + 1;
		while(r1 < n && s[r1] == s[p1]) r1++;
		while(r2 < m && p[r2] == p[p2]) r2++;
		if (s[p1] != p[p2]) return false;
		if (r1 - p1 > r2 - p2) return false;
		p1 = r1;
		p2 = r2;
	}
	return p2 == m;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}