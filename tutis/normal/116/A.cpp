/*input
4
0 3
2 5
4 2
4 0
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
	int maxi = 0;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		suma -= a;
		suma += b;
		maxi = max(maxi, suma);
	}
	cout << maxi << "\n";
}