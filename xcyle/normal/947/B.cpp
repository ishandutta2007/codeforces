#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;
const long long INF = 999999999999999;
int n;
long long v[maxn], t[maxn];
long long ans[maxn];
long long cnt[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
	for (int i = 1; i <= n; i++) t[i] += t[i - 1];
	t[n + 1] = INF;
	for (int i = 1; i <= n; i++)
	{
		int loc = lower_bound(t + 1, t + n + 1, v[i] + t[i - 1]) - t;
		ans[loc] += v[i] - (t[loc - 1] - t[i - 1]);
		cnt[i]++;
		cnt[loc]--;
	}
	long long now = 0;
	for (int i = 1; i <= n; i++)
	{
		now += cnt[i];
		printf("%lld ", now * (t[i] - t[i - 1]) + ans[i]);
	}
	return 0;
}