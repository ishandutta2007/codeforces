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

const int N = 222;
int n;
int a[N];
int b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		b[i] = -1;
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
		if (b[a[i]] == -1)
			b[a[i]] = i;
	}
	int ans = 0;
	for (int i = 0; i < 2 * n; i++)
		for (int j = 0; j < i; j++)
			if (b[a[i]] < b[a[j]])
				ans++;
	printf("%d\n", ans);

	return 0;
}