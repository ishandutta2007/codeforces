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

map <ll, int> cnt;

int main()
{
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;
		cnt[sum]++;
	}
	int ans = n;
	for (auto e : cnt)
		ans = min(ans, n - e.Y);
	cout << ans << endl;
	return 0;
}