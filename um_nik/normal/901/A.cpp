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
int a[N];
int b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i]);
	int pos = 0;
	while(pos < n && (a[pos] == 1 || a[pos + 1] == 1)) pos++;
	if (pos == n) {
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	b[0] = 1;
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i - 1];

	printf("0");
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++)
			printf(" %d", b[i - 1]);
	}
	printf("\n");

	printf("0");
	for (int i = 1; i <= n; i++) {
		if (i == pos + 1) {
			printf(" %d", b[i - 1] + 1);
			for (int j = 1; j < a[i]; j++)
				printf(" %d", b[i - 1]);
		} else {
			for (int j = 0; j < a[i]; j++)
				printf(" %d", b[i - 1]);
		}
	}
	printf("\n");

	return 0;
}