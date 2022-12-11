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

const int N = (int)3e5 + 10;
ll arr[N];
int nextMin[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	ll minValue = *min_element(arr, arr + n);
	nextMin[n] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] == minValue)
			nextMin[i] = i;
		else
			nextMin[i] = nextMin[i + 1];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int nxt = nextMin[i + 1];
		if (nxt == n)
			nxt += nextMin[0];
		ans = max(ans, minValue * n + (nxt - i) - 1);
	}
	cout << ans << endl;
	return 0;
}