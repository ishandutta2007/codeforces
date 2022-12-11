#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int N = 1000;
bool used[N];
bool inCycle[N];
int f[N];
ll lcm = 1;
int n;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void addLcm(ll s)
{
	ll g = gcd(s, lcm);
	s /= g;
	lcm *= s;
}

void getCycles(int v)
{
	for (int i = 0; i < n; i++)
		v = f[v];
	int sz = 0;
	if (inCycle[v])
		return;
	while (!inCycle[v])
	{
		sz++;
		inCycle[v] = 1;
		v = f[v];
	}
	addLcm(sz);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &f[i]);
		f[i]--;
	}

	for (int i = 0; i < n; i++)
		getCycles(i);
	int maxH = 0;
	for (int i = 0; i < n; i++)
	{
		int v = i;
		int curH = 0;
		while (!inCycle[v])
		{
			curH++;
			v = f[v];
		}
		maxH = max(maxH, curH);
	}

	ll result = lcm;
	while (result < maxH)
		result += lcm;
	cout << result;

	return 0;
}