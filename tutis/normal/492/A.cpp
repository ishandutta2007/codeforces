/*input
25
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int reik = 0;
	int i = 1;
	int h = 0;
	while (n > 0)
	{
		reik += i;
		i++;
		if (n >= reik)
		{
			h++;
			n -= reik;
		}
		else
			break;
	}
	cout << h << "\n";

}