#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int P = 1e9 + 7;

inline int sum(int a, int b)
{
	a += b;
	if (a >= P)
		return a - P;
	return a;
}

inline int mul(int a, int b)
{
	return (ll) a * b % P;
}

inline int sub(int a, int b)
{
	return sum(a, P - b);
}

int bpow(int x, int p)
{
	int res = 1;
	for (; p; p /= 2)
	{
		if (p % 2 == 1)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

const int A = 1e6 + 10;
const int N = 2e5 + 10;
int least_divisor[A], cnt[A], real_add[A], primes_in_factor[A];
int n, k, q, primes[N], psi, ans, facts[N], facts_rev[N];

int cnk(int n, int k)
{
	return mul(facts[n], mul(facts_rev[k], facts_rev[n - k]));
}

void calc_real_add(int x, int d, int mult, int cnt)
{
	if (d == 1)
	{
		if (cnt & 1)
			real_add[x] -= x / mult;
		else
			real_add[x] += x / mult;
		return;
	}
	if (least_divisor[d] != least_divisor[d / least_divisor[d]])
		calc_real_add(x, d / least_divisor[d], mult * least_divisor[d], cnt + 1);
	calc_real_add(x, d / least_divisor[d], mult, cnt);
}

void sieve()
{
	for (int i = 0; i < A; ++i)
		least_divisor[i] = i;
	for (int i = 2; i < A; ++i)
	{
		if (least_divisor[i] == i)
		{
			primes[psi++] = i;
			primes_in_factor[i] = 1;
		}
		for (int j = 0; j < psi && primes[j] <= i && i * primes[j] < A; ++j)
		{
			least_divisor[i * primes[j]] = primes[j];
			primes_in_factor[i * primes[j]] = primes_in_factor[i] + 1;
		}
	}
	for (int i = 1; i < A; ++i)
		calc_real_add(i, i, 1, 0);
}

inline void apply(int div)
{
	if (cnt[div]++ >= k - 1)
		ans = sum(ans, mul(cnk(cnt[div] - 1, k - 1), real_add[div]));
}

void process(int x)
{
	int div = 1;
	for (; div * div < x; ++div)
		if (x % div == 0)
		{
			apply(div);
			apply(x / div);
		}
	if (div * div == x)
		apply(div);
}

void solve()
{
	sieve();
	facts[0] = 1;
	for (int i = 1; i < N; ++i)
		facts[i] = mul(facts[i - 1], i);
	for (int i = 0; i < N; ++i)
		facts_rev[i] = bpow(facts[i], P - 2);
	cin >> n >> k >> q;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		process(a);
	}
	for (int i = 0; i < q; ++i)
	{
		int a;
		cin >> a;
		process(a);
		cout << ans << '\n';
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}