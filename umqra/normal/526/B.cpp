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

const int N = (int)1e5 + 10;
int cnt;

int light[N];
int maxLight[N];

void calc(int v)
{
	light[v] += light[v / 2];
	if (v >= cnt / 2)
	{
		maxLight[v] = light[v];
		return;
	}
	calc(2 * v);
	calc(2 * v + 1);
	maxLight[v] = max(maxLight[2 * v], maxLight[2 * v + 1]);
}

int ans = 0;

void solve(int v)
{
	if (v >= cnt / 2)
		return;
	int l = maxLight[2 * v];
	int r = maxLight[2 * v + 1];
	ans += abs(r - l);
	solve(2 * v);
	solve(2 * v + 1);
}


int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	cnt = (1 << (n + 1));
	for (int i = 2; i < cnt; i++)
		scanf("%d", &light[i]);

	calc(1);
	solve(1);
	cout << ans;

	return 0;
}