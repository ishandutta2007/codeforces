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

const int N = (int)5e6;
int d[N];
int a[N];
int n;
bool used[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 2; x < N; x++)
		d[x] = -1;
	for (int x = 2; x < N; x++) {
		if (d[x] != -1) continue;
		for (int y = x; y < N; y += x)
			if (d[y] == -1)
				d[y] = x;
	}
	/*
	int cnt = 0;
	for (int i = (int)1e5 + 1; i < N; i++)
		if (d[i] == i)
			cnt++;
	printf("%d\n", cnt);
*/
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int pos = 0;
	while(pos < n) {
		bool ok = true;
		int x = a[pos];
		while(x > 1) {
			ok &= !used[d[x]];
			x /= d[x];
		}
		if (ok) {
			x = a[pos];
			while(x > 1) {
				used[d[x]] = 1;
				x /= d[x];
			}
			pos++;
			continue;
		}
		while(!ok) {
			ok = true;
			a[pos]++;
			x = a[pos];
			while(x > 1) {
				ok &= !used[d[x]];
				x /= d[x];
			}
		}
		x = a[pos];
		while(x > 1) {
			used[d[x]] = 1;
			x /= d[x];
		}
		pos++;
		break;
	}

	int y = 2;
	while(pos < n) {
		while(d[y] != y || used[y]) y++;
		a[pos++] = y;
		y++;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}