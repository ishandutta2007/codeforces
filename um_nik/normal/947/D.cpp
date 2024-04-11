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
char s[N], t[N];
int n, m;
int sCntA[N], tCntA[N];
int sSumB[N], tSumB[N];

bool solve() {
	int l1, r1, l2, r2;
	scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
	l1--;
	l2--;
	int sb = sSumB[r1] - sSumB[l1], tb = tSumB[r2] - tSumB[l2];
	if ((sb + tb) & 1) return false;
	if (sb > tb) return false;
	int sa = min(r1 - l1, sCntA[r1 - 1]), ta = min(r2 - l2, tCntA[r2 - 1]);
	if (sa < ta) return false;
	if (tb == sb) {
		return sa % 3 == ta % 3;
	}
	if (sb == 0 && sa == ta) return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	for (int i = 0; i < n; i++) {
		sSumB[i + 1] = sSumB[i];
		if (s[i] == 'A') {
			sCntA[i] = (i > 0 ? sCntA[i - 1] : 0) + 1;
		} else {
			sSumB[i + 1]++;
		}
	}
	for (int i = 0; i < m; i++) {
		tSumB[i + 1] = tSumB[i];
		if (t[i] == 'A') {
			tCntA[i] = (i > 0 ? tCntA[i - 1] : 0) + 1;
		} else {
			tSumB[i + 1]++;
		}
	}

	int q;
	scanf("%d", &q);
	while(q--) {
		if (solve())
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	return 0;
}