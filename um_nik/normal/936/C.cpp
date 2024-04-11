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

const int N = 6060;
int n;
char s[N];
char SS[] = "abcdef";
char p[N];
int ans[N];
int ansSz;

void makeShift(int x) {
	ans[ansSz++] = x;
	rotate(s, s + n - x, s + n);
	reverse(s, s + x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", p);
	for (int i = 0; i < n; i++) {
		int pos = i;
		while(pos < n && s[pos] != p[n - 1 - i]) pos++;
		if (pos == n) {
			printf("-1\n");
			return 0;
		}
		makeShift(n);
		makeShift(pos);
		makeShift(1);
	}
	for (int i = 0; i < n; i++)
		if (s[i] != p[i])
			throw;
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}