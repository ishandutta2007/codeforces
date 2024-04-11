#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int64_t a, b, c;
	cin >> a >> b >> c;
	int64_t n;
	cin >> n;
	int64_t cnt = 0;
	for (int64_t i = 0; i < n; i++)
	{
		int64_t x;
		cin >> x;
		if (b < x and x < c)
			cnt++;
	}
	cout << cnt;
}