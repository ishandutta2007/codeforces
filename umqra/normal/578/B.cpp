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

const int N = (int)2e5 + 100;
int cnt[100];
ll a[N];
ll ans = 0;

void changeCnt(ll value, int d)
{
	for (int s = 0; s < 62; s++)
	{
		if (value & (1LL << (ll)s))
			cnt[s] += d;
	}
}

void relaxAns()
{
	ll value = 0;
	for (int i = 0; i < 62; i++)
	{
		if (cnt[i] > 0)
			value |= (1LL << (ll)i);
	}
	ans = max(ans, value);
}

int main()
{
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll value = 1;
	for (int i = 0; i < k; i++)
		value *= x;
	for (int i = 0; i < n; i++)
		changeCnt(a[i], 1);
	for (int i = 0; i < n; i++)
	{
		changeCnt(a[i], -1);
		ll newValue = value * a[i];
		changeCnt(newValue, 1);
		relaxAns();
		changeCnt(newValue, -1);
		changeCnt(a[i], 1);
	}
	cout << ans << endl;
	return 0;
}