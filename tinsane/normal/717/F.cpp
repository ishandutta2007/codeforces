#pragma region Kek
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<ctime>
#include<cstring>
using namespace std;

#pragma comment(linker, "/STACK:17100500")

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 0
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#pragma endregion

//#define STRESS

const int N = 200500;
const int BLOCK = 500;
const int CNT = N / BLOCK + 1;
const ll INF = (ll)2e18;

int n, q;
ll seq[N];
ll max_odd[N], min_even[N], bal[N];
ll adding[N];
#ifdef STRESS
ll slow[N];
#endif

ll get(int i)
{
	return seq[i] + adding[i / BLOCK];
}

void build_block(int id)
{
	min_even[id] = INF;
	max_odd[id] = -INF;
	bal[id] = 0;
	for (int i = 0; i < BLOCK; i++)
	{
		ll e = get(id * BLOCK + i);
		if (i % 2 == 0)
		{
			bal[id] += e;
			min_even[id] = min(min_even[id], bal[id]);
		}
		else
		{
			bal[id] -= e;
			max_odd[id] = max(max_odd[id], bal[id]);
		}
	}
}

void query_add(int l, int r, int x)
{
	for (int i = l; i <= r; )
	{
		if (i % BLOCK != 0 || i + BLOCK - 1 > r)
		{
			int beg = max(i / BLOCK * BLOCK, l);
			int lim = min(i / BLOCK * BLOCK + BLOCK - 1, r);
			for (int i = beg; i <= lim; i++)
				seq[i] += x;
			build_block(i / BLOCK);
			i = lim + 1;
		}
		else
		{
			adding[i / BLOCK] += x;
			min_even[i / BLOCK] += x;
			i += BLOCK;
		}
	}
}

bool query_can(int l, int r)
{
	ll cur_bal = 0;
	for (int i = l; i <= r; )
	{
		if (i % BLOCK != 0 || i + BLOCK - 1 > r)
		{
			int beg = max(i / BLOCK * BLOCK, l);
			int lim = min(i / BLOCK * BLOCK + BLOCK - 1, r);
			for (int i = beg; i <= lim; i++)
			{
				if ((i - l) % 2 == 0)
				{
					cur_bal += get(i);
					if (cur_bal < 0)
						return false;
				}
				else
				{
					cur_bal -= get(i);
					if (cur_bal > 0)
						return false;
				}
			}
			i = lim + 1;
		}
		else
		{
			int id = i / BLOCK;
			if ((id * BLOCK - l) % 2 == 0)
			{
				if (cur_bal + min_even[id] < 0)
					return false;
				if (cur_bal + max_odd[id] > 0)
					return false;
				cur_bal += bal[id];
			}
			else
			{
				if (min_even[id] - cur_bal < 0)
					return false;
				if (max_odd[id] - cur_bal > 0)
					return false;
				cur_bal -= bal[id];
			}
			i += BLOCK;
		}
	}
	return cur_bal == 0;
}

#ifdef STRESS
void slow_add(int a, int b, int x)
{
	for (int i = a; i <= b; i++)
		slow[i] += x;
}
#endif

#ifdef STRESS
bool slow_can(int a, int b)
{
	int rem = slow[a];
	if (rem < 0)
		return false;
	for (int i = a + 1; i <= b; i++)
	{
		rem = slow[i] - rem;
		if (slow[i] < 0)
			return false;
		if (rem < 0)
			return false;
	}
	return rem == 0;
}
#endif

void solve()
{
#ifdef STRESS
	n = rand() % 20 + 1;
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		seq[i] = slow[i] = rand() % 10;
		printf("%lld ", seq[i] + 1);
	}
	printf("\n");
#else
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &seq[i]);
		seq[i]--;
	}
#endif

	for (int i = 0; i * BLOCK + BLOCK <= n; i++)
		build_block(i);

#ifdef STRESS
	q = rand() % 10 + 1;
	printf("%d\n", q);
#else
	scanf("%d", &q);
#endif
	for (int i = 0; i < q; i++)
	{
		int t, a, b;
#ifdef STRESS
		t = rand() % 2 + 1;
		a = rand() % n;
		b = rand() % n;
		if (a > b)
			swap(a, b);
		printf("%d %d %d\n", t, a, b);
#else
		scanf("%d%d%d", &t, &a, &b);
#endif
		if (t == 1)
		{
			int k;
#ifdef STRESS
			k = rand() % 10;
			printf("%d\n", k);
#else
			scanf("%d", &k);
#endif
			query_add(a, b, k);
#ifdef STRESS
			slow_add(a, b, k);
#endif
		}
		else
		{
			int ans = (int)query_can(a, b);
			printf("%d\n", ans);
#ifdef STRESS
			if (ans != slow_can(a, b))
				throw;
#endif
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#endif

#ifdef STRESS
	srand(31415);
	while (true)
	{
		printf("TEST\n");
		memset(adding, 0, sizeof(adding));
		solve();
	}
#else
	solve();
#endif

	eprintf("\n\nTime: %.3f\n", clock() * 1. / CLOCKS_PER_SEC);
}