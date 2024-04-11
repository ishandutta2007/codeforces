#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e14;
const int N = 100100;
int n, m, k;
ll a[N];
ll h[N];
ll p;
int b[N];

void read()
{
	scanf("%d%d%d%I64d", &n, &m, &k, &p);
	for (int i = 0; i < n; i++)
		scanf("%I64d%I64d", &h[i], &a[i]);
	return;
}

bool check(ll val)
{
	for (int i = 0; i < n; i++)
		if (a[i] > val)
			return false;
	int cnt = 0;
	for (int i = 0; i <= m; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
	{
		ll w = val;
		ll t = 0;
		while(t < m)
		{
			ll tmp = w / a[i];
			t += tmp;
			if (t >= m)
			{
				t -= tmp;
				w -= a[i] * (m - t);
				break;
			}
			w %= a[i];
			while(w < a[i])
			{
				b[t]++;
				cnt++;
				w += p;
				if (cnt > m * k) return false;
			}
		}
		while(w < h[i])
		{
			b[m]++;
			cnt++;
			w += p;
			if (cnt > m * k) return false;
		}
	}
	int bal = 0;
	for (int i = 1; i <= m; i++)
	{
		bal += b[i];
		if (bal > i * k) return false;
	}
	return true;
}

ll solve()
{
	ll L = 0LL;
	ll R = INF;
	while(R - L > 1)
	{
		ll mid = (L + R) / 2;
		if (check(mid))
			R = mid;
		else
			L = mid;
	}
	return R;
}

int main()
{
	read();
//	check(14LL);
	printf("%I64d\n", solve());

	return 0;
}