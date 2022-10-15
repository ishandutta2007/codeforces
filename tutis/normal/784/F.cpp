/*input
3 3 1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	clock_t pradzia = clock();
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n;
	cin >> n;
	int a[10];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n; i < 10; i++)
		a[i] = 1000 + i;
	while (double(clock() - pradzia) / CLOCKS_PER_SEC <= 1.5)
	{
		sort(a, a + 10);
		next_permutation(a, a + 10);
		while (!is_sorted(a, a + 10))
		{
			next_permutation(a, a + 10);
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}