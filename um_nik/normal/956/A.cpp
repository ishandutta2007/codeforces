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

const int N = 55;
char s[N][N];
bool u1[N], u2[N];
int n, m;
bool a[N], b[N];

void dfsX(int x);
void dfsY(int y);

void dfsX(int x) {
	u1[x] = 1;
	a[x] = 1;
	for (int y = 0; y < m; y++)
		if (!u2[y] && s[x][y] == '#')
			dfsY(y);
}
void dfsY(int y) {
	u2[y] = 1;
	b[y] = 1;
	for (int x = 0; x < n; x++)
		if (!u1[x] && s[x][y] == '#')
			dfsX(x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int x = 0; x < n; x++) {
		if (u1[x]) continue;
		for (int i = 0; i < n; i++)
			a[i] = 0;
		for (int i = 0; i < m; i++)
			b[i] = 0;
		dfsX(x);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (!a[i] || !b[j]) continue;
				if (s[i][j] != '#') {
					printf("No\n");
					return 0;
				}
			}
	}
	printf("Yes\n");

	return 0;
}