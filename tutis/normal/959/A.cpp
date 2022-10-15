/*input
2
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
	if (n == 1)
	{
		cout << "Ehab" << endl;
		return 0;
	}
	if (n % 2 == 1)
	{
		cout << "Ehab" << endl;
		return 0;
	}
	if (n % 2 == 0)
	{
		cout << "Mahmoud" << endl;
		return 0;
	}
}