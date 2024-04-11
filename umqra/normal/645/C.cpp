#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e5 + 10;
int sum[N];
char table[N];

int n, k;

bool check(int d)
{
	for (int i = 0; i < n; i++)
	{
		if (table[i] == '1')
			continue;
		int l = max(0, i - d);
		int r = min(n - 1, i + d);
		if (sum[r] - (l == 0 ? 0 : sum[l - 1]) >= k + 1)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf(" %s", table);
	for (int i = 0; i < n; i++)
	{
		sum[i] = (i == 0 ? 0 : sum[i - 1]);
		if (table[i] == '0')
			sum[i]++;
	}
	int l = 0, r = n;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%d\n", r);
	return 0;
}