#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 100100;
const int M = 201;
const int INF = (int)1e8;
int ans;
pii a[N];
int b[M];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ans = INF;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].X);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].Y);
	sort(a, a + n);
	reverse(a, a + n);
	int idx = 0;
	int idx2 = 0;
	for (int i = 0; i < n; i++)
		b[a[i].Y]++;
	int sum = 0;
	while(idx < n)
	{
		while(idx2 < n && a[idx].X == a[idx2].X)
		{
			b[a[idx2].Y]--;
			idx2++;
		}
		int cur = sum;
		int p = (n - idx2) - (idx2 - idx) + 1;
		int c = 0;
		while(p > 0)
		{
			int x = min(p, b[c]);
			cur += c * x;
			p -= x;
			c++;
		}
		ans = min(ans, cur);

		while(idx < idx2)
		{
			sum += a[idx].Y;
			idx++;
		}
	}
	printf("%d\n", ans);

	return 0;
}