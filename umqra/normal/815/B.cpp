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

const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 10;
vector <int> numbers;

int add(int a, int b)
{
	a += b;
	if (a < 0)
		return a + mod;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (1LL * a * b) % mod;
}

int my_pow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(a, my_pow(a, k - 1));
	int t = my_pow(a, k / 2);
	return mult(t, t);
}

int rev(int a)
{
	return my_pow(a, mod - 2);
}

int fact[N], r_fact[N];

void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = mult(i, fact[i - 1]);
	r_fact[N - 1] = rev(fact[N - 1]);
	for (int i = N - 2; i >= 0; i--)
		r_fact[i] = mult(r_fact[i + 1], i + 1);
}

int get_c(int n, int k)
{
	if (k > n || k < 0 || n < 0)
		return 0;
	return mult(fact[n], mult(r_fact[k], r_fact[n - k]));
}

int fold(int l, int r, int depth)
{
	int value = 0;
	for (int i = l; i < r; i++)
	{
		int offset = (i - l);
		int k, total;
		if (depth % 4 == 2)
			k = offset / 2, total = depth / 2 - 1;
		else
			k = offset / 2, total = depth / 2;
		if (depth % 4 == 2 || offset % 2 == 0)
		{
			int sign = (l % 2 == 1 && (i - l) % 2 == 1 && depth % 2 == 0 ? -1 : 1);
			value = add(value, sign * mult(get_c(total, k), numbers[i]));
		}
	}
	return value;
}

vector<int> fold(vector<int> seq, int &sign)
{
	vector <int> res = {};
	for (int i = 0; i < (int)seq.size() - 1; i++)
	{
		res.push_back(add(seq[i], sign * seq[i + 1]));
		sign = -sign;
	}
	return res;
}

int perfect_pyr(int n)
{
	int old = n;
	while ((n % 4 != 1 && n % 4 != 2) || (old - n) % 2 == 1)
		n--;
	return n;
}

int slow()
{
	int sign = 1;
	while (numbers.size() != 1)
	{
		numbers = fold(numbers, sign);
	}
	return numbers[0];
}

int main()
{
	init();
	int n;
	scanf("%d", &n);
	numbers = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);
	if (n < 4)
	{
		printf("%d\n", slow());
		return 0;
	}
	int d = perfect_pyr(n);
	vector <int> seq = {};
	int rem = n - d;
	for (int i = 0; i <= rem; i++)
	{
		int value = fold(i, i + d, d);
		seq.push_back(value);
	}

	int sign = -2LL * (((2LL * n - d + 1) * (d - 1)) & 1) + 1;
	while (seq.size() != 1)
		seq = fold(seq, sign);

	printf("%d\n", seq[0]);
#ifdef LOCAL
	int x = slow();
	eprintf("%d\n", x);
	assert(x == seq[0]);
#endif
	return 0;
}