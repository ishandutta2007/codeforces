/*input
6
2
4 6 3 3 5 6
2 6 3 6 5 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n;
	cin >> n;
	int M;
	cin >> M;
	int a[n + 1];
	int b[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	vector<int>skr;
	skr.push_back(a[1]);
	for (int i = 2; i <= n; i++)
	{
		skr.push_back(a[i]);
		skr.push_back(b[i]);
	}
	skr.push_back(b[1]);
	ld lo = 0;
	ld hi = 1e10;
	while (abs(hi - lo) > 1e-8)
	{
		ld g = (lo + hi) * 0.5;
		ld K = g;
		for (ld i : skr)
		{
			K -= ld(M + K) / ld(i);
			if (K < 0)
				break;
		}
		if (K <= 0)
			lo = g;
		else
			hi = g;
	}
	ld m = (lo + hi) * 0.5;
	if (m >= 2e9)
	{
		cout << "-1\n";
		return 0;
	}
	cout << fixed << setprecision(19) << m << "\n";
}