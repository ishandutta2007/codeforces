/*input
100000 100000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
long long phi[100001 + 1];
void computeTotient(int n)
{
	// Create and initialize an array to store
	// phi or totient values
	for (int i = 1; i <= n; i++)
		phi[i] = i; // indicates not evaluated yet
	// and initializes for product
	// formula.

	// Compute other Phi values
	for (int p = 2; p <= n; p++)
	{
		// If phi[p] is not computed already,
		// then number p is prime
		if (phi[p] == p)
		{
			// Phi of a prime number p is
			// always equal to p-1.
			phi[p] = p - 1;

			// Update phi values of all
			// multiples of p
			for (int i = 2 * p; i <= n; i += p)
			{
				// Add contribution of p to its
				// multiple i by multiplying with
				// (1 - 1/p)
				phi[i] = (phi[i] / p) * (p - 1);
			}
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>X;
	for (int a = 2; a <= n; a++)
	{
		X.push_back({1, a});
		m--;
	}
	if (m < 0)
	{
		cout << "Impossible\n";
		return 0;
	}
	for (int a = 2; a <= n; a++)
	{
		if (m == 0)
			break;
		for (int x = 2; x < a; x++)
		{
			if (__gcd(x, a) == 1)
			{
				X.push_back({x, a});
				m--;
			}
			if (m == 0)
				break;
		}
		if (m == 0)
			break;
	}
	if (m == 0)
	{
		cout << "Possible\n";
		for (pair<int, int>a : X)
			cout << a.first << " " << a.second << "\n";
		return 0;
	}
	cout << "Impossible\n";

}