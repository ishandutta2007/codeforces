#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;
typedef pair<int, int> pii;
const int N = 105;

int n;
int a[N], d[N];
vector<pair<int, int>> elem;
int bef[N], aft[N];
bool in_aft[N];
int score;
vector<int> order;

int count_inside(int l, int r)
{
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		int x = in_aft[i] ? aft[i] : bef[i];
		if (l <= x && x <= r)
			res++;
	}
	return res;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &d[i]);

	for (int i = 0; i < n; i++)
	{
		elem.emplace_back(a[i], i);
		elem.emplace_back(a[i] + d[i], i);
	}
	sort(elem.begin(), elem.end(), [&](const pii &a, const pii &b)
	{
		if (a.first != b.first)
			return a.first > b.first;
		return a.second < b.second;
	});

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n; j++)
		{
			if (elem[j] == make_pair(a[i], i))
				bef[i] = j;
			if (elem[j] == make_pair(a[i] + d[i], i))
				aft[i] = j;
		}

	for (int i = 0; i < n; i++)
		if (bef[i] <= aft[i])
			order.push_back(i);
	sort(order.begin(), order.end(), [&](int a, int b)
	{
		return bef[a] < bef[b];
	});
	for (int i : order)
	{
		score += count_inside(bef[i], aft[i]);
		in_aft[i] = true;
	}

	order.clear();
	for (int i = 0; i < n; i++)
		if (bef[i] > aft[i])
			order.push_back(i);
	sort(order.begin(), order.end(), [&](int a, int b)
	{
		return bef[a] > bef[b];
	});
	for (int i : order)
	{
		score += count_inside(aft[i], bef[i]);
		in_aft[i] = true;
	}

	printf("%d\n", score);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}