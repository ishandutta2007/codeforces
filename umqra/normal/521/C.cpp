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

ll mod = (ll)1e9 + 7;
const int N = (int)1e5 + 100;
char str[N];
ll fact[N];
ll rFact[N];
ll sum[N];

ll myPow(ll x, ll k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return (x * myPow(x, k - 1)) % mod;
	ll t = myPow(x, k / 2);
	return (t * t) % mod;
}

void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 0; i < N; i++)
		rFact[i] = myPow(fact[i], mod - 2);
}

ll getC(int n, int k)
{
	if (n < k || n < 0 || k < 0)
		return 0;
	ll res = (fact[n] * rFact[k]) % mod;
	res = (res * rFact[n - k]) % mod;
	return res;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	init();
	int n, k;
	scanf("%d%d", &n, &k);
	scanf(" %s", str);

	ll pow10 = 1;
	for (int cnt = 1; cnt <= n; cnt++)
	{
		ll added = (getC(n - cnt - 1, k - 1) * pow10) % mod;
		sum[cnt] = (sum[cnt - 1] + added) % mod;

		pow10 = (pow10 * 10) % mod;
	}

	ll answer = 0;
	for (int i = 0; i < n; i++)
	{
		int d = str[i] - '0';
		int cnt = n - i - 1;
		answer = (answer + d * sum[cnt]) % mod;
	}
	ll number = 0;
	pow10 = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		int len = n - i;
		int d = str[i] - '0';
		number = (number + d * pow10) % mod;
		int newN = n - 1 - len;
		int newK = k - 1;
		if (i == 0)
		{
			newN = 0;
			newK = k;
		}

		ll value = (number * getC(newN, newK)) % mod;
		answer = (answer + value) % mod;
		pow10 = (pow10 * 10) % mod;
	}
	cout << answer;

	return 0;
}