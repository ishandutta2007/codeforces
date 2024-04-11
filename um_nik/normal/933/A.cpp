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

const int N = 2020;
int n;
int a[N];
int ans = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int z = 0; z <= n; z++) {
		int ans1 = 0, ans2 = 0;
		int sum = 0;
		for (int i = 0; i < z; i++)
			sum += (int)(a[i] == 1);
		ans1 = max(ans1, sum);
		for (int i = z - 1; i >= 0; i--) {
			if (a[i] == 1)
				sum--;
			else
				sum++;
			ans1 = max(ans1, sum);
		}
		sum = 0;
		for (int i = z; i < n; i++)
			sum += (int)(a[i] == 2);
		ans2 = max(ans2, sum);
		for (int i = z; i < n; i++) {
			if (a[i] == 1)
				sum++;
			else
				sum--;
			ans2 = max(ans2, sum);
		}
		ans = max(ans, ans1 + ans2);
	}
	printf("%d\n", ans);

	return 0;
}