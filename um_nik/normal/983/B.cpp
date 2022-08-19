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

const int N = 5005;
int n;
int a[N][N];
int b[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i][i + 1]);
		b[i][i + 1] = a[i][i + 1];
	}
	for (int len = 2; len <= n; len++)
		for (int l = 0; l + len <= n; l++) {
			int r = l + len;
			a[l][r] = a[l][r - 1] ^ a[l + 1][r];
			b[l][r] = max(a[l][r], max(b[l][r - 1], b[l + 1][r]));
		}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		printf("%d\n", b[l][r]);
	}	

	return 0;
}