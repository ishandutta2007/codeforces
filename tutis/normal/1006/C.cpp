/*input
3
4 1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll d[n];
	for (int i = 0; i < n; i++)
		cin >> d[i];
	ll ans = 0;
	ll sum1 = 0;
	ll sum3 = 0;
	int i = -1;
	int j = n;
	while (i < j)
	{
		i++;
		sum1 += d[i];
		while (j > 0 && sum3 < sum1)
		{
			j--;
			sum3 += d[j];
		}
		if (i < j && sum1 == sum3)
		{
			ans = max(ans, sum1);
		}
	}
	cout << ans << "\n";
}