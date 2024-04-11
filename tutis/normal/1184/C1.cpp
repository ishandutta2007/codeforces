/*input
2
0 0
0 1
0 2
0 3
1 0
1 2
2 0
2 1
2 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n;
	cin >> n;
	n = 4 * n + 1;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int mxx = 51;
	for (int xa = -1; xa <= mxx; xa++)
	{
		for (int xb = xa + 1; xb <= mxx; xb++)
		{
			for (int ya = -1; ya <= mxx; ya++)
			{
				int yb = ya + xb - xa;
				int kiek = 0;
				int xx = -1;
				int yy = -1;
				for (int i = 0; i < n; i++)
				{
					bool ok = false;
					if (x[i] == xa || x[i] == xb)
						ok = true;
					if (y[i] == ya || y[i] == yb)
						ok = true;
					if (x[i] > xb || x[i] < xa)
						ok = false;
					if (y[i] > yb || y[i] < ya)
						ok = false;
					if (ok == false)
					{
						kiek++;
						xx = x[i];
						yy = y[i];
					}
				}
				if (kiek == 1)
				{
					cout << xx << " " << yy << endl;
					return 0;
				}
			}
		}
	}
}