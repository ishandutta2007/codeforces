#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}

// find a pair (c, d) s.t. ac + bd = gcd(a, b)
pair<ll, ll> extended_gcd(ll a, ll b) {
	if (b == 0) return{ 1, 0 };
	auto t = extended_gcd(b, a % b);
	return{ t.second, t.first - t.second * (a / b) };
}
// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
	return (extended_gcd(a, m).first % m + m) % m;
}

ll chinese_remainder(ll* a, ll* n, int size) {
	if (size == 1) return *a;
	ll tmp = modinverse(n[0], n[1]);
	ll tmp2 = (tmp * (a[1] - a[0]) % n[1] + n[1]) % n[1];
	ll ora = a[1];
	ll tgcd = gcd(n[0], n[1]);
	a[1] = a[0] + n[0] / tgcd * tmp2;
	n[1] *= n[0] / tgcd;
	ll ret = chinese_remainder(a + 1, n + 1, size - 1);
	n[1] /= n[0] / tgcd;
	a[1] = ora;
	return ret;
}

bool notprime[200005];
vector<int> primes;

void getprime()
{
	notprime[1] = true;
	for (int i = 2; i <= 200000; i ++)
	{
		if (notprime[i]) continue;
		primes.push_back(i);
		for (int j = i * 2; j <= 200000; j += i)
		{
			notprime[j] = true;
		}
	}
}

vector<ll> nn, mm;

ll solve2(int x, int y)
{
	vector<ll> num, mod;

	for (int i = 0; i < nn.size(); i++)
	{
		for (int j = 0; j < mm.size(); j++)
		{
			if (gcd(nn[i], mm[j]) == 1) continue;
			ll g = min(nn[i], mm[j]);
			if (x%g != y%g) return 1e18;
		}
	}

	for (int i = 0; i < nn.size(); i++)
	{
		int j;
		for (j = 0; j < mm.size(); j++)
		{
			if (gcd(nn[i], mm[j]) > 1 && nn[i] < mm[j]) break;
		}
		if (j == mm.size())
		{
			num.push_back(x % nn[i]);
			mod.push_back(nn[i]);
		}
	}

	for (int j = 0; j < mm.size(); j++)
	{
		int i;
		for (i = 0; i < nn.size(); i++)
		{
			if (gcd(nn[i], mm[j]) > 1 && mm[j] <= nn[i]) break;
		}
		if (i == nn.size())
		{
			num.push_back(y % mm[j]);
			mod.push_back(mm[j]);
		}
	}

	return chinese_remainder(&num[0], &mod[0], num.size());
}
int n, m, k;

void solve(int x, int y)
{
	ll ret = 1e18;
	ret = min(ret, solve2(x, y));
	ret = min(ret, solve2(x, 2*m-y));
	ret = min(ret, solve2(2*n-x, y));
	ret = min(ret, solve2(2*n-x, 2*m-y));

	if (ret >= 1e17) printf("-1\n");
	else printf("%lld\n", ret);
}


int main()
{
	getprime();
	scanf("%d%d%d", &n, &m, &k);
	{
		int n_ = n;
		n *= 2;
		for (int i = 0; i < primes.size() && notprime[n]; i++)
		{
			int cnt = 1;
			while (n % primes[i] == 0)
			{
				n /= primes[i];
				cnt *= primes[i];
			}

			if (cnt > 1)
			{
				nn.push_back(cnt);
			}
		}
		if (n > 1) nn.push_back(n);
		int m_ = m;

		m *= 2;
		for (int i = 0; i < primes.size() && notprime[m]; i++)
		{
			int cnt = 1;
			while (m % primes[i] == 0)
			{
				m /= primes[i];
				cnt *= primes[i];
			}

			if (cnt > 1)
			{
				mm.push_back(cnt);
			}
		}
		if (m > 1) mm.push_back(m);

		n = n_;
		m = m_;
	}
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		solve(a, b);
	}
}