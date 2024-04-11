/*input
LoCk
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(ll n)
{
	while (n > 0)
	{
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string a;
	cin >> a;
	bool blogai = true;
	for (int i = 1; i < a.size(); i++)
		if (islower(a[i]))
			blogai = false;
	if (blogai)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (isupper(a[i]))
				a[i] = tolower(a[i]);
			else
				a[i] = toupper(a[i]);
		}
	}
	cout << a << "\n";
}