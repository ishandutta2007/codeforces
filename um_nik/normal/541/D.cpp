#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair

const int L = (int)2e6;
const int N = (int)3e4;
bool pr[L];
int primes[L];
int primesSz = 0;
ll A;
ll d[N];
int n;
ll ps[N];
int m;
vector<ll> q[N];

bool isPrime(ll x)
{
	if (x < L)
		return pr[x];
	for (int i = 0; (ll)primes[i] * primes[i] <= x; i++)
		if (x % primes[i] == 0)
			return false;
	return true;
}

void init()
{
	for (int i = 2; i < L; i++)
		pr[i] = true;
	for (int x = 2; x < L; x++)
	{
		if (!pr[x]) continue;
		primes[primesSz++] = x;
		for (int y = x * 2; y < L; y += x)
			pr[y] = false;
	}
	return;
}

ll INF = (ll)1e13;
ll mult(ll x, ll y)
{
	x *= y;
	if (x > INF) return INF;
	return x;
}

ll myPow(ll x, int p)
{
	ll res = 1;
	for (int i = 0; i < p; i++)
		res = mult(res, x);
	return res;
}

ll getP(ll x)
{
	if (x == 1) return -1;
	if (isPrime(x)) return x;
	for (int Pow = 2; Pow <= 40; Pow++)
	{
		double tmp = pow((double)x, 1. / (double)Pow);
		ll z = (ll)tmp;
		for (ll s = z; s <= z + 2; s++)
			if (isPrime(s) && myPow(s, Pow) == x)
				return s;
	}
	return -1;
}

void read()
{
	cin >> A;
	for (ll x = 1; x * x <= A; x++)
	{
		if (A % x != 0) continue;
		d[n++] = x;
		ll y = A / x;
		if (x != y)
			d[n++] = y;
	}
	sort(d, d + n);
	pll r[N];
	int sz = 0;
	for (int i = 1; i < n; i++)
	{
		ll x = d[i] - 1;
		ll y = getP(x);
		if (y == -1) continue;
		r[sz++] = mp(y, d[i]);
	}
	sort(r, r + sz);
	ll lst = -1;
	m = -1;
	for (int i = 0; i < sz; i++)
	{
		if (r[i].first != lst){
			m++;
			lst = r[i].first;
		}
		q[m].push_back(r[i].second);
	}
	m++;
	return;
}

ll dp[2][N];

void solve()
{
	dp[0][n - 1] = dp[1][n - 1] = 1;
	for (int it = 0; it < m; it++)
	{
		for (int i = 0; i < (int)q[it].size(); i++)
		{
			ll P = q[it][i];
			int idx = 0;
			for (int j = 0; j < n; j++)
			{
				if (dp[0][j] == 0) continue;
				if (d[j] % P != 0) continue;
				ll y = d[j] / P;
				while(d[idx] < y) idx++;
				dp[1][idx] += dp[0][j];
			}
		}

		for (int i = 0; i < n; i++)
			dp[0][i] = dp[1][i];
	}
	cout << dp[0][0] << endl;
}

int main()
{
	init();
	read();
	solve();

	return 0;
}