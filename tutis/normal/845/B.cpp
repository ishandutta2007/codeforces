/***
111000
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(string X)
{
	if (X[0] + X[1] + X[2] != X[3] + X[4] + X[5])
		return false;
	return true;
}
int price(string x, string y)
{
	int ans = 0;
	for (int i = 0; i < 6; i++)
		if (x[i] != y[i])
			ans++;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string X;
	cin >> X;
	int ans = 6;
	for (char y0 = '0'; y0 <= '9'; y0++)
		for (char y1 = '0'; y1 <= '9'; y1++)
			for (char y2 = '0'; y2 <= '9'; y2++)
				for (char y3 = '0'; y3 <= '9'; y3++)
					for (char y4 = '0'; y4 <= '9'; y4++)
						for (char y5 = '0'; y5 <= '9'; y5++)
						{
							string y{y0, y1, y2, y3, y4, y5};
							if (lucky(y))
								ans = min(ans, price(X, y));
						}
	cout << ans;
}