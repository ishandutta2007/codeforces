/*input
10
rocesfedoc
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string a;
	cin >> a;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			for (int b = 0; b < i && b <= i - 1 - b; b++)
				swap(a[b], a[i - 1 - b]);
		}
	}
	cout << a << "\n";



}