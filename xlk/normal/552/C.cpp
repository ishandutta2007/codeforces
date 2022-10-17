#include <bits/stdc++.h>
using namespace std;
bool F(int w, int m)
{
	while (m > 0)
	{
		if (m % w == 0 || m % w == 1)
		{
			m /= w;
		}
		else if (m % w == w - 1)
		{
			++m /= w;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int w, m;
	cin >> w >> m;
	cout << (F(w, m) ? "YES" : "NO") << endl;
	return 0;
}