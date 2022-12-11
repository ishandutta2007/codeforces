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
const int A = 26;
const int N = (int)1e6 + 10;

int add(int a, int b)
{
	a += b;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (ll)a * b % mod;
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

char str[N];
int pos[N];
int z[N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &pos[i]);
		pos[i]--;
	}
	int len = strlen(str);
	int l = 0, r = 0;
	for (int i = 1; i < len; i++)
	{
		if (i < r)
			z[i] = min(z[i - l], r - i + 1);
		while (str[i + z[i]] == str[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			l = i, r = i + z[i] - 1;
		}
	}
	int ans = 1;
	l = -1, r = -1;
	for (int i = 0; i < m; i++)
	{
		int p = pos[i];
		if (p > r)
			ans = mult(ans, myPow(A, p - r - 1));
		else
		{
			int inter = r - p + 1;
			if (z[len - inter] < inter)
				ans = 0;
		}
		l = p;
		r = p + len - 1;
	}
	cout << mult(ans, myPow(A, n - r - 1));
	return 0;
}