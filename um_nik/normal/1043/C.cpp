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
char s[N];
int ans[N];
int cur;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = cur;
		if (s[i] == 'a') ans[i] ^= 1;
		cur ^= ans[i];
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}