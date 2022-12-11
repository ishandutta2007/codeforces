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

typedef long long ll;

const int N = (int)5e5 + 10;
ll gSize[N];
ll gSq[N];
ll delta[N];
int a[N];
vector <int> d[N];
bool used[N];

ll answer = 0;

void change(int id, int dt)
{
	int sz = (int)d[id].size();
	int value = a[id];
	for (int i = 0; i < sz; i++)
	{
		int x = d[id][i];
		ll sub = gSq[x] - delta[x];
		answer -= sub;
	}
	for (int i = 0; i < sz; i++)
	{
		int x = d[id][i];
		for (int s = 0; s < sz; s++)
		{
			int y = d[id][s];
			ll z = (ll)x * (ll)y;
			if (z > value)
				break;
			ll sub = (gSq[z] - delta[z]);
			delta[x] -= sub;
		}
	}
	for (int i = sz - 1; i >= 0; i--)
	{
		int x = d[id][i];
		gSize[x] += dt;
		gSq[x] = (gSize[x] * (gSize[x] - 1)) / 2;
		for (int s = 0; s < sz; s++)
		{
			int y = d[id][s];
			ll z = (ll)x * (ll)y;
			if (z > value)
				break;
			ll sub = (gSq[z] - delta[z]);
			delta[x] += sub;
		}
		answer += gSq[x] - delta[x];
	}
}

int n;

int gcd(int x, int y)
{
	return (y == 0 ? x : gcd(y, x % y));
}

ll simple()
{
	ll r = 0;
	for (int i = 0; i < n; i++)
		for (int s = i + 1; s < n; s++)
		{
			if (used[i] && used[s] && gcd(a[i], a[s]) == 1)
				r++;
		}
	return r;
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
	{
		scanf("%d", &a[i]);
		for (int s = 1; s * s <= a[i]; s++)
		{
			if (a[i] % s == 0)
			{
				if (s != 1)
					d[i].push_back(s);
				if (a[i] / s != s)
					d[i].push_back(a[i] / s);
			}
		}
		sort(d[i].begin(), d[i].end());
	}

	ll cnt = 0;
	for (int i = 0; i < q; i++)
	{
		int id;
		scanf("%d", &id);
		id--;
		if (used[id])
		{
			cnt--;
			change(id, -1);
			used[id] = 0;
		}
		else
		{
			cnt++;
			change(id, 1);
			used[id] = 1;
		}
		/*
		ll cur = cnt * (cnt - 1) / 2 - answer;
		if (cur != simple())
		{
			eprintf("query %d, wrong : given %lld, expected %lld\n", i, cur, simple());
			throw;
		}
		*/
		printf("%lld\n", cnt * (cnt - 1) / 2 - answer);
	}

	return 0;
}