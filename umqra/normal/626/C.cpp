/*
	Team: Dandelion
	Room: 258
*/

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

bool check(int value, int a, int b)
{
	int cnt2 = value / 2;
	int cnt3 = value / 3;
	int cnt6 = value / 6;
	a -= cnt2 - cnt6;
	b -= cnt3 - cnt6;
	a = max(a, 0);
	b = max(b, 0);
	return a + b <= cnt6;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int l = 0, r = (int)1e9;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid, n, m))
			r = mid;
		else
			l = mid;
	}
	printf("%d\n", r);
	return 0;
}