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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a[4];
char s[4];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%s %d", s, &x);
		int mask = 0;
		if (s[0] == '1') mask += 1;
		if (s[1] == '1') mask += 2;
		a[mask].push_back(x);
	}
	if (a[1].size() < a[2].size()) swap(a[1], a[2]);
	nth_element(a[1].begin(), a[1].begin() + (int)a[1].size() - (int)a[2].size(), a[1].end());
	int ans = 0;
	for (int i = 0; i < (int)a[1].size(); i++) {
		if (i >= (int)a[1].size() - (int)a[2].size())
			ans += a[1][i];
		else
			a[0].push_back(a[1][i]);
	}
	nth_element(a[0].begin(), a[0].begin() + max(0, (int)a[0].size() - (int)a[3].size()), a[0].end());
	for (int i = max(0, (int)a[0].size() - (int)a[3].size()); i < (int)a[0].size(); i++)
		ans += a[0][i];
	for (int x : a[2])
		ans += x;
	for (int x : a[3])
		ans += x;
	printf("%d\n", ans);

	return 0;
}