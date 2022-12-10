#pragma region Kek
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<ctime>
#include<cstring>
using namespace std;

#pragma comment(linker, "/STACK:17100500")

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 0
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#pragma endregion

const int P = 10007;

int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}

int mul(int a, int b)
{
	return (ll)a * b % P;
}

const int N = 1e5 + 10;
int n;
int a[N];
int ans = 0;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		ans = sum(ans, mul(a[i], a[n - 1 - i]));
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#endif

	solve();

	eprintf("\n\nTime: %.3f\n", clock() * 1. / CLOCKS_PER_SEC);
}