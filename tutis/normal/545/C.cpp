/*input
5
1 2
2 1
5 10
10 9
19 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{

	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	pair<ll, ll>A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i].first >> A[i].second;
	sort(A, A + n);
	int v[n];
	fill_n(v, n, 0);//1 left 2 right
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			v[i] = 1;
			continue;
		}
		if (i == n - 1)
		{
			v[i] = 2;
			continue;
		}
		if (v[i - 1] != 2)
		{
			if (A[i - 1].first < A[i].first - A[i].second)
			{
				v[i] = 1;
				continue;
			}
		}
		if (v[i - 1] == 2)
		{
			if (A[i - 1].first + A[i - 1].second < A[i].first - A[i].second)
			{
				v[i] = 1;
				continue;
			}
		}
		if (A[i + 1].first > A[i].first + A[i].second)
			v[i] = 2;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (v[i] != 0)
			ans++;
	cout << ans << "\n";
}