#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 20005;
const int maxT = 24 * 60 * 60 + 5;
const int inf = maxT + 5;

vector<int> add[maxT + 5], del[maxT + 5];
int ans[maxn], id[maxn], last[maxn], where[maxn];
int kv[maxn];
int n, m, T;

int main()
{
	scanf("%d%d%d", &n, &m, &T);
// 	n = m = 20000;
// 	T = 5432;
	for (int i = 0; i < n; i++)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int t = h * 60 * 60 + m * 60 + s;
// 		int t = rand() % (86400 - T);
		add[t].pb(i);
		del[t + T - 1].pb(i);
	}
	for (int i = 0; i < m; i++)
	{
		id[i] = -1;
		last[i] = inf;
	}
	int answer = 0;
	int kv_used = 0;
	bool ok = false;
	for (int i = 0; i <= maxT; i++)
	{
		for (auto x : add[i])
		{
			int wh = max_element(last, last + m) - last;
			if (id[wh] == -1)
			{
				id[wh] = answer++;
				kv_used++;
			}
			where[x] = wh;
			ans[x] = id[wh];
			kv[wh]++;
			last[wh] = i;
		}
		if (kv_used == m) ok = true;
		for (auto x : del[i])
		{
			int wh = where[x];
			kv[wh]--;
			if (kv[wh] == 0)
			{
				last[wh] = inf;
				id[wh] = -1;
				kv_used--;
			}
		}
	}
	if (!ok)
	{
		printf("No solution\n");
	} else
	{
		printf("%d\n", answer);
		for (int i = 0; i < n; i++) printf("%d\n", ans[i] + 1);
	}
	return 0;
}