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

const int N = (int)1e6 + 7;
int n;
int a[N];
int ans;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) continue;
		ans ^= 1;
		int x = i;
		while(x != -1) {
			int y = a[x];
			a[x] = -1;
			x = y;
		}
	}
	if (ans)
		printf("Um_nik\n");
	else
		printf("Petr\n");

	return 0;
}