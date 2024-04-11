#include <iostream>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 500200;
int n;
ll m, d, s;
ll a[N];
pli ans[N];
int ansSz;
set<pli> setik;

bool Failed = false;
void Fail()
{
	Failed = true;
//	printf("IMPOSSIBLE\n");
}

bool isPoint(ll x)
{
	int id = lower_bound(a, a + n, x) - a;
	return id >= 0 && id < n && a[id] == x;
}

bool check()
{		
	ll sum = 0;
	for (int i = 0; i < ansSz; i++)
	{
		if (isPoint(sum))
			return false;
		sum += ans[i].first;
		if (i != 0 && ans[i].second == ans[i - 1].second)
			return false;
		if (isPoint(sum))
			return false;
		ll l = sum - ans[i].first;
		ll r = sum;
		if (ans[i].second == 0)
		{
			int id = lower_bound(a, a + n, l) - a;
			if (id >= 0 && id < n && a[id] <= r)
				return false;
		}
	}
	return sum == m;
}

void read()
{
	scanf("%d%lld%lld%lld", &n, &m, &s, &d);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
}

int tmp[N];
void gen()
{
	n = rand() % 5 + 1;
	m = rand() % 20 + n + 1;
	s = rand() % 20 + 1;
	d = rand() % 20 + 1;
	for (int i = 1; i <= m - 1; i++)
		tmp[i - 1] = i;
	random_shuffle(tmp, tmp + m - 1);
	for (int i = 0; i < n; i++)
		a[i] = tmp[i];
}

void printTest()
{
	printf("%d %lld %lld %lld\n", n, m, s, d);
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	puts("");
	fflush(stdout);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	Failed = false;
	setik.clear();
	ansSz = 0;

	sort(a, a + n);
	a[n] = 2 * m;
	int it = 0;
	ll x = 0;
	int r = 0;
	while(it < n)
	{
//			printf("x = %lld\n", x);
		if (a[it] - x - 1 < s)
		{
			Fail();
			break;
		}
		ans[ansSz++] = mp(a[it] - x - 1, 0);
		x = a[it] - 1;
//			printf("it = %d, x = %lld, r = %d\n", it, x, r);
		while(r < n && a[r] - x + 1 <= d)
		{
			ll len = a[r + 1] - a[r];
			setik.insert(mp(-len, r));
			r++;
		}
//		printf("r = %d\n", r);
		if (it > 0)
			setik.erase(mp(a[it - 1] - a[it], it - 1));
		if (setik.empty())
		{	
			Fail();
			break;
		}
		//printf("Test:\n");
		//for (auto e : setik)
		//	printf("%lld %d\n", e.first, e.second);
		int id = setik.begin()->second;
//			printf("it: %d, id: %d\n", it, id);
		ll y = a[id] + 1;
		ans[ansSz++] = mp(y - x, 1);
		while(it < id)
		{
			it++;
			setik.erase(mp(a[it - 1] - a[it], it - 1));
		}
		it++;
		x = y;
		r = max(r, it);
	}

	if (x < m)
		ans[ansSz++] = mp(m - x, 0);
	if (Failed)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for (int i = 0; i < ansSz; i++)
	{
		if (ans[i].second == 0)
			printf("RUN ");
		else
			printf("JUMP ");
		printf("%lld\n", ans[i].first);
	}


	return 0;
}