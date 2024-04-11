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

const int N = 1010101;
char s[N];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	int p = 0;
	while(p < n && s[p] == 'a') p++;
	int q = p;
	while(q < n && s[q] == 'b') q++;
	int t = q;
	while(t < n && s[t] == 'c') t++;
	if (t != n || p == 0 || q == p) {
		printf("NO\n");
		return 0;
	}
	if (t - q == p || t - q == q - p)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}