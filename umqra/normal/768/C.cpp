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
#include <cassert>
#include <complex>
#include <valarray>
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

const int N = 2000;
int cnt[N];
int new_cnt[N];
int n, k, x;

void perform()
{
	memset(new_cnt, 0, sizeof(new_cnt));
	int type = 1;
	for (int i = 0; i < N; i++)
	{
		if (type == 1)
		{
			int xored = (cnt[i] + 1) / 2;
			new_cnt[i ^ x] += xored;
			new_cnt[i] += cnt[i] - xored;
		}
		else
		{
			int xored = (cnt[i] / 2);
			new_cnt[i ^ x] += xored;
			new_cnt[i] += cnt[i] - xored;
		}
		type = (type + cnt[i]) % 2;
	}
	for (int i = 0; i < N; i++)
		cnt[i] = new_cnt[i];
}

int main()
{
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = 0; i < k; i++)
		perform();
	int min_value = N, max_value = 0;
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0)
			continue;
		min_value = min(min_value, i);
		max_value = max(max_value, i);
	}
	printf("%d %d\n", max_value, min_value);
	return 0;
}