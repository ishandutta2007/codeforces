#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include <random>
#include <numeric>
#include <thread>
using namespace std;

#pragma warning(disable: 6031)

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a[4];
		scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
		int r[2] = { max(a[0], a[1]), max(a[2], a[3]) };
		sort(a, a + 4);
		sort(r, r + 2);
		if (a[2] == r[0] && a[3] == r[1]) printf("YES\n");
		else printf("NO\n");
	}
}