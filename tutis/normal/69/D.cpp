/*input
0 0 2 3
1 1
1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int X, Y, n, d;
	cin >> X >> Y >> n >> d;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int XXX[500][500];
	for (int a = 0; a < 500; a++)
		for (int b = 0; b < 500; b++)
			XXX[a][b] = -1;
	function<int(int, int)>G = [&](int a, int b)
	{
		if (XXX[a + 200][b + 200] != -1)
			return XXX[a + 200][b + 200];
		bool vals[2] = {false, false};
		for (int i = 0; i < n; i++)
			if ((a + x[i]) * (a + x[i]) + (b + y[i]) * (b + y[i]) <= d * d)
				vals[G(a + x[i], b + y[i])] = true;
		for (int t = 0; t <= 1; t++)
			if (vals[t] == 0)
				return XXX[a + 200][b + 200] = t;
		return XXX[a + 200][b + 200] = 1;
	};
	if (G(X, Y) != 0)
		cout << "Anton\n";
	else
		cout << "Dasha\n";
}/**/