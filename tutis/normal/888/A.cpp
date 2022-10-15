/*input
Danil_and_Olya
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i + 1 < n; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			ans++;
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			ans++;
	}
	cout << ans << "\n";
}