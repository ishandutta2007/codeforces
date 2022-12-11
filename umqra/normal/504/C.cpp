#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

int cntNeg = 0;
int cntOdd = 0;

const int N = (int)1e5 + 10;

int cnt[N];
int a[N];

void add(int val)
{
	cnt[val] += 1;
	if (cnt[val] == 0)
		cntNeg--;
	if (cnt[val] % 2 == 0)
		cntOdd--;
	else
		cntOdd++;
}

void sub(int val)
{
	cnt[val] -= 1;
	if (cnt[val] == -1)
		cntNeg++;
	if (cnt[val] % 2 == 0)
		cntOdd--;
	else
		cntOdd++;
}
int locCnt[100];
int n;

bool check(int l, int r)
{
	memset(locCnt, 0, sizeof(locCnt));
	for (int i = l; i <= r; i++)
		locCnt[a[i]]++;
	for (int i = 0; i < n; i++)
	{
		int sim = n - i - 1;
		if ((sim < l || sim > r) && (i < l || i > r))
		{
			if (a[i] != a[sim])
				return false;
		}
	}
	for (int i = l; i <= r; i++)
	{
		int sim = n - i - 1;
		if (sim < l || sim > r)
			locCnt[a[sim]]--;
	}
	int cc = 0;
	for (int i = 0; i < 100; i++)
	{
		if (locCnt[i] < 0)
			return false;
		if (locCnt[i] % 2 == 1)
			cc++;
	}
	return cc <= 1;
}

int simple()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int s = i; s < n; s++)
			if (check(i, s))
			{
				ans++;
			}
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d", &n);

	int maxL = 0;
	int midL = (n - 1) / 2, midR = n / 2;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while (maxL < n && a[maxL] == a[n - maxL - 1])
		maxL++;
	while (midL >= 0 && a[midL] == a[midR])
	{
		midL--;
		midR++;
	}
	
	ll ans = 0;
	int r = -1;
	for (int i = 0; i < n; i++)
	{
		eprintf("IT = %d\n", i);
		int sim;
		while (r < n)
		{
			int x = min(i, n - r - 1);
			int y = min(midR, r) - max(midL, i) + 1;
			eprintf("cntNeg = %d, cntOdd = %d, i = %d, r = %d\n", cntNeg, cntOdd, i, r);
			if (i <= r && x <= maxL && cntNeg == 0 && cntOdd <= 1 && y > 0)
				break;
			r++;
			sim = n - r - 1;
			add(a[r]);
			if (sim < i || sim > r)
				sub(a[sim]);
			else if (sim != r)
				add(a[r]);
		}
		for (int s = 0; s < 2; s++)
			eprintf("cnt[%d] = %d\n", s, cnt[s]);
		ans += n - r;
		sim = n - i - 1;
		sub(a[i]);
		if (i + 1 <= sim && sim <= r)
			sub(a[i]);
		else
			add(a[sim]);
	}
	cout << ans;
	
	return 0;
}