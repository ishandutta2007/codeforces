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

const int N = 5002;
int n;
char s[N];
int z[N][N];
bool dp[N][N];

void calcZ(int p)
{
	int l = 0, r = 0;
	for (int i = p + 1; i < n; i++) {
		if (i < r)
			z[p][i] = min(r - i, z[p][p + (i - l)]);
		while(i + z[p][i] < n && s[p + z[p][i]] == s[i + z[p][i]]) z[p][i]++;
		if (i + z[p][i] > r) {
			l = i;
			r = i + z[p][i];
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);

	/*
	for (int i = 0; i < 5000; i++)
		s[i] = 'a';
	s[5000] = '\0';
	*/

	n = strlen(s);
	for (int i = 0; i < n; i++)
		calcZ(i);

	for (int i = 0; i < n; i++)
		dp[0][i] = dp[1][i] = 1;
	for (int len = 2; len <= n; len++)
		for (int l = 0; l + len <= n; l++) {
			int r = l + len;
			if (s[l] == s[r - 1])
				dp[len][l] = dp[len - 2][l + 1];
		}

	for (int it = 0; it < n; it++) {
		int cnt = 0;
		for (int len = 1; len <= n; len++)
			for (int l = 0; l + len <= n; l++)
				cnt += dp[len][l];
		printf("%d ", cnt);
		if (cnt == 0) {
			for (int i = it + 1; i < n; i++)
				printf("0 ");
			printf("\n");
			return 0;
		}
		for (int len = n; len > 0; len--) {
			int L = len / 2;
			for (int l = 0; l + len <= n; l++) {
				int r = l + len;
				dp[len][l] = (len >= 2) && z[l][r - len / 2] >= len / 2 && dp[L][l] && dp[L][r - len / 2];
			}
		}
	}
	printf("\n");

	return 0;
}