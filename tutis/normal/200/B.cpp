/*input
3
50 50 100
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
	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		suma += a;
	}
	cout << fixed << setprecision(15) << ld(suma) / n << "\n";
}