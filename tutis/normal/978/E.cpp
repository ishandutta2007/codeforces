/*input
4 10
2 4 1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, w;
	cin >> n >> w;
	ll suma = 0;
	ll nuo = 0;
	ll iki = w;

	while (n--)
	{
		ll a;
		cin >> a;
		suma += a;
		nuo = max(nuo, -suma);
		iki = min(iki, w - suma);
	}
	cout << max(0ll, iki - nuo + 1) << "\n";


}