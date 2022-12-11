#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
int a[N], b[N];
ull sumA[N], sumB[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	sort(a, a + n);
	sort(b, b + m);

	sumA[0] = a[0];
	for (int i = 1; i < n; i++)
		sumA[i] = sumA[i - 1] + a[i];
	sumB[0] = b[0];
	for (int i = 1; i < m; i++)
		sumB[i] = sumB[i - 1] + b[i];
	int cnt = 0;
	unsigned long long ans = (unsigned long long)1e19 + 1000;
	for (int i = n - 1; i >= 0; i--)
	{
		cnt++;
		ans = min(ans, (ull)cnt * sumB[m - 1] + (i == 0 ? 0 : sumA[i - 1]));
	}
	cnt = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		cnt++;
		ans = min(ans, (ull)cnt * sumA[n - 1] + (i == 0 ? 0 : sumB[i - 1]));
	}
	cout << ans;
	return 0;
}