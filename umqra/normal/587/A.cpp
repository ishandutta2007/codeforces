#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6 + 1000;
int cnt[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);
		cnt[b]++;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] %= 2;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += cnt[i];
	printf("%d\n", ans);
	return 0;
}