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

const int N = (int)2e6 + 10;

struct State
{
	ll cnt, h;
	State () : cnt(), h() {}
	State (ll _c, ll _h) : cnt(_c), h(_h) {}
};

State q[N];
int c[N];
int l = N / 2, r = N / 2;
int n, k;

void initState()
{
	int last = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == n || c[i] != c[last])
		{
			q[r++] = State(i - last, c[last]);
			last = i;
		}
	}
}

void merge()
{
	while (r - l > 1)
	{
		if (q[r - 1].h == q[r - 2].h)
		{
			q[r - 2].cnt += q[r - 1].cnt;
			r--;
		}
		else
			break;
	}
	while (r - l > 1)
	{
		if (q[l].h == q[l + 1].h)
		{
			q[l + 1].cnt += q[l].cnt;
			l++;
		}
		else
			break;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	sort(c, c + n);
	initState();
	while (r - l > 2 && k > 0)
	{
		ll deltaBig = (q[r - 1].h - q[r - 2].h) * 1LL * q[r - 1].cnt;
		ll deltaSmall = (q[l + 1].h - q[l].h) * 1LL * q[l].cnt;
		
		ll delta = min({deltaBig, deltaSmall, 1LL * k});
		q[r - 1].h -= (delta / q[r - 1].cnt);
		ll remBig = (delta % q[r - 1].cnt);
		if (remBig != 0)
		{
			q[r - 1].h--;
			ll other = q[r - 1].cnt - remBig;
			q[r - 1].cnt = remBig;
			q[r] = State(other, q[r - 1].h + 1);
			r++;
		}

		q[l].h += (delta / q[l].cnt);
		ll remSmall = (delta % q[l].cnt);
		if (remSmall != 0)
		{
			q[l].h++;
			ll other = q[l].cnt - remSmall;
			q[l].cnt = remSmall;
			q[l - 1] = State(other, q[l].h - 1);
			l--;
		}
		k -= delta;
		merge();
	}

	if (r - l == 2 && k > 0)
	{
		ll rightHeight = (q[l + 1].h - (k / q[l + 1].cnt));
		ll leftHeight = (q[l].h + (k / q[l].cnt));
		if (leftHeight < rightHeight)
		{
			printf("%lld\n", rightHeight - leftHeight);
			return 0;
		}
		ll total = 1LL * q[l].cnt * q[l].h + 1LL * q[l + 1].cnt * q[l + 1].h;
		if (total % (q[l].cnt + q[l + 1].cnt) == 0)
		{
			puts("0");
			return 0;
		}
		puts("1");
		return 0;
	}
	printf("%lld\n", q[r - 1].h - q[l].h);
	return 0;
}