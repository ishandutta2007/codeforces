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

const int N = 6000;
int color[N];
int cnt[N];

int ans[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &color[i]);
		color[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		int index = -1;
		for (int s = i; s < n; s++)
		{
			cnt[color[s]]++;
			if (index == -1 || (cnt[index] < cnt[color[s]]) || (cnt[index] == cnt[color[s]] && index > color[s]))
				index = color[s];
			ans[index]++;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}