#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

int m;
typedef long long ll;
const int N = (int)1e6 + 10;

ll h[2], a[2], x[2], y[2];
bool used[2][N];
int cycle[2][N];
int sizeCycle[2];

void findCycle(int id)
{
	while (!used[id][h[id]])
	{
		cycle[id][sizeCycle[id]++] = h[id];
		used[id][h[id]] = 1;
		h[id] = (h[id] * x[id] + y[id]) % m;
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d", &m);
	scanf("%lld%lld%lld%lld", &h[0], &a[0], &x[0], &y[0]);
	scanf("%lld%lld%lld%lld", &h[1], &a[1], &x[1], &y[1]);

	for (int i = 0; i < m; i++)
	{
		for (int s = 0; s < 2; s++)
			h[s] = (h[s] * x[s] + y[s]) % m;
		if (h[0] == a[0] && h[1] == a[1])
		{
			printf("%d", i + 1);
			return 0;
		}
	}

	findCycle(0);
	findCycle(1);
	if (!used[0][a[0]] || !used[1][a[1]])
	{
		puts("-1");
		return 0;
	}

	ll tme = m;
	int shift1 = 0, shift2 = 0;
	for (int i = 0; i < sizeCycle[0]; i++)
	{
		if (cycle[0][i] == a[0])
		{
			shift1 = i;
			break;
		}
	}
	for (int i = 0; i < sizeCycle[1]; i++)
	{
		if (cycle[1][i] == a[1])
		{
			shift2 = i;
			break;
		}
	}


	tme += shift1;
	int delta = (sizeCycle[0] % sizeCycle[1]);
	int c = (shift1 % sizeCycle[1]);
	for (int i = 0; i < sizeCycle[1] + 1; i++)
	{
		if (c == shift2)
		{
			printf("%lld", tme);
			return 0;
		}
		c = (delta + c) % sizeCycle[1];
		tme += sizeCycle[0];
	}
	puts("-1");

	
	return 0;
}