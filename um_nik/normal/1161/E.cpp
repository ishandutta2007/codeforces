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

const int N = 100100;
int n;
int toPrev[N];
int toPrev2[N];
int col[N];
int bord[N];
int m;
char s[N];
vector<int> ans[3];

void printAns() {
	printf("A %d %d %d\n", (int)ans[0].size(), (int)ans[1].size(), (int)ans[2].size());
	for (int i = 0; i < 3; i++) {
		for (int x : ans[i])
			printf("%d ", x + 1);
		printf("\n");
	}
	fflush(stdout);
}

void solve() {
	scanf("%d", &n);
	if (n == -1) exit(0);
	m = 0;
	for (int i = 1; i < n; i++)
		toPrev[i] = -1;
	if (n / 2 > 0) {
		printf("Q %d", n / 2);
		for (int i = 0; i < (n / 2) * 2; i++) {
			printf(" %d", i + 1);
		}
		printf("\n");
		fflush(stdout);
		scanf("%s", s);
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == '1')
				toPrev[2 * i + 1] = 0;
			else
				toPrev[2 * i + 1] = 1;
		}
	}
	if ((n - 1) / 2 > 0) {
		printf("Q %d", (n - 1) / 2);
		for (int i = 0; i < ((n - 1) / 2) * 2; i++) {
			printf(" %d", i + 2);
		}
		printf("\n");
		fflush(stdout);
		scanf("%s", s);
		for (int i = 0; i < (n - 1) / 2; i++) {
			if (s[i] == '1')
				toPrev[2 * i + 2] = 0;
			else
				toPrev[2 * i + 2] = 1;
		}
	}
	bord[m++] = 0;
	for (int i = 1; i < n; i++) {
		if (toPrev[i] == 1)
			bord[m++] = i;
	}
	bord[m] = n;
	for (int i = 0; i < 3; i++)
		ans[i].clear();
	if (m <= 2) {
		for (int i = 0; i < m; i++)
			for (int x = bord[i]; x < bord[i + 1]; x++)
				ans[i].push_back(x);
		printAns();
		return;
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 2; i < m; i++)
		toPrev2[i] = -1;
	for (int i = 0; i < m - 2; i++) {
		if (i % 4 == 0 || i % 4 == 1)
			cnt1++;
		else
			cnt2++;
	}
	if (cnt1 > 0) {
		printf("Q %d", cnt1);
		for (int i = 0; i < m - 2; i++) {
			if (i % 4 == 0 || i % 4 == 1) {
				printf(" %d %d", bord[i] + 1, bord[i + 2] + 1);
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%s", s);
		int k = 0;
		for (int i = 0; i < m - 2; i++) {
			if (i % 4 == 0 || i % 4 == 1) {
				if (s[k] == '1')
					toPrev2[i + 2] = 0;
				else
					toPrev2[i + 2] = 1;
				k++;
			}
		}
	}
	if (cnt2 > 0) {
		printf("Q %d", cnt2);
		for (int i = 0; i < m - 2; i++) {
			if (i % 4 == 2 || i % 4 == 3) {
				printf(" %d %d", bord[i] + 1, bord[i + 2] + 1);
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%s", s);
		int k = 0;
		for (int i = 0; i < m - 2; i++) {
			if (i % 4 == 2 || i % 4 == 3) {
				if (s[k] == '1')
					toPrev2[i + 2] = 0;
				else
					toPrev2[i + 2] = 1;
				k++;
			}
		}
	}
	col[0] = 0;
	col[1] = 1;
	for (int i = 2; i < m; i++) {
		if (toPrev2[i] == 0) {
			col[i] = col[i - 2];
		} else {
			col[i] = 0;
			while(col[i] == col[i - 1] || col[i] == col[i - 2]) col[i]++;
		}
	}
	for (int i = 0; i < m; i++)
		for (int x = bord[i]; x < bord[i + 1]; x++)
			ans[col[i]].push_back(x);
	printAns();
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