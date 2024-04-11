/*input
3
2 1 2
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
	sort(a, a + n);
	int suma = accumulate(a, a + n, 0);
	int sumb = 0;
	int k = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		suma -= a[i];
		sumb += a[i];
		k++;
		if (sumb > suma)
		{
			cout << k << '\n';
			return 0;
		}
	}
}