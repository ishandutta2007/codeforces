/**
1
5
1
1 5
**/
#define MOD (1000000007ll)
#define mod(x) (x%MOD)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std; int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int t = accumulate(A, A + n, 0);
	int m;
	cin >> m;
	int laik = INT_MAX;
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l <= t && t <= r)
		{
			cout << t << endl;
			return 0;
		}
		if (l > t)
			laik = min(laik, l);
	}
	if (laik != INT_MAX)
		cout << laik;
	else
		cout << -1;
}