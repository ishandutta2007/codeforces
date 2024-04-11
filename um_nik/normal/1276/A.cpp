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

const int N = 200200;
int n;
char s[N];
int ans[N];
int ansSz;

void solve() {
	scanf("%s", s);
	n = strlen(s);
	ansSz = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
			ans[ansSz++] = i + 1;
			s[i + 1] = '1';
		} else if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
			if (i + 3 == n || s[i + 3] != 'o') {
				ans[ansSz++] = i + 2;
				s[i + 2] = '1';
			} else {
				ans[ansSz++] = i + 1;
				s[i + 1] = '1';
			}
		}
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}