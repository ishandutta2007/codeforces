#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 100;

ll a[N];
int l[N], r[N], x[N], y[N];
ll d[N];
ll addQ[N], delQ[N];
ll addA[N], delA[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d%d%I64d", &l[i], &r[i], &d[i]); 

	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		addQ[x[i] - 1]++;
		delQ[y[i] - 1]++;
	}

	ll cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cnt += addQ[i];

		addA[l[i] - 1] += cnt * d[i];
		delA[r[i] - 1] += cnt * d[i];

		cnt -= delQ[i];
	}

	ll resAdd = 0;
	for (int i = 0; i < n; i++)
	{
		resAdd += addA[i];

		printf("%I64d ", a[i] + resAdd);

		resAdd -= delA[i];
	}


	return 0;
}