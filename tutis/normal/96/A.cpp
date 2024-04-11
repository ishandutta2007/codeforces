/*input
1000000001
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		bool blogai = true;
		for (int c = 0; c < 7; c++)
		{
			if (i + c >= a.size() || a[i + c] == '0')
				blogai = false;
		}
		if (blogai)
		{
			cout << "YES\n";
			return 0;
		}
		blogai = true;
		for (int c = 0; c < 7; c++)
		{
			if (i + c >= a.size() || a[i + c] == '1')
				blogai = false;
		}
		if (blogai)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}