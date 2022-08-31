#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 200200;
int n, m;
ll ans = 0;
ll a[N], b[N];
set<pli> setik;

void read()
{
	m = 1;
	scanf("%d", &n);
	while(n--)
	{
		ll x1, y1, x2, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		if (x1 <= y2 && y1 <= x2) continue;
		ans += x1 - y1 + x2 - y2;
		ll f = x1 + y1, s = x2 + y2;
		if (f <= s)
		{
			if (x1 > y2)
				ans += f - s;
			else
				ans += s - f;
			continue;
		}
		a[m] = f;
		b[m] = s;
		m++;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 1; i < m; i++)
		setik.insert(mp(-a[i], i));
	for (int it = 0; !setik.empty(); it++)
	{
		pli t = *setik.begin();
		setik.erase(setik.begin());
		if (it % 2 == 0)
			ans -= t.first;
		else
			ans += t.first;
		int id = t.second;
		if (id < 0) continue;
		setik.insert(mp(-b[id], -id));
	}
	if (abs(ans) % 2 == 1) throw;
	printf("%lld\n", ans / 2);

	return 0;
}