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

int main()
{
	int remain = 60 * 4;
	int n, k;
	scanf("%d%d", &n, &k);
	remain -= k;

	int ans = 0;
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		total += 5 * i;
		if (total > 60 * 4)
			break;
		remain -= 5 * i;
		if (remain < 0)
			break;
		ans = i;
	}
	printf("%d\n", ans);
	return 0;
}