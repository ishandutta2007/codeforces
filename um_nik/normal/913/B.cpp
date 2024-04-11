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

const int N = 1010;
int n;
int a[N];
int par[N];
bool leaf[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		par[i] = x;
		leaf[x] = 0;
		leaf[i] = 1;
	}
	for (int i = 0; i < n; i++)
		if (leaf[i])
			a[par[i]]++;
	for (int i = 0; i < n; i++) {
		if (!leaf[i] && a[i] < 3) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");

	return 0;
}