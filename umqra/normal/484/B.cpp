#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
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

const int MAXC = (int)1e6 + 10;
const int pow2 = (1 << 18);

vector <int> listValue[MAXC];
int it[MAXC];
bool used[MAXC];
int a[MAXC];
int cnt[MAXC];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		used[a[i]] = 1;
	}
	sort(a, a + n);

	n = unique(a, a + n) - a;
	for (int i = 0; i < n; i++)
		for (int s = a[i]; s < MAXC; s += a[i])
			it[s]++;
	for (int s = 0; s < MAXC; s++)
		if (it[s])
			listValue[s].resize(it[s]);
	for (int i = 0; i < n; i++)
	{
		for (int s = a[i]; s < MAXC; s += a[i])
		{
			listValue[s][it[s] - 1] = a[i];
			it[s]--;
		}
	}

	int ans = 0;
	int itMin = 0;
	for (int i = 1; i < MAXC; i++)
	{
		for (int s = 0; s < (int)listValue[i].size(); s++)
		{
			int x = listValue[i][s];
			int old = i - x;
			if (old > 0)
				cnt[old]--;
			cnt[i]++;
		}
		while (itMin < i && cnt[itMin] == 0)
			itMin++;
		if (used[i])
			ans = max(ans, i - itMin);
	}
	cout << ans;

	return 0;
}