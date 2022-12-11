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

const int N = (int)1e5 + 100;
ll a[N];
int ansL[N], ansR[N];
int st[N];
ll diff[N];

ll solve(int x, int y)
{
	ll ans = 0;
	int r = 0;
	for (int i = x; i <= y - 1; i++)
	{
		while (r > 0 && diff[st[r - 1]] < diff[i])
			r--;
		ansL[i] = (r == 0 ? x : st[r - 1] + 1);
		st[r++] = i;
	}
	r = 0;
	for (int i = y - 1; i >= x; i--)
	{
		while (r > 0 && diff[st[r - 1]] <= diff[i])
			r--;
		ansR[i] = (r == 0 ? y : st[r - 1]);
		st[r++] = i;
	}
	for (int i = x; i < y; i++)
	{
		ans += 1LL * (i - ansL[i] + 1) * (ansR[i] - i) * diff[i];
	}
	return ans;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n - 1; i++)
		diff[i] = llabs(a[i + 1] - a[i]);

	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", solve(l - 1, r - 1));
	}
	return 0;
}