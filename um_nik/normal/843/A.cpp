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
pii a[N];
bool used[N];
vector<int> ans[N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	m = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		int x = i;
		while(!used[x]) {
			used[x] = 1;
			ans[m].push_back(x + 1);
			x = a[x].second;
		}
		m++;
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%d", (int)ans[i].size());
		for (int x : ans[i])
			printf(" %d", x);
		printf("\n");
	}

	return 0;
}