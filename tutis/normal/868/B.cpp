/***
3 47 0 4 9
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	s *= 60 * 60;
	m *= 60 * 60;
	t1 *= 5 * 60 * 60;
	t2 *= 5 * 60 * 60;
	h *= 5 * 60 * 60;
	h = h + m / 60 + s / 3600;
	m = m + s / 60;
	s = s % 216000;
	m = m % 216000;
	h = h % 216000;
	t1 = t1 % 216000;
	t2 = t2 % 216000;
	while (t1 != t2)
	{
		int T = (t1 + 1) % 216000;
		if (T != h && T != m && T != s)
			t1 = T;
		else
			break;
	}
	while (t1 != t2)
	{
		int T = (t1 + 216000 - 1) % 216000;
		if (T != h && T != m && T != s)
			t1 = T;
		else
			break;
	}
	if (t1 == t2)
		cout << "YES";
	else
		cout << "NO";
}