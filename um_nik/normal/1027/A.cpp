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

const int N = 11111;
int n;
char s[N];

void solve() {
	scanf("%d", &n);
	scanf("%s", s);
//	n = strlen(s);
	for (int i = 0; 2 * i < n; i++) {
		int x = (int)(s[i] - 'a'), y = (int)(s[n - 1 - i] - 'a');
		bool ok = false;
		for (int mask = 0; !ok && mask < 4; mask++) {
			int xx = x, yy = y;
			if (mask & 1)
				xx++;
			else
				xx--;
			if (mask & 2)
				yy++;
			else
				yy--;
			if (xx >= 0 && xx < 26 && xx == yy) {
				ok = true;
				s[i] = 'a' + xx;
				s[n - 1 - i] = 'a' + yy;
			}
		}
		if (!ok) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}