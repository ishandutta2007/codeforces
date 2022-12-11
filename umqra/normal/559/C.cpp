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

const int mod = (int)1e9 + 7;
const int SZ = (int)3e5 + 10;
const int N = (int)2e3 + 10;

int add(int a, int b)
{
	a += b;
	if (a < 0)
		return a + mod;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return ((long long)a * b) % mod;
}

int myPow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(a, myPow(a, k - 1));
	int t = myPow(a, k / 2);
	return mult(t, t);
}

int fact[SZ], revFact[SZ];
int dp[N];
pii p[N];

int countPath(int w, int h)
{
	return mult(fact[w + h - 2], mult(revFact[w - 1], revFact[h - 1]));
}

void precalc()
{
	fact[0] = 1;
	revFact[0] = 1;
	for (int i = 1; i < SZ; i++)
	{
		fact[i] = mult(fact[i - 1], i);
		revFact[i] = myPow(fact[i], mod - 2);
	}
}


int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	precalc();
	int w, h, n;
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = mp(x, y);
	}

	int ans = countPath(w, h);
	sort(p, p + n);
	eprintf("%d\n", ans);
	for (int i = 0; i < n; i++)
	{
		dp[i] = countPath(p[i].X, p[i].Y);
		for (int s = 0; s < i; s++)
		{
			if (p[s].X <= p[i].X && p[s].Y <= p[i].Y)
				dp[i] = add(dp[i], -mult(dp[s], countPath(p[i].X - p[s].X + 1, p[i].Y - p[s].Y + 1)));
		}
		ans = add(ans, -mult(dp[i], countPath(h - p[i].X + 1, w - p[i].Y + 1)));
	}
	cout << ans;
	
	return 0;
}