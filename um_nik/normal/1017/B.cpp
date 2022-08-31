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

const int N = 100100;
char s[N], p[N];
int n;
ll a[4];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", p);
	for (int i = 0; i < n; i++) {
		int mask = 0;
		if (s[i] == '1')
			mask |= 1;
		if (p[i] == '1')
			mask |= 2;
		a[mask]++;
	}
	printf("%lld\n", a[0] * a[3] + a[1] * a[2] + a[0] * a[1]);

	return 0;
}