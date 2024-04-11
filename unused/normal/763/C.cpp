#include <bits/stdc++.h>
using namespace std;

int dat[100005];
bool f[300000];
unordered_set<int> st;

using ll = long long;
int m, n;

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

void printans(int a, int b, bool flip)
{
	if (flip) a = (a + 1ll * n * b) % m;
	printf("%d %d\n", a, b);
	exit(0);
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	if (n == m)
	{
		printf("0 1\n");
		return 0;
	}

	bool flip = false;

	if (n * 2 > m)
	{
		flip = true;
		for (int i = 0; i < n; i++) f[dat[i]] = true;
		int p = 0;
		for (int i = 0; i < m; i++)
		{
			if (f[i] == false) dat[p++] = i;
		}

		n = p;
	}

	if (n == 1) printans(dat[0], 1, flip);
	if (n == 2) printans(dat[0], (dat[1] + m - dat[0]) % m, flip);

	int aa = dat[0];
	for (int i = 0; i < n; i++)
	{
		dat[i] = (dat[i] + m - aa) % m;
		st.insert(dat[i]);
	}

	int cnt = n;
	for (int i = 0; i < n; i++)
	{
		cnt -= st.count((dat[i] + dat[1]) % m);
	}

	// d * cnt == a[1]
	int d = dat[1] * modinverse(cnt, m) % m;

	int found = -1;
	for (int i = 0; i < n; i++)
	{
		if (st.count((dat[i] + m - d) % m) == 0)
		{
			found = i;
			break;
		}
	}

	if (found == -1) printans(aa, d, flip);

	for (int i = 0, now = dat[found]; i < n; i++)
	{
		if (st.count(now) == 0)
		{
			printf("-1\n");
			return 0;
		}
		now = (now + d) % m;
	}

	printans((aa + dat[found]) % m, d, flip);
}