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

const int N = 100100;

int MASK = (1 << 26) - 1;
char s[N];
int ans = -1;

int getMask() {
	int mask = 0;
	int L = strlen(s);
	for (int i = 0; i < L; i++)
		mask |= 1 << (int)(s[i] - 'a');
	return mask;
}

bool check(int mask) {
	for (int k = 0; k < 26; k++)
		if (mask == (1 << k))
			return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		if (s[0] == '.') {
			scanf("%s", s);
			MASK &= ~getMask();
		} else if (s[0] == '!') {
			if (check(MASK)) ans++;
			scanf("%s", s);
			MASK &= getMask();
		} else {
			if (check(MASK)) ans++;
			scanf("%s", s);
			MASK &= ~getMask();
		}
	}
	ans = max(ans, 0);
	printf("%d\n", ans);

	return 0;
}