/*input
01100010
00110
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int suma = 0;
	for (int i = 0; i < (int)b.size(); i++)
	{
		suma += (b[i] - '0');
		suma += (a[i] - '0');
	}
	int ans = 0;
	if (suma % 2 == 0)
		ans++;
	for (int i = b.size(); i < (int)a.size(); i++)
	{
		suma += a[i] - '0';
		suma += a[i - b.size()] - '0';
		if (suma % 2 == 0)
			ans++;
	}
	cout << ans << "\n";
}