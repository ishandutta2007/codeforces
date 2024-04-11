#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int64_t n, m;
	cin >> n >> m;
	m=min(n, m);
	n -= m;
	int64_t d = m;
	int64_t liko = -1.0 + sqrtl(1.0 + 8.0 * (long double)n) / 2.0;
	while (liko * (liko + 1) > n * 2)
		liko--;
	while (liko * (liko + 1) < n * 2)
		liko++;
	cout << liko + d << endl;
	return 0;
}