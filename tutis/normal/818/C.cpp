/*input
2
2 2
2 1 1 1
1 2 2 2
1 0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int d, n, m;
	cin >> d >> n >> m;
	int x1[d];
	int x2[d];
	int y1[d];
	int y2[d];
	for (int i = 0; i < d; i++)
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	int L, R, T, B;
	cin >> L >> R >> T >> B;
	int l[n + 3];
	int r[n + 3];
	int t[m + 3];
	int b[m + 3];
	fill_n(l, n + 3, 0);
	fill_n(r, n + 3, 0);
	fill_n(t, m + 3, 0);
	fill_n(b, m + 3, 0);
	for (int i = 0; i < d; i++)
	{
		l[min(x1[i], x2[i])]++;
		r[max(x1[i], x2[i])]++;
		t[min(y1[i], y2[i])]++;
		b[max(y1[i], y2[i])]++;
	}
	for (int i = 1; i < n + 3; i++)
		l[i] += l[i - 1];
	for (int i = 1; i < m + 3; i++)
		t[i] += t[i - 1];
	for (int i = n + 1; i >= 0; i--)
		r[i] += r[i + 1];
	for (int i = m + 1; i >= 0; i--)
		b[i] += b[i + 1];
	for (int i = 0; i < d; i++)
	{
		if (l[max(x1[i], x2[i]) - 1] - (x1[i] != x2[i]) == L)
		{
			if (r[min(x1[i], x2[i]) + 1] - (x1[i] != x2[i]) == R)
			{
				if (t[max(y1[i], y2[i]) - 1] - (y1[i] != y2[i]) == T)
				{
					if (b[min(y1[i], y2[i]) + 1] - (y1[i] != y2[i]) == B)
					{
						cout << i + 1 << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "-1\n";
}