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

int A, B;

ll getSum(int pos)
{
	return (ll)A * (ll)pos + (ll)B * pos * (pos - 1) / 2;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d%d%d", &A, &B, &n);
	for (int i = 0; i < n; i++)
	{
		int l, m, t;
		scanf("%d%d%d", &l, &t, &m);
		int a = l - 1, b = l + (int)1e6 + 10;
		while (b - a > 1)
		{
			int mid = (a + b) / 2;
			ll value = A + (ll)(mid - 1) * B;
			ll sum = getSum(mid) - getSum(l - 1);
			ll x = max(value, (sum + m - 1) / m);
			if (x <= t)
				a = mid;
			else
				b = mid;
		}
		if (a == l - 1)
			puts("-1");
		else
			printf("%d\n", a);
	}
	return 0;
}