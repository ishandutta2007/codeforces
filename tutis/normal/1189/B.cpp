/*input
3
2 4 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	clock_t pradzia = clock();
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mt19937_64 gen(123123);
	sort(a, a + n);
	deque<int>b;
	for (int i = 0; i < n; i += 2)
	{
		b.push_back(a[i]);
	}
	for (int i = 1; i < n; i += 2)
	{
		b.push_front(a[i]);
	}
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	while ((clock() - pradzia) * 10 <= 9 * CLOCKS_PER_SEC)
	{
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			ok &= a[(i + 1) % n] < (a[i] + a[(i + 2) % n]);
		}
		if (ok)
		{
			cout << "YES\n";
			for (int i : a)
				cout << i << " ";
			return 0;
		}
		shuffle(a, a + n, gen);
	}
	cout << "NO\n";
}