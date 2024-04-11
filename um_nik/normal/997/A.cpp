#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 300300;
int n;
char s[N];
ll x, y, ans;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld", &n, &x, &y);
	scanf("%s", s);
	ans = 0;
	if (s[0] == '0') ans++;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0' && s[i - 1] == '1')
			ans++;
	}
	if (ans == 0)
		printf("0\n");
	else
		printf("%lld\n", y + (ans - 1) * min(x, y));

	return 0;
}