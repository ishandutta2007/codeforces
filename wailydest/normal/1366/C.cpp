#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 30;

void get(int n, int m, int a[N][N]) 
{
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", a[i] + j);
}
void getrt(int &n, int &m, int a[N][N]) 
{
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", a[j] + i);
	swap(n, m);
}

void testcase() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[N][N];
	if (n > m) getrt(n, m, a);
	else get(n, m, a);
	int ans = 0;
	for (int j = 0; j < (m + n - 1) / 2; ++j) {
		int k = 0, l = j;
		int cnt = 0;
		int bal = 0;
		while (k < n && l >= 0) {
			bal += a[k][l];
			++k;
			--l;
			++cnt;
		}
		k = n - 1;
		l = m - j - 1;
		while (k >= 0 && l < m) {
			bal += a[k][l];
			--k;
			++l;
		}
		ans += min(bal, cnt * 2 - bal);
	}
	printf("%d\n", ans);
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		testcase();
	}
	return 0;
}