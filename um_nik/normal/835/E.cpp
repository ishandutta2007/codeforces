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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int query(vector<int> a)
{
	if (a.empty()) return 0;
	sort(a.begin(), a.end());
	printf("? %d", (int)a.size());
	for (int x : a)
		printf(" %d", x + 1);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int n, X, Y;
int ans1 = 0, ans2 = 0;
bool df[10];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &X, &Y);

	int p = -1;
	for (int i = 0; i < 10; i++) {
		vector<int> a;
		for (int x = 0; x < n; x++)
			if ((x >> i) & 1)
				a.push_back(x);
		if (query(a) != ((int)a.size() & 1) * X) {
			p = i;
			df[i] = 1;
		}
	}
	if (p == -1) throw;
	ans1 |= 1 << p;
	for (int i = 0; i < 10; i++) {
		if (i == p) continue;
		vector<int> a;
		for (int x = 0; x < n; x++) {
			if (((x >> p) & 1) == 0) continue;
			if ((x >> i) & 1)
				a.push_back(x);
		}
		if (query(a) != ((int)a.size() & 1) * X) {
			ans1 |= 1 << i;
			if (!df[i])
				ans2 |= 1 << i;
		} else {
			if (df[i])
				ans2 |= 1 << i;
		}
	}

	ans1++;
	ans2++;
	if (ans1 > ans2) swap(ans1, ans2);
	printf("! %d %d\n", ans1, ans2);
	fflush(stdout);

	return 0;
}