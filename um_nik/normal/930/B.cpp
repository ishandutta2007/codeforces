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

const int N = 5050;
const int A = 26;
int a[A][N][A];
char s[N];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int L = j - i;
			if (L < 0) L += n;
			a[(int)(s[i] - 'a')][L][(int)(s[j] - 'a')]++;
		}
	int ans = 0;
	for (int i = 0; i < A; i++) {
		int bst = 0;
		for (int j = 1; j < n; j++) {
			int cur = 0;
			for (int k = 0; k < A; k++)
				if (a[i][j][k] == 1)
					cur++;
			bst = max(bst, cur);
		}
		ans += bst;
	}
	printf("%.12lf\n", (double)ans / n);

	return 0;
}