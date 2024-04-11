/*input
2
11 8
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
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] += i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		a[i] -= i;
	if (!is_sorted(a, a + n) || *min_element(a, a + n) < 0)
	{
		cout << ":(\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}/**/