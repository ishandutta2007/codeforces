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

bool rev;
int n, m;
vector<int> a[N];
int ans[N][2];

void printAns() {
	printf("YES\n");
	if (!rev) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf("%d ", a[i][j] + 1);
			printf("\n");
		}
		return;
	}
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			int xx = a[x][y] / m, yy = a[x][y] % m;
			printf("%d ", 1 + yy * n + xx);
		}
		printf("\n");
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	rev = false;
	if (n < m) {
		swap(n, m);
		rev = true;
	}
	for (int i = 0; i < n; i++)
		a[i].resize(m);

	if (m == 1) {
		if (n == 1) {
			printf("YES\n");
			printf("1\n");
			return 0;
		}
		if (n == 2 || n == 3) {
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for (int x = 2; x <= n; x += 2) {
			printf("%d", x);
			if (rev)
				printf(" ");
			else
				printf("\n");
		}
		for (int x = 1; x <= n; x += 2) {
			printf("%d", x);
			if (rev)
				printf(" ");
			else
				printf("\n");
		}
		if (rev) printf("\n");
		return 0;
	}

	if (n > 4 || m == 4) {
		vector<int> white, black;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				if ((x + y) % 2 == 0)
					white.push_back(x * m + y);
				else
					black.push_back(x * m + y);
			}
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				if (!white.empty()) {
					a[x][y] = white.back();
					white.pop_back();
				} else {
					a[x][y] = black.back();
					black.pop_back();
				}
			}
		printAns();
		return 0;
	}

	if (m == 2) {
		if (n <= 3) {
			printf("NO\n");
			return 0;
		}
		if (n == 4) {
			a[0][0] = 4;
			a[0][1] = 7;
			a[1][0] = 0;
			a[1][1] = 3;
			a[2][0] = 5;
			a[2][1] = 6;
			a[3][0] = 1;
			a[3][1] = 2;
			printAns();
		}
		return 0;
	}
	if (m == 3) {
		if (n == 3) {
			printf("YES\n");
			printf("6 1 8\n");
			printf("7 5 3\n");
			printf("2 9 4\n");
			return 0;
		}
		a[0] = {6, 4, 8};
		a[1] = {0, 10, 2};
		a[2] = {9, 1, 11};
		a[3] = {3, 7, 5};
		printAns();
		return 0;
	}
	throw;
	return 0;
}