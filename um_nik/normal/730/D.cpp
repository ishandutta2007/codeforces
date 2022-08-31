#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int B = 100000;
const int N = 200200;
int n;
ll r;
ll ans = 0;
vector<ll> res;
ll a[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &r);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &a[j][i]);
	for (int i = 0; i < n; i++)
		if (a[i][0] > a[i][1])
		{
			printf("-1\n");
			return 0;
		}
	ll lst = 0;
	ll T = 0;
	for (int i = 0; i < n; i++)
	{
		ll x = a[i][0], y = a[i][1];
		ll t = min(lst, x);
		lst -= t;
		T += t;
		x -= t;
		y -= t;
		if (x * 2 <= y)
		{
			T += 2 * x;
			continue;
		}
		t = y - x;
		T += 2 * t;
		x -= t;
		y -= 2 * t;
		ll cnt = (y + r - 1) / r;
		if (ans + cnt <= (ll)B)
		{
			while(y > r)
			{
				res.push_back(T);
				T += r;
				y -= r;
				ans++;
			}
			res.push_back(T);
			lst = r - y;
			T += y;
			ans++;
		}
		else
		{
			ans += cnt;
			T += y;
			lst = r - (y % r);
			if (lst == r) lst = 0;
		}
	}
	printf("%lld\n", ans);
	if (ans <= (ll)B)
	{
		for (ll x : res)
			printf("%lld ", x);
		printf("\n");
	}

	return 0;
}