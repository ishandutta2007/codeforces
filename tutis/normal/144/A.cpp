/*input
4
33 44 11 22
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(ll n)
{
	while (n > 0)
	{
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int mx = *max_element(A, A + n);
	int mn = *min_element(A, A + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == mx)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				swap(A[j], A[j + 1]);
				ans++;
			}
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (A[i] == mn)
		{
			for (int j = i; j + 1 < n; j++)
			{
				swap(A[j], A[j + 1]);
				ans++;
			}
			break;
		}
	}
	cout << ans << "\n";
}