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

const int A = 10;
const int N = (int)1e6 + 4;
char s[N];
int n;
int a[N];
int k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d %s", &k, s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[(int)s[i] - '0']++;
	for (int i = 0; i < A; i++)
		k -= i * a[i];
	int ans = 0;
	for (int i = 0; k > 0 && i < A - 1; i++) {
		int x = min(a[i], (k + (9 - i) - 1) / (9 - i));
		k -= x * (9 - i);
		ans += x;
	}
	printf("%d\n", ans);

	return 0;
}