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

const int N = 111;
int n, m;
char s[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);

	if (n % 3 == 0) {
		int nn = n / 3;
		bool ok = true;
		if (s[0][0] == s[nn][0] || s[0][0] == s[2 * nn][0] || s[nn][0] == s[2 * nn][0])
			ok = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ok &= s[i][j] == s[(i / nn) * nn][0];
		if (ok) {
			printf("YES\n");
			return 0;
		}
	}

	swap(n, m);
	for (int i = 0; i < max(n, m); i++)
		for (int j = 0; j < i; j++)
			swap(s[i][j], s[j][i]);

	if (n % 3 == 0) {
		int nn = n / 3;
		bool ok = true;
		if (s[0][0] == s[nn][0] || s[0][0] == s[2 * nn][0] || s[nn][0] == s[2 * nn][0])
			ok = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ok &= s[i][j] == s[(i / nn) * nn][0];
		if (ok) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}