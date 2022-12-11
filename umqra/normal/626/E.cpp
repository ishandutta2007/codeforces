/*
	Team: Dandelion
	Room: 258
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
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

const int N = (int)3e5 + 10;
int n;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct Fraction
{
	ll a, b;
	Fraction () : a(), b(1) {}
	Fraction (ll _a) : a(_a), b(1) {}
	Fraction (ll _a, ll _b)
	{
		a = _a;
		b = _b;
		ll g = gcd(llabs(a), llabs(b));
		a /= g;
		b /= g;
		if (b < 0)
		{
			a = -a;
			b = -b;
		}
	}
	Fraction operator / (const Fraction &x) const
	{
		return Fraction(a * x.b, b * x.a);
	}
	bool operator < (const Fraction &x) const
	{
		return a * x.b < b * x.a;
	}
	Fraction operator - (const Fraction &x) const
	{
		return Fraction(a * x.b - x.a * b, b * x.b);
	}
	void eprint()
	{
		eprintf("%lf\n", 1. * a / b);
	}
};

ll arr[N];
ll sum[N];

ll getSum(int pos)
{
	return pos < 0 ? 0 : sum[pos];
}

ll getSum(int l, int r)
{
	return getSum(r) - getSum(l - 1);
}

Fraction answer = Fraction(-1);
int ansA, ansB, ansLen;

void relaxAnswer(int a, int b, int len, Fraction X, Fraction Y)
{
	Fraction delta = X - Y;
	if (answer < delta)
	{
		answer = delta;
		ansA = a;
		ansB = b;
		ansLen = len;
	}
}

void getOptimalLen(int a, int b, int cnt, ll curSum)
{
	int l = 0, r = min(a, n - b);
	Fraction median = Fraction(curSum) / Fraction(cnt);
	while (r - l > 3)
	{
		int m = (l + r) / 2;
		Fraction c1 = Fraction((getSum(0, m - 1) + getSum(b, b + m - 1) + curSum)) / Fraction(cnt + 2 * m);
		Fraction c2 = Fraction((getSum(0, m) + getSum(b, b + m) + curSum)) / Fraction(cnt + 2 * (m + 1));
//		eprintf("Try length: %d\n", m);
		if (c1 < c2)
			l = m;
		else
			r = m;
	}
//	eprintf("[%d, %d): %d %d\n", a, b, l, r);
//	eprintf("Cur sum : %lld\n", curSum);
	for (int i = l; i <= r; i++)
	{
		Fraction c = Fraction((getSum(0, i - 1) + getSum(b, b + i - 1) + curSum)) / Fraction(cnt + 2 * i);
//		eprintf("i: %d\n", i);
//		c.eprint();
		relaxAnswer(a, b, i, c, median);
	}
}

void printSet()
{
	vector <ll> values = {};
	for (int i = ansA; i < ansB; i++)
		values.push_back(arr[i]);
	for (int i = 0; i < ansLen; i++)
		values.push_back(arr[i]);
	for (int i = ansB; i < ansB + ansLen; i++)
		values.push_back(arr[i]);
	sort(values.begin(), values.end());
	printf("%d\n", (int)values.size());
	for (ll x : values)
		printf("%lld ", x);
}

void solve()
{
	sum[0] = arr[0];
	for (int i = 1; i < n; i++)
		sum[i] += sum[i - 1] + arr[i];

	for (int i = 0; i < n; i++)
	{
		getOptimalLen(i, i + 1, 1, arr[i]);	
	}
	for (int i = 0; i < n - 1; i++)
	{
		getOptimalLen(i, i + 2, 2, arr[i] + arr[i + 1]);
	}
#ifdef LOCAL
	printf("%.10lf\n", answer.a * 1. / answer.b);
#endif
	printSet();
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	reverse(arr, arr + n);
	solve();
	return 0;
}