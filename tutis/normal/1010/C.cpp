/*input
3 10
10 20 30
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	ll n, k;
	cin >> n >> k;
	bool gali[k];
	fill_n(gali, k, false);
	ll gcd = 0;
	while (n--)
	{
		ll a;
		cin >> a;
		if (a != 0)
			gcd = __gcd(gcd, a);
	}
	for (int i = 0; i <= k; i++)
		gali[(i * gcd) % k] = true;
	int kiek = 0;
	for (int i = 0; i < k; i++)
		if (gali[i])
			kiek++;
	cout << kiek << "\n";
	for (int i = 0; i < k; i++)
		if (gali[i])
			cout << i << " ";
}