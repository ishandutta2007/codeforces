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
int n;
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;
		u--;
		a[v]++;
		a[u]++;
	}
	int V = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= 2) continue;
		if (V != -1) {
			printf("No\n");
			return 0;
		}
		V = i;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (int)(a[i] == 1);
	cnt++;
	cnt /= 2;
	printf("Yes\n%d\n", cnt);
	int U = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != 1) continue;
		if (U == -1) {
			U = i;
		} else {
			printf("%d %d\n", U + 1, i + 1);
			U = -1;
		}
	}
	if (U != -1) {
		if (V == -1) throw;
		printf("%d %d\n", U + 1, V + 1);
	}

	return 0;
}