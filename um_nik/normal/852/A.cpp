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

const int N = 200200;
int n;
char s[N];
int a[N];
bool b[N];

int firstDig(int x) {
	while(x >= 10) x /= 10;
	return x;
}

void twoStep(int S) {
	for (int it = 0; it < 2; it++) {
		int m = 0;
		while(S > 0) {
			a[m++] = S % 10;
			S /= 10;
		}
		reverse(a, a + m);
		for (int i = 0; i < m; i++) {
			if (i > 0) printf("+");
			printf("%d", a[i]);
			S += a[i];
		}
		printf("\n");
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	if (n == 1 && s[0] == '0') throw;
	for (int i = 0; i < n; i++)
		a[i] = (int)(s[i] - '0');
	int S = 0;
	for (int i = 0; i < n; i++)
		S += a[i];
	if (S <= 180) {
		for (int i = 0; i < n; i++) {
			if (i > 0) printf("+");
			printf("%d", a[i]);
		}
		printf("\n");
		twoStep(S);
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
		b[i] = 1;
	int S1 = 0, S2 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (i & 1)
			S2 += a[i];
		else
			S1 += a[i];
	}
	int z = firstDig(S);
	if (z == 1)
		z = 2;
	else
		z = 1;
	if (S1 >= S2) {
		for (int i = 0; firstDig(S) != z; i += 2) {
			S += 9 * a[i];
			b[i] = 0;
		}
	} else {
		for (int i = 1; firstDig(S) != z; i += 2) {
			S += 9 * a[i];
			b[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (b[i])
			printf("+");
	}
	printf("\n");
	twoStep(S);

	return 0;
}