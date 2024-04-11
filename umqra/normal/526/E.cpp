#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

int n;
const int N = (int)1e6 + 10;

int jump[N];
int rJump[N];
int longJump[N];
int rLongJump[N];
int cnt[N];
int rCnt[N];
ll a[N];
ll rA[N];
ll sum[N];

void calcJumps(ll *arr, int *j, int *lj, int* c, ll b)
{
	ll csum = 0;
	int it = 0;
	j[n] = lj[n] = n;
	c[n] = 0;
	for (int i = 0; i < n; i++)
	{
		while (it < n && csum + arr[it] <= b)
		{
			csum += arr[it];
			it++;
		}
		j[i] = it;
		csum -= arr[i];
		if (j[i] < n)
		{
			c[i] = 1;
			lj[i] = j[i];
		}
		else
		{
			lj[i] = i;
			c[i] = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int to = j[i];
		if (to < n && lj[to] < n)
		{
			lj[i] = lj[to];
			c[i] += c[to];
		}
	}
}


int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		rA[i] = a[i];
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];
	reverse(rA, rA + n);

	for (int i = 0; i < q; i++)
	{
		ll b;
		scanf("%lld", &b);
		calcJumps(a, jump, longJump, cnt, b);
		calcJumps(rA, rJump, rLongJump, rCnt, b);

		int ans = n;
		for (int s = 0; s < n; s++)
		{
			int to1 = longJump[s];
			int to2 = n - 1 - rLongJump[n - s];
			int cur = cnt[s] + rCnt[n - s];
			if (sum[n - 1] - (to1 < 0 ? 0 : sum[to1 - 1]) + (to2 < 0 ? 0 : sum[to2]) <= b)
				cur++;
			else
				cur += 2;
			ans = min(ans, cur);
		}
		printf("%d\n", ans);
	}

	return 0;
}