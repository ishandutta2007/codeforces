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

const int N = 110;
int n;
int a[N];

bool solve(int lb)
{
	priority_queue<pii> q;
	for (int i = 0; i < n; ++i)
		if (lb < a[i])
			q.emplace(a[i] - lb, i);
	if (q.size() == 0)
	{
		printf("%d\n0\n", lb);
		return true;
	}
	if (q.size() == 1)
		return false;
	vector<pii> ans;
	while (q.size() > 1)
	{
		auto f = q.top();
		q.pop();
		auto s = q.top();
		q.pop();
		ans.emplace_back(f.second, s.second);
		if (f.first > 1)
			q.emplace(f.first - 1, f.second);
		if (s.first > 1)
			q.emplace(s.first - 1, s.second);
	}
	int add = -1;
	if (q.size() != 0)
	{
		auto e = q.top();
		if (e.first > 1 || ans.back().first == e.second)
			return false;
		add = e.second;
	}
	printf("%d\n", lb);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i + 1 < ans.size(); ++i)
	{
		string out = string(n, '0');
		out[ans[i].first] = out[ans[i].second] = '1';
		puts(out.c_str());
	}
	string out = string(n, '0');
	if (add != -1)
		out[add] = '1';
	out[ans.back().first] = out[ans.back().second] = '1';
	puts(out.c_str());
	return true;
}

void solve()
{
	scanf("%d", &n);
	int mi = 111;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		mi = min(mi, a[i]);
	}
	for (int i = mi; i > 0; --i)
		if (solve(i))
			return;
	puts("0");
	int cnt = max(a[0], a[1]);
	for (int i = 2; i < n; ++i)
		cnt += a[i];
	printf("%d\n", cnt);
	for (int i = 0; i < max(a[0], a[1]); ++i)
	{
		printf("11");
		for (int j = 2; j < n; ++j)
			printf("0");
		puts("");
	}
	for(int i = 2; i < n; ++i)
		for (int j = 0; j < a[i]; ++j)
		{
			printf("1");
			for (int k = 1; k < i; ++k)
				printf("0");
			printf("1");
			for (int k = i + 1; k < n; ++k)
				printf("0");
			puts("");
		}
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