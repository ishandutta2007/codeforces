/*input
5
1 1 1 5 1
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
	for (int &i : a)
		cin >> i;
	ll suma = 0;
	for (int &i : a)
		suma += i;
	for (int k = (*max_element(a, a + n));; k++)
	{
		ll suma1 = n * k - suma;
		if (suma1 > suma)
		{
			cout << k << "\n";
			return 0;
		}
	}
}