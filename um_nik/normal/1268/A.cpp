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
char s[N];
char p[N];
int n, k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (i < k)
			p[i] = s[i];
		else
			p[i] = p[i - k];
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == p[i]) continue;
		ok = s[i] < p[i];
		break;
	}
	if (ok) {
		p[n] = '\0';
		printf("%d\n%s\n", n, p);
		return 0;
	}
	int pos = k - 1;
	while(pos >= 0 && p[pos] == '9') {
		p[pos] = '0';
		pos--;
	}
	if (pos < 0) {

	} else {
		p[pos]++;
		for (int i = k; i < n; i++)
			p[i] = p[i - k];
		p[n] = '\0';
		printf("%d\n%s\n", n, p);
		return 0;
	}
	printf("%d\n", n + 1);
	for (int i = 0; i < k; i++)
		printf("%d", (i % k == 0 ? 1 : 0));
	printf("\n");

	return 0;
}